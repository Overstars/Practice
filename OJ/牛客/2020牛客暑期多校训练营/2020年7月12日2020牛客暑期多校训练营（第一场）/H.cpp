//#pragma comment(linker, "/STACK:102400000,102400000")
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
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
map<int,int>mp;
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
		mp[d[t]*a[t]]+=a[t];
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
int cost[maxn];
signed main()
{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,u,v,w,c,q;
	while(~scanf("%lld%lld",&n,&m))
	{
		mm.init(n+10);
		mp.clear();
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&u,&v,&cost[i]);
//			cin>>u>>v>>cost[i];
			mm.AddEdge(u,v,1,cost[i]);
		}
		ll tot=0,mf=mm.MincostMaxflow(1,n,tot);
		scanf("%lld",&q);
//		cin>>q;
		while(q--)
		{
			scanf("%lld%lld",&u,&v);
//			cin>>u>>v;
			if(mf*u<v)
				puts("NaN");
			else{//容量乘以u,跑v的流量
				ll now=0,x=0,y=v;
				for(auto &i:mp)
				{
//					printf("%d,%d\n",i.first,i.second);
					if(v>i.second*u)
					{
						v-=i.second*u;
						x+=i.first*u;
					}
					else{
						x+=i.first*v/i.second;
						break;
					}
				}
				ll g=gcd(x,y);
				printf("%lld/%lld\n",x/g,y/g);
			}
		}
	}
	return 0;
}


