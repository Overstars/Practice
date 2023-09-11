#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 5, maxm = 2e5 + 5;
const int INF = 0x7f7f7f7f;
struct MCMF
{
	int n, m, s, t, dis[maxn];
	int tot, lnk[maxn], cur[maxn], ter[maxm], nxt[maxm], cap[maxm], cost[maxm];
	bool vis[maxn];
	void init(int n)
	{
		this->n=n;
		tot=1;
		memset(nxt,0,sizeof(nxt));
		memset(lnk,0,sizeof(lnk));
	}
	void add(int u, int v, int w, int c)
	{
		ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
	}
	void addEdge(int u, int v, int w, int c)
	{
		add(u, v, w, c);
		add(v, u, 0, -c);
	}
	bool spfa(int s, int t)
	{
		memset(dis, 0x7f, sizeof(dis));
		memcpy(cur, lnk, sizeof(lnk));
		std::queue<int> q;
		q.push(s), dis[s] = 0, vis[s] = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop(), vis[u] = false;
			for (int i = lnk[u]; i; i = nxt[i])
			{
				int v = ter[i];
				if (cap[i] && dis[v] > dis[u] + cost[i]) {
					dis[v] = dis[u] + cost[i];
					if (!vis[v]) q.push(v), vis[v] = true;
				}
			}
		}
		return dis[t] < INF;
	}
	int dfs(int u, int t, int flow)
	{
		if (u == t) return flow;
		vis[u] = true;
		int ans = 0;
		for (int &i = cur[u]; i; i = nxt[i])
		{
			int v = ter[i];
			if (cap[i] && !vis[v] && dis[v] == dis[u] + cost[i]) {
				int x = dfs(v, t, std::min(cap[i], flow));
				if (!x) continue;
				cap[i] -= x, cap[i ^ 1] += x, flow -= x, ans += x;
				if (!flow) break;
			}
		}
		vis[u] = false;
		return ans;
	}
	std::pair<int, int> dinic(int s, int t)
	{
		int maxFlow = 0, minCost = 0;
		while (spfa(s, t))
		{
			int x;
			while ((x = dfs(s, t, INF)))
				maxFlow += x, minCost += x * dis[t];
		}
		return std::make_pair(maxFlow, minCost);
	}
} mm;
//#define debug
int main()
{
	#ifdef debug
	freopen("P3381.in","r",stdin);
	#endif // debug
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	mm.init(n);
	for(int i=1;i<=m;i++)
	{
		int u,v,w,f;
		cin>>u>>v>>w>>f;
		mm.addEdge(u,v,w,f);
	}
	pair<int,int> ans=mm.dinic(s,t);
	cout<<ans.first<<' '<<ans.second<<endl;
	return 0;
}

