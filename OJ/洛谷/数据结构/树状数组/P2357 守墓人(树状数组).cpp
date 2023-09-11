#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l, int r, ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:1~k的区间和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
int a[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,f,ope,l,r,k;
	cin>>n>>f;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bit.build(a,n);
	while(f--)
	{
		cin>>ope;
		if(ope==1)
		{
			cin>>l>>r>>k;
			bit.radd(l,r,k);
		}
		else if(ope==2)
		{
			cin>>k;
			bit.radd(1,1,k);
		}
		else if(ope==3)
		{
			cin>>k;
			bit.radd(1,1,-k);
		}
		else if(ope==4)
		{
			cin>>l>>r;
			cout<<bit.query(r)-bit.query(l-1)<<endl;
		}
		else
			cout<<bit.query(1)<<endl;
//		printf("*****\n");
//		for(int i=1;i<=n;i++)
//		{
//			printf("%lld ",bit.query(i)-bit.query(i-1));
//		}
//		printf("\n");
	}
	return 0;
}


