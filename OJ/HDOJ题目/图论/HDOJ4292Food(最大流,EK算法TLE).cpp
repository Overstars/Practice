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
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):
        from(u), to(v), cap(c), flow(f) {}
};
struct EdmonsKarp //时间复杂度O(v*E*E)
{
    int n, m;//n个节点,m条边(这个m不要去管)
    vector<Edge> edges; //边数的两倍
    vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    int a[maxn]; //起点到i的可改进量
    int p[maxn]; //最短路树上p的入弧编号
    void init()
    {
        for(int i = 0; i < n; i++)
            G[i].clear();
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
    int Maxflow(int s, int t)
    {
        int flow = 0;
        while(1)
        {
            memset(a, 0, sizeof(a));
            queue<int> q;
            q.push(s);
            a[s] = inf;
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i = 0; i < (int)G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        q.push(e.to);
                    }
                }
                if (a[t])
                    break;
            }
            if(!a[t])
                break;
            for(int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
} ek;
int n,f,d;
void getmap(int s,int t)
{
	int tem;
	for(int i=1;i<=n;i++)//将人添加到图里
		ek.AddEdge(i,i+n,1);
	for(int i=1;i<=f;i++)
	{
		cin>>tem;//食物的数量
		ek.AddEdge(s,2*n+i,tem);//超级源点到各种食物
	}
	for(int i=1;i<=d;i++)
	{
		cin>>tem;
		ek.AddEdge(2*n+f+i,t,tem);//饮料到超级汇点
	}
	for(int i=1;i<=n;i++)//食物->第i个人
	{
		char ch;
		for(int j=1;j<=f;j++)
		{
			scanf(" %c",&ch);
			if(ch=='Y')
				ek.AddEdge(2*n+j,i,1);
		}
	}
	for(int i=1;i<=n;i++)//第i个人->饮料
	{
		char ch;
		for(int j=1;j<=d;j++)
		{
			scanf(" %c",&ch);
			if(ch=='Y')
				ek.AddEdge(n+i,2*n+f+j,1);
		}
	}
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    int s,t;
    while(cin>>n>>f>>d)//n个人,f种食物,d种饮料
    {
    	s=0,t=2*n+f+d+1;
    	ek.n=2*n+f+d+1;
        ek.init();
        getmap(s,t);
        cout<<ek.Maxflow(s,t)<<endl;
    }
    return 0;
}
