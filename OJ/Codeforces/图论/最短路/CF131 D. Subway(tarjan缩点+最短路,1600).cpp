//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int dist[maxn];//到这个点的最近队员的
void dijkstra(int n,int start)//传入总数及起点
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
		for(auto &x:E[u])
		{
			int v=x.v,cost=x.cost;
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
int vis[maxn],tar,stk[maxn],top=0;
vector<int>circle,G[maxn];
void dfs(int x,int fa)
{
	if(tar)
		return;
	if(vis[x])
	{
		tar=x;
		while(stk[top]!=x)
		{
			circle.push_back(stk[top--]);
//			printf("%d has been poped.\n",stk.top());
		}
		circle.push_back(x);
//		stk.pop();
		return;
	}
	vis[x]=1;
	stk[++top]=x;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
	}
	top--;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		adde(u,v,1);
	}
	dfs(1,1);
	int s=n+1;
	for(auto &x:circle)
		adde(s,x,0);
	dijkstra(n+1,s);
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
	return 0;
}

