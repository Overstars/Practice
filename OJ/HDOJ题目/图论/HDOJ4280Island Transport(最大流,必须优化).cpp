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
const int maxn = 200010;//kb的模板
const int inf=0x3f3f3f3f;
const int MAXN = 101050;//点数的最大值
const int MAXM = 202005;//边数的最大值
struct Dinic
{
	struct Edge
	{
		int to,next,cap,flow;
	}edge[MAXM];//注意是 MAXM
	int tol;
	int head[MAXN];
	void init()
	{
		tol = 2;
		memset(head,-1,sizeof(head));
	}
	void addedge(int u,int v,int w,int rw = 0)
	{
		edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
		edge[tol].next = head[u]; head[u] = tol++;
		edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
		edge[tol].next = head[v]; head[v] = tol++;
	}
	int Q[MAXN];
	int dep[MAXN],cur[MAXN],sta[MAXN];
	bool bfs(int s,int t,int n)
	{
		int front = 0,tail = 0;
		memset(dep,-1,sizeof(dep[0])*(n+1));
		dep[s] = 0;
		Q[tail++] = s;
		while(front < tail)
		{
			int u = Q[front++];
			for(int i = head[u]; i != -1;i = edge[i].next)
			{
				int v = edge[i].to;
				if(edge[i].cap > edge[i].flow && dep[v] == -1)
				{
					dep[v] = dep[u] + 1;
					if(v == t)
						return true;
					Q[tail++] = v;
				}
			}
		}
		return false;
	}
	int dinic(int s,int t,int n)
	{
		int maxflow = 0;
		while(bfs(s,t,n))
		{
			for(int i = 0;i < n;i++)
				cur[i] = head[i];
			int u = s, tail = 0;
			while(cur[s] != -1)
			{
				if(u == t)
				{
					int tp = inf;
					for(int i = tail-1;i >= 0;i--)
						tp = min(tp,edge[sta[i]].cap-edge[sta[i]].flow) ;
					maxflow += tp;
					for(int i = tail-1;i >= 0;i--)
					{
						edge[sta[i]].flow += tp;
						edge[sta[i]^1].flow -= tp;
						if(edge[sta[i]].cap-edge[sta[i]].flow == 0)
							tail = i;
					}
					u = edge[sta[tail]^1].to;
				}
				else if(cur[u] != -1 && edge[cur[u]].cap > edge[cur[u]].flow && dep[u] + 1 == dep[edge[cur[u]].to])
				{
					sta[tail++] = cur[u];
					u = edge[cur[u]].to;
				}
				else {
					while(u != s && cur[u] == -1)
						u = edge[sta[--tail]^1].to;
					cur[u] = edge[cur[u]].next;
				}
			}
		}
		return maxflow;
	}
} di;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    int T,n,m;
    cin>>T;
    while(T--)
    {
    	cin>>n>>m;//点数,边数,源点,汇点
        di.init();
        int s=0,t=0,maxi=-inf,mini=inf;
        for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			if(mini>x)
			{
				s=i;
				mini=x;
			}
			if(maxi<x)
			{
				t=i;
				maxi=x;
			}
		}
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
			cin>>u>>v>>w;
            di.addedge(u,v,w);
            di.addedge(v,u,w);
        }
        cout<<di.dinic(s,t,n)<<endl;
    }
    return 0;
}
