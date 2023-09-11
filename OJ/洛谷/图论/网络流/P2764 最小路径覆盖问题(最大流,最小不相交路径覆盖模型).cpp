//#pragma GCC optimize("O2")
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
const int maxn = 13005;//�ϴ��ģ��
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
	int n, m, s, t; //�����,����(��������),Դ���źͻ����
	vector<Edge> edges; //�߱�edge[e]��edge[e^1]��Ϊ����
	vector<int> G[maxn]; //�ڽӱ�G[i][j]��ʾ�ڵ�i�ĵ�j������e�����е����
	bool vis[maxn]; //BFSʹ��
	int d[maxn]; //����㵽i�ľ���
	int cur[maxn]; //��ǰ���±�
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	inline void AddEdge(int from, int to, int cap)
    {
//        edges.emplace_back(Edge(from, to, cap, 0));//ħ�Ĳ̶�ģ��
//        edges.emplace_back(Edge(to, from, 0, 0)); //����
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
	int DFS(int x, int a)//xΪ��ǰ��,aΪ��ǰ��������
	{
		if (x == t || a == 0)//����Ŀ��/����Ϊ0
			return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++)
		{ //���ϴο��ǵĻ�
			Edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				if(x!=s)
				{
					nex[x]=e.to;//��¼��һ���ڵ�,�������
					vist[e.to-all]=1;//����,�����
				}
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}//���ⲻ������ը���Ż�������
//		if(!flow)//��֪���ɲ����Լ�
//			d[x] = -2;//ը���Ż��ز�����,֤������Ҫ�ĵ���һ�ξͲ��ñ���
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
//void output(int x)
//{
//	printf("%d ",x);
//	for(int i=)
//}
//void show(int n,int t)
//{
//	for(int i=0;i<=n;i++)
//		fa[i]=i;
//	for(int i=0;i<=m;i++)
//	{
//		if(di.edges[i].from>=1&&di.edges[i].from<=n&&di.edges[i].to<t&&di.edges[i].to>n&&di.edges[i].flow==1)
//		{
//			fa[findfa(di.edges[i].to-n)]=findfa(di.edges.from);
//		}
//		for(int i=1;i<=n;i++)
//			if(findfa(i)==1)
//			{
//				output(i);
//				putchar('\n');
//			}
//	}
//}
//#define debug
int main()
{
	#ifdef debug
		freopen("P2764.in","r",stdin);
	#endif // debug
//	std::ios::sync_with_stdio(false);
//    std::cin.tie(0);
//    std::cout.tie(0);
	int n,m;
	memset(vist,0,sizeof(vist));
	cin>>n>>m;
	all=n;
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
	}
	int ans=di.Maxflow(s,t);
	for(int i=1;i<=n;i++)
	{
//		queue<int> tem;
		if(!vist[i])//û��ǵľ������
		{
			int now=i;
			cout<<now<<' ';
			while(nex[now]&&nex[now]!=t)
			{
				cout<<nex[now]-n<<' ';
				now=nex[now]-n;
			}
			cout<<endl;
//			tem.push(now);
//			while(nex[now]&&nex[now]!=t)
//			{
//				tem.push(nex[now]-n);
//				now=nex[now]-n;
//			}
		}
//		while(!tem.empty())
//		{
//			int no;
//			no=tem.front();
//			tem.pop();
//			if(tem.empty())
//				cout<<no<<endl;
//			else
//				cout<<no<<' ';
//		}
	}
	cout<<n-ans<<endl;
	return 0;
}
