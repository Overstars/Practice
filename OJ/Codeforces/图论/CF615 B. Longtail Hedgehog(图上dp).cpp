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
vector<int>G[maxn];
int deg[maxn],rec[maxn],dist[maxn],root;//root为树上直径的一端
bool vis[maxn];
void bfs(int s,int n)
{
	memset(vis,0,sizeof(vis));
	queue<int>q;
//	for(int i=1;i<=n;i++)
//		if()
	while(!q.empty())
	{
		int x=q.front();
		for(auto &v:G[x])
		{
			if(!vis[v])
			{
				dist[v]=dist[x]+1;
				if(dist[v]>dist[root])
					root=v;
				rec[v]=max(rec[v],dist[v]);
			}
		}
	}
}
int dp[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	ll ans=0;
	for(int v=1;v<=n;v++)
	{
		dp[v]=1;//序号严格递增
		for(auto &u:G[v])
			if(u<v)
				dp[v]=max(dp[v],dp[u]+1);
		ans=max(ans,(ll)dp[v]*G[v].size());
	}
	cout<<ans<<endl;
	return 0;
}


