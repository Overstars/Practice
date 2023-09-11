//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct qnode{
	int v;
	ll c;
	qnode(int _v=0,ll _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int u,v;
	ll cost;
	Edge(int _u=0,int _v=0,ll _cost=0):u(_u),v(_v),cost(_cost){}
};
vector<Edge>E[maxn];//使用前必须清空0~n
ll dist[maxn];//到这个点的最近队员的
bool mp[maxn];//标记是否为关键点
ll dijkstra(int n,int start,int ed)//传入总数及起点
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
		if(u==ed)
			return dist[u];
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
	return dist[ed];
}
void adde(int u,int v,ll w)
{
	E[u].push_back(Edge(u,v,w));
//	E[v].push_back(Edge(u,w));
}
signed main(signed argc, char const *argv[])
{
//	#define DEBUG
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P5304.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,k,u,v,w;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		int st=n+1,ed=n+2;
		for(int i=1;i<=n+80;i++)
			E[i].clear();
		vector<int> mk(k);
//		vector<Edge>rec;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			if(u==v)
			{
//				rec.push_back(Edge(u,v,w));
				continue;
			}
//			rec.push_back(Edge(u,v,w));
			adde(u,v,w);//第二层图
		}
		for(auto &i:mk)
			cin>>i;
		ll ans=INF;
		for(int i=0;i<=17;i++)
		{
//			for(int j=1;j<=ed;j++)
//				E[j].clear();
//			for(auto &e:rec)
//				adde(e.u,e.v,e.cost);
			st=n+i*4+1,ed=st+1;
			for(auto &x:mk)
			{
				if((x>>i)&1)
					adde(st,x,0);
				else
					adde(x,ed,0);
			}
			ans=min(ans,dijkstra(ed,st,ed));
//			for(int j=1;j<=ed;j++)
//				E[j].clear();
//			for(auto &e:rec)
//				adde(e.u,e.v,e.cost);
			st=ed+1,ed=st+1;
			for(auto &x:mk)
			{
				if(!((x>>i)&1))
					adde(st,x,0);
				else
					adde(x,ed,0);
			}
			ans=min(ans,dijkstra(ed,st,ed));
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-05-11-21.48.47
 * 分层图会比答案跑出来的小,第一层图里的u'经过一些边可能到第二层的u
 * 因为分层图某一个节点会跑回到自己,这种情况是不合法的
*/

