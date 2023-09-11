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
struct MCMF
{
	struct Edge
	{
		int from, to, cap, flow, cost;
		Edge(int u, int v, int c, int f, int w)
			: from(u), to(v), cap(c), flow(f), cost(w) {}
	};
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn]; //是否在队列中
	int d[maxn]; //bellmanford
	int p[maxn]; //上一条弧
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
			d[i] = inf;
		memset(inq, 0, sizeof(inq));
		d[s] = 0;
		inq[s] = 1;
		p[s] = 0;
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
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
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
		if (d[t] == inf)
			return false; // 当没有可增广的路时退出
		flow += a[t];
		cost += (ll)d[t] * (ll)a[t];
		for (int u = t; u != s; u = edges[p[u]].from)
		{
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
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
int r[maxn];
int main()
{
	#ifdef debug
	freopen("P3381.in","r",stdin);
	#endif // debug
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int N,p,m,f,n,s;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>r[i];
	cin>>p>>m>>f>>n>>s;
	int st=0,tar=2*N+1;
	mm.init(tar+10);
	for(int i=1;i<=N;i++)
	{
		mm.AddEdge(st,i,r[i],0);
		mm.AddEdge(N+i,tar,r[i],0);
		mm.AddEdge(st,N+i,inf,p);//添加买新毛巾的边
		if(i<N)//毛巾可以留到下一天晚上洗
			mm.AddEdge(i,i+1,inf,0);//从第i天晚上连到第i+1天晚上
		if(i+m<=N)//快洗
			mm.AddEdge(i,N+i+m,inf,f);//第i天晚上开始洗,第i+m天早上洗完
		if(i+n<=N)//慢洗
			mm.AddEdge(i,N+i+n,inf,s);
	}
	ll cost;
	mm.MincostMaxflow(st,tar,cost);
	cout<<cost<<endl;
	return 0;
}
