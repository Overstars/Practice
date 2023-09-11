//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
struct MCMF
{
	struct Edge
	{
		int from, to, cap, flow;
		ll cost;
		Edge(int u, int v, int c, int f, ll w)
			: from(u), to(v), cap(c), flow(f), cost(w) {}
	};
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	ll inq[maxn]; //是否在队列中
	ll d[maxn]; //bellmanford
	ll p[maxn]; //上一条弧
	ll a[maxn]; //可改进量
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap, ll cost)
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
			d[i] = INF;
		memset(inq, 0, sizeof(inq));
		d[s] = 0;
		inq[s] = 1;
		p[s] = 0;
		a[s] = INF;
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
					a[e.to] = min(a[u],(ll) e.cap - e.flow);
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
		if (d[t] == INF)
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
ll c[55][4];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&c[i][j]);
		int mid=m+n+1,ed=m+n+2;
		mm.init(ed+100);
		for(int j=1;j<=n;j++)
		{
			mm.AddEdge(mid,j,1,0);
			for(int k=1;k<=m;k++)
				mm.AddEdge(j,n+k,1,c[j][1]*k*k+c[j][2]*k+c[j][3]);
		}
		for(int j=1;j<=m;j++)
			mm.AddEdge(n+j,ed,1,0);
		ll ans=0;
		mm.MincostMaxflow(mid,ed,ans);
//		for(int i=1;i<=n;i++)
//		{
//			int st=m+n+2+i;
//			mm.AddEdge(st,mid,i,0);
//			cout<<"flow="<<mm.MincostMaxflow(st,ed,ans)<<endl;
//			printf("%lld ",ans);
//		}
	}
	return 0;
}


