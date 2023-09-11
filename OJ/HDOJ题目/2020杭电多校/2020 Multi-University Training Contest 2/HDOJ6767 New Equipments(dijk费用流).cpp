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
//const int maxm = 100010;
struct MCMF
{//复杂度O(n^2f),f为最大流量(我觉得是O(fmlogm)?
	struct Edge {
		ll v, cap, cost, rev;
	};
	const ll INF=0x3f3f3f3f3f3f3f3f;
	ll flow, cost, s, t, n;
	ll dist[maxn], H[maxn], pv[maxn], pe[maxn];
	std::vector<Edge> G[maxn];
	void init(int n){//一定要初始化
		this->n = n;
		for (int i = 0; i <= n; ++i) G[i].clear();
	}
	void addEdge(int u, int v, int cap, ll cost){//dijk费用流中两节点间流向单向
		G[u].push_back({v,cap,cost,G[v].size()});
		G[v].push_back({u,0,-cost,G[u].size()-1});
	}
	bool dijkstra()
	{//将花费作为距离
		std::priority_queue<pair<ll,ll>, std::vector<pair<ll,ll>>, std::greater<pair<ll,ll>> > q;
		std::fill(dist, dist + n + 1, INF);
		dist[s] = 0; q.push({ 0, s });
		while (!q.empty())
		{
			pair<ll,ll> x = q.top(); q.pop();
			ll& u = x.second;
			if (dist[u] < x.first) continue;//不能优化距离
			for (int i = 0; i < G[u].size(); ++i)
			{
				Edge& e = G[u][i];
				ll& v = e.v;
				pair<ll,ll> y(dist[u] + e.cost + H[u] - H[v], v);
				if (e.cap > 0 && dist[v] > y.first)
				{
					dist[v] = y.first;
					pe[v] = i, pv[v] = u;
					q.push(y);
				}
			}
		}
		if (dist[t] == INF)//无增广路
			return false;
		for (int i = 0; i <= n; ++i)
			H[i] += dist[i];
		ll f = INF;
		for (int v = t; v != s; v = pv[v])
			f = std::min(f, G[pv[v]][pe[v]].cap);//记录可增广量
		flow += f;//每次增广一条路径,这条路径增广量就是新增的流量
		cost += f * H[t];//且是此时总流量对应的最小花费
		for (int v = t; v != s; v = pv[v])
		{
			Edge& e = G[pv[v]][pe[v]];
			e.cap -= f;//增广路径上边容量减少
			G[v][e.rev].cap += f;//反向边容量增加
		}
		return true;
	}
	ll solve(int s, int t)
	{
		this->s = s, this->t = t;
		flow = cost = 0;
		std::fill(H, H + n + 1, 0);
		while (dijkstra());//每次选择最小费用增广路径一定是当前残留图的最小增广路径
		return flow;
	}
} mm;
ll a[55],b[55],c[55];
inline ll cost(int ind,int x)
{
	return (ll)a[ind]*x*x+b[ind]*x+c[ind];
}
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
		for(int i=1;i<=n;i++)//a>0,有最小值>0
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		set<int>rec;//形成一个二次函数,记录最优的那些点,左右各取n个,因为可能会被占用
		for(int i=1;i<=n;i++)
		{
			int now=min(m,max(1,(int)(-b[i]/(2*a[i])))),cnt=1;
			rec.insert(now);
//			int l=max(1,now-n),r=min(m,now+n+1);
//			for(;l<=r;l++)//左右各延伸n个会TLE
//				rec.insert(l);
			int l=now-1,r=now+1;
            while(cnt<=n+2)
            {
                if(1<=l&&r<=m)
                {
                    if(cost(i,l)<=cost(i,r))
                        rec.insert(l--);
                    else
                        rec.insert(r++);
                }
                else if(r<=m)
                    rec.insert(r++);
                else if(l>=1)
                    rec.insert(l--);
				else
					break;
                cnt++;
            }
		}
		vector<int>v;
		for(auto &x:rec)
			v.push_back(x);
		int st=n+v.size()+1,ed=n+v.size()+2;
		mm.init(ed+10);
		for(int i=1;i<=n;i++)
		{
			mm.addEdge(st,i,1,0);
			for(int j=0;j<v.size();j++)
			{
				mm.addEdge(i,n+j+1,1,cost(i,v[j]));
			}
		}
		for(int j=0;j<v.size();j++)
			mm.addEdge(n+j+1,ed,1,0);
		mm.s=st,mm.t=ed;
		mm.flow=mm.cost=0;
		std::fill(mm.H, mm.H +ed+ 10, 0);
		for(int i=1;i<=n;i++)
		{
			mm.dijkstra();
			printf("%lld%c",mm.cost,(i==n)?'\n':' ');
		}
	}
	return 0;
}

