#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn = 10005;
int n,p,q;//n辆探测车
bool flag=0;
struct MCMF
{
	struct Edge
	{
		int from, to, cap, flow, cost;
		Edge(int u, int v, int c, int f, int w)
			: from(u), to(v), cap(c), flow(f), cost(w) {}
	};
	int n, m;
	vector<Edge> edges;//边表。edge[e]和edge[e^1]互为反向弧
	vector<int> G[maxn];//邻接表，G[i][j]表示节点i的第j条边在edges数组中的序号
	int inq[maxn]; //是否在队列中
	int dist[maxn]; //bellmanford
	int prevv[maxn]; //上一条弧
	int a[maxn]; //可改进量
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap, int cost)
	{
		edges.emplace_back(Edge(from, to, cap, 0, cost));
		edges.emplace_back(Edge(to, from, 0, 0, -cost));
//		edges.push_back(Edge(from, to, cap, 0, cost));
//		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BellmanFord(int s, int t, int& flow, ll& cost)
	{
		for (int i = 0; i < n; i++)
			dist[i] = inf;
		memset(inq, 0, sizeof(inq));
		dist[s] = 0;
		inq[s] = 1;
		prevv[s] = 0;
		a[s] = inf;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if (e.cap > e.flow && dist[e.to] > dist[u] + e.cost)
				{
					dist[e.to] = dist[u] + e.cost;
					prevv[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
//		cout<<"DEBUG:BellmanFord\n";
//		cout<<"flow"<<flow<<",cost="<<cost<<endl;
		if (dist[t] == inf)
			return false; // 当没有可增广的路时退出
		flow += a[t];
		cost += (ll)dist[t] * (ll)a[t];
		for (int u = t; u != s; u = edges[prevv[u]].from)
		{
			edges[prevv[u]].flow += a[t];
			edges[prevv[u] ^ 1].flow -= a[t];
		}
		return true;
	}
	int MincostMaxflow(int s, int t, ll& cost)
	{
		int flow = 0;
		cost = 0;
		while(BellmanFord(s, t, flow, cost));
		return flow;
	}
} mm;
//#define debug
struct edge
{
	int u,v,c,w;
} e[5005];
int main()
{
	#ifdef debug
	freopen("P3356.in","r",stdin);
	#endif // debug
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	mm.init(n+10);
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].c>>e[i].w;
		mm.AddEdge(e[i].u,e[i].v,e[i].c,0);
	}
	ll cost;
	cout<<mm.MincostMaxflow(1,n,cost)<<' ';
	for(int i=1;i<=m;i++)
		mm.AddEdge(e[i].u,e[i].v,inf,e[i].w);
	int s=0;
	mm.AddEdge(s,1,k,0);
	mm.MincostMaxflow(s,n,cost);
	cout<<cost<<endl;
	return 0;
}

