#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define debug
using namespace std;
const int maxn = 10005;//上大的模板
const int inf=0x3f3f3f3f;
struct Dinic
{
	struct Edge
	{
		int from, to, cap, flow;
		Edge(int u, int v, int c, int f):
			from(u), to(v), cap(c), flow(f) {}
	};
	int n, m, s, t; //结点数,边数(包括反向弧),源点编号和汇点编号
	vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
	vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
	bool vis[maxn]; //BFS使用
	int d[maxn]; //从起点到i的距离
	int cur[maxn]; //当前弧下标
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap)
    {
//        edges.emplace_back(Edge(from, to, cap, 0));//魔改蔡队模板
//        edges.emplace_back(Edge(to, from, 0, 0)); //反向弧
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
		memset(d, 0, sizeof(d));
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
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int DFS(int x, int a)//x为当前点,a为当前边上流量
	{
		if (x == t || a == 0)//到达目标/流量为0
			return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++)
		{ //从上次考虑的弧
			Edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}
		if(!flow)//不知道可不可以加
			d[x] = -1;//炸点优化必不可少,证明不必要的点下一次就不用遍历
		return flow;
	}
	int Maxflow(int s, int t)
	{
		this->s = s, this->t = t;
		int flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s,inf);
		}
		return flow;
	}
} di;
int main()
{
	#ifdef debug
		freopen("P2764.in","r",stdin);
	#endif // debug
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s=0,t=2*n+1;
	di.init(t);
	for(int i=1;i<=n;i++)
	{
		di.AddEdge(s,i,1);
		di.AddEdge(n+i,t,1);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		di.AddEdge(u,n+v,1);
//		di.AddEdge(v,u,1);
	}
	int ans=di.Maxflow(s,t);


	cout<<n-ans<<endl;
	return 0;
}
#ifdef debug
void out(int n)
{
	bool vis[maxn]={0};
	queue<int> qu[maxn];
	for(int i=1;i<=n;i++)
	{//枚举每个节点
		if(vis[i])
			continue;
//		cout<<i<<' ';
		int x=i,last=0;
		int nex=x;
		vis[i]=1;
		qu[i].push(i);
		while(last!=nex)
		{
			last=nex;
			for(int j=0;j<di.G[nex].size();j++)
			{
				int no=di.edges[di.G[nex][j]].to-n;
				if(!vis[no]&&no>0)
				{
					vis[no]=1;
					nex=no;//找到下一个节点
					qu[i].push(nex);
	//				cout<<no<<' ';
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(!qu[i].empty())
		{
			int tem=qu[i].front();
			qu[i].pop();
			if(qu[i].empty())
				cout<<tem<<'\n';
			else
				cout<<tem<<' ';
		}
	}
}
#endif // debug
