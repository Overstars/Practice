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
int nex[maxn];
bool vist[maxn];
int all;
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
		for (int i = 0; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	inline void AddEdge(int from, int to, int cap)
    {
//        edges.emplace_back(Edge(from, to, cap, 0));//魔改蔡队模板
//        edges.emplace_back(Edge(to, from, 0, 0)); //反向弧
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        this->m = edges.size();
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
				if(x!=s)
				{
					nex[x]=e.to;//记录下一个节点,便于输出
					vist[e.to-all]=1;//打标记,找起点
				}
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}//这题不能乱用炸点优化！！！
		if(!flow)//不知道可不可以加
			d[x] = -2;//炸点优化必不可少,证明不必要的点下一次就不用遍历
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
struct student
{
	int h;
	char sex;
	char music[105];
	char sport[105];
	student()
	{
		h=0;
		sex='\0';
		music[0]=sport[0]='\0';
	}
} arr[maxn];
bool judge(int x,int y)//若四条都不符合,为真
{
	if(abs(arr[x].h-arr[y].h)>40)//身高差大于40
		return 0;
	if(arr[x].sex==arr[y].sex)//性别相同
		return 0;
//	if(arr[x].music.compare(arr[y].music))//不相同
//		cnt++;
//	if(!arr[x].sport.compare(arr[y].sport))//相同
//		cnt++;
    if(strcmp(arr[x].music,arr[y].music))//不相同
		return 0;
    if(!strcmp(arr[x].sport,arr[y].sport))//相同
		return 0;
	return 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("UVA12083.in","r",stdin);
    int ca,n,s=0,t;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        t=2*n+1;
        for(int i=1;i<=n;i++)
		{
			scanf("%d %c%s%s",&arr[i].h,&arr[i].sex,arr[i].music,arr[i].sport);
		}
		di.init(t);
		for(int i=1;i<=n;i++)
        {
//            if(arr[i].sex=='M')
                di.AddEdge(s,i,1);
//            else
                di.AddEdge(n+i,t,1);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
            {
//                if(arr[j].sex=='M')
//                    continue;
                if(judge(i,j))//有恋爱可能的人连边
                {
                    di.AddEdge(i,n+j,1);
//                    di.AddEdge(n+j,i,1);
                }
            }
//        for(int i=4*n;i<=di.edges.size();i+=2)
//        {
//            if(di.edges[i].flow)
//                cout<<"节点:"<<(di.edges[i].from)/2+1<<endl;
//        }
        printf("%d\n",n-di.Maxflow(s,t));
    }
    return 0;
}
