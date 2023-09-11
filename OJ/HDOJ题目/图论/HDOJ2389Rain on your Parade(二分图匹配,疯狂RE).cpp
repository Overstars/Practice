//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=6003,inf=0x3f3f3f3f,mod=1000000007;
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
struct Dinic
{//复杂度O(n^2m)
	struct Edge
	{
		short from, to, cap, flow;
		Edge(short u, short v, short c, short f):
			from(u), to(v), cap(c), flow(f) {}
	};
	int n, m, s, t; //结点数,边数(包括反向弧),源点编号和汇点编号
	vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
	vector<short> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
	bool vis[maxn]; //BFS使用
	short d[maxn]; //从起点到i的距离
	short cur[maxn]; //当前弧下标
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap)
	{
//		edges.emplace_back(Edge(from, to, cap, 0));//魔改蔡队模板
//		edges.emplace_back(Edge(to, from, 0, 0)); //反向弧,初始容量为0
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
//		memset(d, 0, sizeof(d));
		queue<int> q;
		q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{//只考虑残量网络中的弧
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;//构造分层图
					q.push(e.to);
				}
			}
		}
		return vis[t];//有无增广路,s->t
	}
	int DFS(int x, int a)//x为当前点,a为当前边上流量
	{//在层次图上向t延伸,多路增广
		if(x==t||a==0)//到达目标/流量为0断流
			return a;
		int flow = 0, f;
		for(short& i=cur[x];i<G[x].size();i++)//从上一次x遍历跑到的点开始跑
		{//从上次考虑的弧
			Edge& e = edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow))) > 0)
			{//只从层数编号较小的点到下一层的点
				e.flow += f;//该路径上边流量都增加f
				edges[G[x][i]^1].flow -= f;//方便反悔
				flow += f;
				a -= f;//用去可增广量
				if(a==0)//a等于0及时退出
					break;//当a!=0,说明当前节点还存在另一个增广路分支。
			}
		}
		if(!flow)//增广后容量满了
			d[x] = -1;//炸点优化,不必要的点下一次就不用遍历
		return flow;//返回x节点最大流量,传递到上一级
	}
	int Maxflow(int s, int t)
	{
		this->s = s, this->t = t;
		int flow = 0;
		while (BFS())//不停地用bfs构造分层网络，然后用dfs沿着阻塞流增广
		{
			memset(cur, 0, sizeof(cur));//建完分层图后cur也要初始化
			flow += DFS(s,inf);
		}
		return flow;
	}
} di;
//bool mp[3001][3001];
//short x[3001],y[3001],v[3001];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,t,m,n;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&t,&n);
		short *x=new short[n+1],*y=new short[n+1],*v=new short[n+1];
		for(int j=1;j<=n;j++)
			scanf("%hd%hd%hd",&x[j],&y[j],&v[j]);
		scanf("%d",&m);
//		vector<vector<bool>>mp(n+1,vector<bool>(m+1,0));
		bool (*mp)[3003]=new bool[n+1][3003];
		for(int j=1,tx,ty;j<=m;j++)
		{
			scanf("%d%d",&tx,&ty);
			for(int k=1;k<=n;k++)
			{
				ll a=((ll)tx-x[k])*(tx-x[k])+(ty-y[k])*(ty-y[k]),b=(ll)t*t*v[k]*v[k];
				if(a<=b)
					mp[k][j]=1;
				else
					mp[k][j]=0;
			}
		}
		delete []x;
		delete []y;
		delete []v;
		di.init(n+m+2);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(mp[j][k])
					di.AddEdge(j,n+k,1);
//		mp.clear();
		delete []mp;
		int st=n+m+1,ed=n+m+2;
		for(int j=1;j<=n;j++)
			di.AddEdge(st,j,1);
		for(int j=1;j<=m;j++)
			di.AddEdge(n+j,ed,1);
		printf("Scenario #%d:\n%d",i,di.Maxflow(st,ed));
		if(i<T)
			putchar('\n');
		putchar('\n');
	}
	return 0;
}


