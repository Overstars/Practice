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
int kind[22];
vector<int> rec[22];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n,k,m=0,ans=0;
	cin>>k>>n;
	int s=0,t=k+n+1;
	di.init(k+n+2);
	for(int i=1;i<=k;i++)
	{
		cin>>kind[i];
		m+=kind[i];
		di.AddEdge(s,i,kind[i]);//第i种类的容量
	}
	for(int i=1;i<=n;i++)
	{
		int p,x;
		cin>>p;
		for(int j=1;j<=p;j++)//第i题的分类p个
		{
			cin>>x;//第i题类型之一x
			di.AddEdge(x,k+i,1);
		}
		di.AddEdge(k+i,t,1);
	}
	if((ans=di.Maxflow(s,t))==m)
	{
//		printf("ans=%d\n",ans);
		for(int i=2*k;i<di.edges.size();i+=2)
		{
			if(di.edges[i].from<=k&&di.edges[i].to<=n+k&&k<di.edges[i].to&&di.edges[i].flow>0)
			{
				rec[di.edges[i].from].push_back(di.edges[i].to-k);
			}
//			printf("第%d次循环\n",i);
		}
		for(int i=1;i<=k;i++)
		{
			printf("%d: ",i);
			for(int j=0;j<rec[i].size();j++)
			{
				printf("%d",rec[i][j]);
				if(j<kind[i]-1)
					putchar(' ');
				else
					putchar('\n');
			}
		}
	}
	else
		cout<<"No Solution!"<<endl;
	return 0;
}
