//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e4+10,inf=0x3f3f3f3f,mod=1000000007;
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
struct MCMF {
	using type = ll;
	struct Edge {
		ll v, cap;
		type cost;
		ll rev;
	};
	const type INF=0x3f3f3f3f3f3f3f3f;
	ll flow, s, t, n;//跑完的最大流
	type cost;//跑完最大流下的最小费用
	type dist[maxn], H[maxn];//H为节点势函数
	ll pv[maxn], pe[maxn];//前驱结点和对应边
	std::vector<Edge> G[maxn];//因为要记录前驱,不能用前向星
	void init(int n){
		this->n = n;
		for (int i = 0; i <= n; ++i) G[i].clear();
	}
	void addEdge(int u, int v, int cap, type cost){//dijk费用流中两节点间流向单向
		G[u].push_back({v,cap,cost,G[v].size()});
		G[v].push_back({u,0,-cost,G[u].size()-1});
	}
	bool dijkstra()//这里是单路增广
	{//复杂度相对SPFA稳定
		std::priority_queue<pair<type,ll>, std::vector<pair<type,ll>>, std::greater<pair<type,ll>> > q;
		std::fill(dist, dist + n + 1, INF);
		dist[s] = 0; q.push({ 0, s });
		while (!q.empty())
		{//到x距离即为到x的单位花费之和
			pair<type,ll> x = q.top(); q.pop();
			ll& u = x.second;
			if (dist[u] < x.first) continue;//不能优化距离
			for (int i = 0; i < G[u].size(); ++i)
			{
				Edge& e = G[u][i];//当前边
				ll& v = e.v;
				pair<type,ll> y(dist[u] + e.cost + H[u] - H[v], v);
				if (e.cap > 0 && dist[v] > y.first)
				{
					dist[v] = y.first;
					pv[v] = u,pe[v] = i;//前驱点与前驱边
					q.push(y);
				}
			}
		}
		if (dist[t] == INF)//无法增广
			return false;
		for (int i = 0; i <= n; ++i)//更新每轮的势函数
			H[i] += dist[i];
		ll f = INF;
		for (int v = t; v != s; v = pv[v])//沿增广路回到起点
			f = std::min(f, G[pv[v]][pe[v]].cap);
		flow += f;//每次增广一条路径,这条路径增广量就是新增的流量
		cost += f * H[t];//h[t]-h[s]即为s到t的路径长
		for (int v = t; v != s; v = pv[v])
		{//更新增广路容量信息
			Edge& e = G[pv[v]][pe[v]];
			e.cap -= f;
			G[v][e.rev].cap += f;
		}
		return true;
	}
	ll solve(int s, int t)
	{
		this->s = s, this->t = t;
		flow = cost = 0;
		std::fill(H, H + n + 1, 0);//初始网络为0非负,势函数也为0
		while (dijkstra());//每次选择最小费用增广路径一定是当前残留图的最小增广路径
		return flow;
	}
} mm;
double p[maxn],q[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,a,b,s,t;
	cin>>n>>a>>b;
	s=n+2+1,t=s+1;
	mm.init(t+10);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i];
	for(int i=1;i<=n;i++)
	{
		mm.addEdge(s,i,1,0);
		mm.addEdge(s,i,1,p[i]*q[i]);
		mm.addEdge(i,n+1,1,-p[i]);
		mm.addEdge(i,n+2,1,-q[i]);
	}
	mm.addEdge(n+1,t,a,0);
	mm.addEdge(n+2,t,b,0);
	cerr<<mm.solve(s,t)<<endl;
	cout<<-mm.cost<<endl;
	return 0;
}
/*
 * 2021-04-30-23.27.38
*/

