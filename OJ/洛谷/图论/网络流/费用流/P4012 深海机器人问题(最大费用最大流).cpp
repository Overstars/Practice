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
//		edges.emplace_back(Edge(from, to, cap, 0, cost));
//		edges.emplace_back(Edge(to, from, 0, 0, -cost));
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
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
//#define DEBUG
int cost[105][105],mc[105],nc[105];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef _DEBUG
		freopen("P4012.in", "r", stdin);
	//	freopen("P4012.out", "w", stdout);
	#endif
	int a,b,p,q,s,t,cnt=0;//每条网格的边有权值,设容量为1,花费为-cost
	cin>>a>>b>>p>>q;//出发点数,目的地点数
	ll ans;//节点编号横着编号
	s=(p+1)*(q+1)+1,t=s+1;
	mm.init(t+10);
	for(int i=0;i<=p;i++)//网格横边
		for(int j=1;j<=q;j++)//到(j,i)的横边
		{
			int v=i*(q+1)+j;
			int u=v-1,cos;
			cin>>cos;
			mm.AddEdge(u,v,1,-cos);
			mm.AddEdge(u,v,inf,0);//经过
		}
	for(int i=0;i<=q;i++)
		for(int j=1;j<=p;j++)//到(i,j)网格竖边
		{
			int v=j*(q+1)+i;
			int u=v-q-1,cos;
			cin>>cos;
			mm.AddEdge(u,v,1,-cos);
			mm.AddEdge(u,v,inf,0);//经过
		}
	for(int i=1;i<=a;i++)
	{
		int k,x,y;
		cin>>k>>y>>x;
		int v=y*(q+1)+x;
		mm.AddEdge(s,v,k,0);
	}
	for(int i=1;i<=b;i++)
	{
		int r,x,y;
		cin>>r>>y>>x;
		int u=y*(q+1)+x;
		mm.AddEdge(u,t,r,0);
	}
	mm.MincostMaxflow(s,t,ans);
	cout<<-ans<<endl;
	return 0;
}
