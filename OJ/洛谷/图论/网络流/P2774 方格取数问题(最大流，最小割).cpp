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
const int maxn = 100005;//上大的模板
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
		for (int i = 0; i <= n; i++) G[i].clear();
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
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int m,n;
	scanf("%d%d",&m,&n);//棋盘的行数和列数
    int s=0,t=m*n+1,sum=0;//sum为总价值
    di.init(t+1);
    for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int val,no;
//			cin>>val;
			scanf("%d",&val);//i行j列的数值
			sum+=val;
			no=n*(i-1)+j;//重点：一行n个
			if((i+j)%2){//相邻的i+j奇偶性必定相斥
				di.AddEdge(s,no,val);//根据奇偶性连接
			}
			else{
				di.AddEdge(no,t,val);
			}
		}
	}//s与t的边插入结束
	int nx[4]={0,-1,0,1};//只枚举两个方向是不够的,因为是有向图
	int ny[4]={-1,0,1,0};
	for(int i=1;i<=m;i++)//m行
		for(int j=1;j<=n;j++)//n列
		{
			int no=n*(i-1)+j;
			if((i+j)%2){//二分图左边的节点,开始连接右面的节点
				for(int k=0;k<4;k++)//枚举方向,相邻的四个方格
				{
					int x=i+nx[k],y=j+ny[k];//x与m轴同方向
					if(x<=0||x>m||y<=0||y>n)
						continue;
					int no2=n*(x-1)+y;//相邻的方格编号
					di.AddEdge(no,no2,inf);
				}
			}
		}
//	cout<<sum-di.Maxflow(s,t)<<endl;
	printf("%d\n",sum-di.Maxflow(s,t));
	return 0;
}
