#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int maxn = 200010;//�ϴ��ģ��
const int inf=0x3f3f3f3f;
typedef long long ll;
struct Dinic
{
    struct Edge
    {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f):
            from(u), to(v), cap(c), flow(f) {}
    };
    int n, m, s, t; //�����,����(��������),Դ���źͻ����
    vector<Edge> edges; //�߱�edge[e]��edge[e^1]��Ϊ����
    vector<int> G[maxn]; //�ڽӱ�G[i][j]��ʾ�ڵ�i�ĵ�j������e�����е����
    bool vis[maxn]; //BFSʹ��
    ll d[maxn]; //����㵽i�ľ���
    int cur[maxn]; //��ǰ���±�
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
//        edges.emplace_back(Edge(from, to, cap, 0));//ħ�Ĳ̶�ģ��
//        edges.emplace_back(Edge(to, from, 0, 0)); //����
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
    int DFS(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        ll flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        { //���ϴο��ǵĻ�
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
        if(!flow)
            d[x] = -1;//ը���Ż����ز����٣�֤������Ҫ�ĵ���һ�ξͲ��ñ���
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        ll flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s,inf);
        }
        return flow;
    }
} di;
int a[100005],b[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
		int dis;
		cin>>a[i]>>b[i]>>dis;//a��b����
	}
	for(int i=1;i<=n;i++)//Ҫ���в��
	{
		int cap;
		cin>>cap;
		if(i==1||i==n)
			cap=inf;
		di.AddEdge(i,n+i,cap);
	}
	for(int i=1;i<=m;i++)
	{
		di.AddEdge(a[i]+n,b[i],inf);
		di.AddEdge(b[i]+n,a[i],inf);
	}
	cout<<di.Maxflow(1,n<<1)<<endl;
    return 0;
}

