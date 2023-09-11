//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
	ll w;
	edge(int u,int v,ll w,int i):
		u(u),v(v),w(w),id(i){}
};
struct qnode{
	int v,c,id;
	qnode(int _v=0,int _c=0,int id=0):v(_v),c(_c),id(id){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int v,cost,id;
	Edge(int _v=0,int _cost=0,int _id=0):v(_v),cost(_cost),id(_id){}
};
vector<Edge>E[maxn];//使用前必须清空0~n
vector<edge>rec;
ll dist[maxn],pree[maxn];//到这个点的最近队员的
void dijkstra(int n,int start)//传入总数及起点
{//点的编号从 1 开始
	vector<bool>visited(n+10,false);
	for(int i=1;i<=n;i++)
		dist[i]=INF;
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
			ll v=e.v,cost=e.cost;
//			cout<<u<<"->"<<v<<endl;
			if(!visited[v]&&dist[v]>dist[u]+cost){//
				pree[v]=e.id;
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
			else if(dist[v]==dist[u]+cost&&cost<rec[pree[v]-1].w)
			{//进入到v的边优先选择边权最小的,其他的入边即被舍弃
				pree[v]=e.id;
			}
		}
	}
}
void adde(int u,int v,int w,int id)
{
	E[u].push_back(Edge(v,w,id));
	E[v].push_back(Edge(u,w,id));
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,st,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		ll w;
		cin>>u>>v>>w;
		rec.push_back(edge(u,v,w,i));
		adde(u,v,w,i);
	}
	cin>>st;
	dijkstra(n,st);
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(i!=st)
			ans+=rec[pree[i]-1].w;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(i!=st)
			cout<<pree[i]<<' ';
	return 0;
}
/*
 *新概念
 *最短路径树SPT:单源最短路
 *以root为源点跑单源最短路,有效边一定构成以root为根的树
 *且root通过树上边到树上点一定为原最短路距离
 *普通的最短路径树应该是跑最短路时随便记录前置点
 *先跑一遍dijk,求出dist数组
 */

