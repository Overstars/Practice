//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=120,inf=0x3f3f3f3f,mod=1000000007;
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
struct edge
{
	int u,v,id;
};
vector<edge>rec;
vector<int>G[maxn],g[maxn];
bool vis[maxn];
int st,ed,dp[maxn][2],into[maxn];//奇数的数量,偶数的数量
void dfs(int x)
{
	vis[x]=1;
	for(auto &v:G[x])
	{
		if(x==st&&v==ed)
			continue;
		g[x].push_back(v);
		printf("add(%d->%d)\n",x,v);
		into[v]++;
		if(vis[v])
			continue;
		dfs(v);
	}
}
int topo(int st,int ed)
{
	queue<int>q;
	dp[st][0]=1;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		printf("x = %d\n",x);
		printf("dp[%d] = %d\n",x,dp[x][0]);
		q.pop();
		for(auto &v:g[x])
		{
			dp[v][0]+=dp[x][1];
			dp[v][1]+=dp[x][0];
			if(--into[v]==0)
				q.push(v);
		}
	}
	printf("dp[%d] = %d\n",st,dp[ed][0]);
	return dp[ed][0];
}
bool sol(int n,int m)
{
	vector<int> cnt(m+10,0),now;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
//		g[i].clear();
	}
	for(auto &e:rec)
	{
		G[e.u].push_back(e.v);
		G[e.v].push_back(e.u);
		now.push_back(e.id);
	}
	for(auto &e:rec)
	{
		st=e.u;
		ed=e.v;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			g[i].clear();
		dfs(e.u);//建图
		topo(st,ed);
		printf("%d->%d = %d\n",st,ed,dp[e.v][0]);
		cnt[e.id]+=dp[e.v][0];
	}
	sort(now.begin(),now.end(),[cnt](const int &x,const int &y){
			return cnt[x]<cnt[y];//多的在后
		});
	int siz=now.size();
	if(cnt[now[siz-1]]==0)
		return 0;
	printf("%d has been del.\n",now[siz-1]);
	rec.pop_back();
	return true;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		rec.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			rec.push_back(edge{u,v,i});
		}
		int ans=0;
		while(sol(n,m))
			ans++;
		cout<<m-ans<<endl;
	}
	return 0;
}
/*
 * 2021-04-28-15.02.35
*/

