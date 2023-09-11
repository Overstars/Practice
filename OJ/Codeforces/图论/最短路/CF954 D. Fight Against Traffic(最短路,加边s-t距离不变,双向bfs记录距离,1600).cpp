//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
bool vis[maxn][maxn];
const int MAXN=1050;
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
vector<Edge>E[MAXN];//使用前必须清空0~n
bool vis2[MAXN];
int dis1[MAXN],dis2[MAXN];//到这个点的最近队员的
void Dijkstra(int n,int start,int *dist)//传入总数及起点
{//点的编号从 1 开始
	memset(vis2,false,sizeof(vis2));
	for(int i=1;i<=n;i++)
		dist[i]=inf;
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	while(!que.empty())
	{
		qnode now=que.top();
		que.pop();
		int u=now.v;
		if(vis2[u])
			continue;
		vis2[u]=true;
		for(int i=0;i<E[u].size();i++)
		{
			int v=E[u][i].v;
			int cost=E[u][i].cost;
			if(!vis2[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void addedge(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	memset(path,inf,sizeof(path));
	int n,m,s,t,u,v,w,ans=0;
	read(n,m,s,t);
	for(int i=1;i<=m;i++)
	{
		read(u,v);
		vis[u][v]=vis[v][u]=1;
		E[u].push_back({v,1});
		E[v].push_back({u,1});
	}
	Dijkstra(n,s,dis1);
	Dijkstra(n,t,dis2);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!vis[i][j]&&min(dis1[i]+dis2[j],dis1[j]+dis2[i])+1>=dis1[t])
				ans++;
	printf("%d\n",ans);
	return 0;
}


