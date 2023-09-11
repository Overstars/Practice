//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=305,MAXN=2*305*305,inf=0x3f3f3f3f,mod=1000000007;
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
		int from, to, cap, flow;
		Edge(int u, int v, int c, int f):
			from(u), to(v), cap(c), flow(f) {}
	};
	int n, m, s, t; //结点数,边数(包括反向弧),源点编号和汇点编号
	vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
	vector<int> G[MAXN]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
	bool vis[MAXN]; //BFS使用
	int d[MAXN]; //从起点到i的距离
	int cur[MAXN]; //当前弧下标
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
		for(int& i=cur[x];i<G[x].size();i++)//从上一次x遍历跑到的点开始跑
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
char s[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,tot=0,node=0;
	cin>>n>>m;
	int st=2*n*m+1,ed=2*n*m+2;
	di.init(ed+5);
	auto w=[&](int x,int y){return m*(x-1)+y;};//给横着的编号
	auto h=[&](int x,int y){return (n-1)*m+n*(y-1)+x;};//给竖着的边编号
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]+1;
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')
			{
				tot++;//统计数目
				if(i>1&&s[i-1][j]=='#')//上面有#,横边
					di.AddEdge(st,w(i-1,j),1),node++;
				if(j>1&&s[i][j-1]=='#')//左面有#,竖边
					di.AddEdge(h(i,j-1),ed,1),node++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')
			{//下,右
				if(i<n&&j<m&&s[i+1][j]=='#'&&s[i][j+1]=='#')
					di.AddEdge(w(i,j),h(i,j),1);
				//上,右
				if(i>1&&j<m&&s[i-1][j]=='#'&&s[i][j+1]=='#')
					di.AddEdge(w(i-1,j),h(i,j),1);
				//下,左
				if(i<n&&j>1&&s[i+1][j]=='#'&&s[i][j-1]=='#')
					di.AddEdge(w(i,j),h(i,j-1),1);
				//上,左
				if(i>1&&j>1&&s[i-1][j]=='#'&&s[i][j-1]=='#')
					di.AddEdge(w(i-1,j),h(i,j-1),1);
			}
		}
	}
	cout<<tot-(node-di.Maxflow(st,ed))<<endl;
	return 0;
}
/*
 *一个砖头定义为宽为1的矩形
 *给你一个平面,求最少由多少块砖头拼成
 *砖头长度任意但不能重叠
 *想不出来,看题解...
 *设一开始全部为1*1,逐渐删除边界
 *将边界看作点,则斜向相邻的点不会同时选中
 *将这些点连接起来,求最大独立集即为删去的边缘
 *横着的边为二分图左部,竖着的边为二分图右部
 *二分图最大独立集=点数-最小点覆盖(最大匹配)
 */

