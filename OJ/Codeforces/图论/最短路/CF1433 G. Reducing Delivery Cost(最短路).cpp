//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
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
struct qnode{
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];//使用前必须清空0~n
int dist[maxn][maxn];//到这个点的最近队员的
void dijkstra(int n,int start,int dist[])//传入总数及起点
{//点的编号从 1 开始
	vector<bool>visited(n+10,false);
	for(int i=1;i<=n;i++)
		dist[i]=inf;
	priority_queue<qnode>que;
	dist[start]=0;
	que.push(qnode(start,0));
	while(!que.empty())
	{
		qnode now=que.top();
		que.pop();
		int u=now.v;
		if(visited[u])
			continue;
		visited[u]=true;
		for(auto &e:E[u])
		{
			int v=e.v,cost=e.cost;
			if(!visited[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void adde(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
	E[v].push_back(Edge(u,w));
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,u,v,w;
	vector<pii>rec,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		adde(u,v,w);
		rec.push_back(pii(u,v));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>u>>v;
		c.push_back(pii(u,v));
	}
	for(int i=1;i<=n;i++)
		dijkstra(n,i,dist[i]);
	ll ans=inf;
	#define ff first
	#define ss second
	for(auto &e:rec)
	{//枚举所有边
		ll now=0;
		int u=e.ff,v=e.ss;
		for(auto &x:c)
		{
			int a=x.ff,b=x.ss;
			now+=min({dist[a][u]+dist[v][b],dist[a][v]+dist[u][b],dist[a][b]});
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *若<u,v>在最短路上,贡献减少w
 *若不在,删除后在最短路上
 *min(d(a,u)+d(v,b),a(a,v)+d(u,b))
*/

