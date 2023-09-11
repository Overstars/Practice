#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
	ll c[maxn];
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{//维护差分数组时,前缀和表示原点的值
		this->n=n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{
		while(k<=n)
		{
			this->c[k]+=val;
			k+=lowbit(k);
		}
	}
	void range_update(int l, int r, ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的，但是多更新了，所以要每个点都-val；
	}
	ll query(int k)//查询:1~k的区间和
	{
		ll sum=0;
		while(k)
		{
			sum+=this->c[k];
			k-=lowbit(k);
		}
		return sum;
	}
} bit;
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ope,l,r;
	cin>>n>>m;
	bit.n=n;
	while(m--)
	{
		cin>>ope;
		if(ope==1)
		{
			cin>>l>>r;
			bit.range_update(l,r,1);
		}
		else{
			cin>>l;
			cout<<((bit.query(l))&1)<<endl;
//			cout<<((bit.query(l)-query(l-1))&1)<<endl;
		}
//		for(int i=1;i<=n;i++)
//			printf("%lld ",bit.query(i));
//		printf("\n");
	}
	return 0;
}


