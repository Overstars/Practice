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
	void build(int n)//a是原数组,n是元素个数
	{
		this->n=n;
		for(int i=0;i<=n;i++)
			c[i]=sum[i]=0;
//		memset(c,0,sizeof(c));
//		memset(sum,0,sizeof(sum));
//		for(int i=1;i<=n;i++)
//			add(i,a[i]-a[i-1]);//构建差分c数组
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
}bit;
struct line
{
	int l,r,id;
	bool operator <(const line &b)const{
		if(l==b.l)
			return r<b.r;
		return l<b.l;
//		if(r==b.r)
//			return l<b.l;
//		return r<b.r;
	}
};
int fa[maxn],siz[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
	{
		fa[b]=a;
		siz[a]+=siz[b];
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
	}
	return 1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			fa[i]=i,siz[i]=1;
		vector<line>rec(n);
		vector<int>ans(n);
		int lim=0;
		for(int i=0;i<n;i++)
		{
			cin>>rec[i].l>>rec[i].r;
			rec[i].id=i;
			lim=max(lim,rec[i].r);
		}
		sort(rec.begin(),rec.end());
//		bit.build(lim);
		bool ok=1;
		int last=0,flag=0,who=0;
		for(auto &i:rec)
		{
			if(i.l>last)
			{
				flag=1;
				last=i.r;
				who=i.id+1;
				continue;
			}
			last=max(last,i.r);
			Merge(i.id+1,who);
		}
		if(siz[findfa(1)]==n)
			cout<<-1<<endl;
		else{
			for(int i=0;i<n;i++)
				cout<<(findfa(i+1)==1?1:2)<<' ';
			cout<<endl;
		}
	}
	return 0;
}
/*
999
3
1 4
2 5
3 6
3
1 6
2 5
3 4
ans=-1,-1
*/
/*
 * 2021-05-12-15.22.36
*/

