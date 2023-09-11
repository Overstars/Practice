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
		memset(vis, 0, sizeof(vis));//清空vis
		memset(d, 0, sizeof(d));//清空深度
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
				if (!vis[e.to] && e.cap > e.flow)//有剩余流量
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;//标记下一层
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
bool read(int &x)
{
//返回值代表本行是否还有数,1有0无
//其实该读入的鲁棒性还不够好，如果行末有空格就GG了
    char c=' ';
    x=0;
    while(c<'0'||c>'9')
		c=getchar();
    while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
    return (c=='\r'||c=='\n')?0:1;
}
char tools[10000];
//void deal(int num)
//{
//    memset(tools,0,sizeof(tools));
//    cin.getline(tools,10000);
//    int ulen=0,tool;
//    while(sscanf(tools+ulen,"%d",&tool)==1){
//        di.add_edge(num,tool+n,Inf);
//        if(tool==0) ulen++;
//        else{
//            while(tool){
//                tool/=10;
//                ulen++;
//            }
//        }
//    }
//}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int m,n;//实验数,仪器数
	scanf("%d%d",&m,&n);
	int s=0,t=m+n+1,sum=0;
	di.init(t);
	for(int i=1;i<=m;i++)
	{
		int profit,equ;
//		bool flag=read(profit);
//		cin>>profit;//混用cin与快读会导致第一位字符丢失
		scanf("%d",&profit);
		sum+=profit;
		di.AddEdge(s,i,profit);//源点到实验
		while(1)
		{
			char ch;
			scanf("%d%c",&equ,&ch);
//			printf("%d:equ=%d\n",i,equ);
			di.AddEdge(i,m+equ,inf);//实验到器材
			if(ch=='\r'||ch=='\n')
				break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cost;
		scanf("%d",&cost);
		di.AddEdge(m+i,t,cost);//器材到汇点
	}
	int ans=di.Maxflow(s,t);
//	for(int i=0;i<di.edges.size();i+=2)
//	{
//		if(di.edges[i].from==s&&di.edges[i].flow>0)
//			printf("%d ",di.edges[i].to);
//	}
//	putchar('\n');
//	for(int i=2*m;i<di.edges.size();i+=2)
//	{
//		if(di.edges[i].to==t&&di.edges[i].flow>0)
//			printf("%d ",di.edges[i].from-m);
//	}
	for(int i=1;i<=m;i++)
	{
		if(di.d[i])
			printf("%d ",i);
	}
	putchar('\n');
	for(int i=1;i<=n;i++)
	{
		if(di.d[m+i])
			printf("%d ",i);
	}
	printf("\n%d\n",sum-ans);
	return 0;
}
/*
 *1.
 *Q:使用d数组判断选择了哪些实验与器材,即最后一次BFS遍历到的点,那么饱和弧也会被标记吗？
 *A:BFS还能再搜索下去的实验,即为放弃的实验。BFS还能搜索到的仪器，即为要做的实验所需的所有仪器。
 *假设最大毛利润为所有的实验价值总和。净利润即为实验价值总和-不做的实验价值和-购买所需仪器的花费
 *建图后跑最大流求出最小割，满流的实验边割掉，满流的设备边也在割集里(但是这是需要购买的)，该最小割即为最小亏损
 *所以最后一次BFS，所有未被割掉的实验为非饱和弧，可以求出深度。
 *所以未被割掉的实验(及选择去做的实验)所连接的设备同样可以求出深度
*/
