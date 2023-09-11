//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
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
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
int pos[maxn],a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q;
	cin>>n>>q;
	bit.n=max(n,q);
	bool ok=1,isz=0,isq=0;
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==q)
			isq=1;
		if(a[i]==0)
			isz=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
			isz=0,tmp=a[i];
		else if(!isq)
			a[i]=tmp;
		else
			a[i]=q,isq=0;
	}
	tmp=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i])
			tmp=a[i];
		else
			a[i]=tmp;
	}
	if(isz)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<q<<' ';
		return cout<<endl,0;
	}
	map<int,int> pre,cnt;
	for(int i=1;i<=n;i++)
	{
		bit.radd(a[i],a[i],1);
		if(pre[a[i]]==0)
		{
			cnt[a[i]]=bit.query(a[i]-1);
			pre[a[i]]=i;
		}
		else{
			int now=bit.query(a[i]-1);
			if(now!=cnt[a[i]])
			{
				ok=0;
				break;
			}
			pre[a[i]]=i;
		}
	}
	if(!ok)
		return cout<<"NO"<<endl,0;
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
/*
5 3
1 2 1 0 1
*/
/*
 * 2021-05-07-15.05.08
*/

