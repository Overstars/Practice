#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const ll maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll qmod(ll a,ll b)  //快速幂
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int fa[maxn];
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
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
int a[maxn],depth[maxn],val[maxn][2],cnt0,cnt1;
struct edge
{
	ll u,v,w;
};
vector<int>G[maxn];
void dfs(int x,int fa)
{//val[x][0]表示x子树上0的个数
	val[x][a[x]]++;
	depth[x]=depth[fa]+1;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		val[x][0]+=val[v][0];
		val[x][1]+=val[v][1];
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cnt0=cnt1=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
				cnt1++;
			else
				cnt0++;
			fa[i]=i;
			val[i][0]=val[i][1]=0;
			G[i].clear();
		}
		ll u,v,w,now=0,ok=0;
		vector<edge>E;
		for(ll i=1;i<=m;i++)
		{
			cin>>u>>v;
			if(!ok&&Merge(u,v))
			{
				E.push_back({u,v,i});//2^i
				if(++now==n-1)
					ok=1;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		depth[1]=0;
		dfs(1,1);
		ll ans=0;
		for(auto &e:E)
		{
			int u=e.u,v=e.v;
			if(depth[u]>depth[v])
				swap(u,v);
			ans=(ans+((cnt0-val[v][0])*val[v][1]%mod)*qmod(2,e.w)%mod)%mod;
			ans=(ans+((cnt1-val[v][1])*val[v][0]%mod)*qmod(2,e.w)%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}


