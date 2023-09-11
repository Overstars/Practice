//#pragma comment(linker,"/STACK:102400000,102400000")
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
const int maxn = 10005;//�ϴ��ģ��
const int inf=0x3f3f3f3f;
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
		for (int i = 0; i < n; i++) G[i].clear();
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
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}
		if(!flow)//��֪���ɲ����Լ�
			d[x] = -1;//ը���Ż��ز�����,֤������Ҫ�ĵ���һ�ξͲ��ñ���
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
bool f[55][7];
int main()
{
	int ca,n,d;
	cin>>ca;
	while(ca--)
	{
		int s,t,sum=0,maxweek=1;
		int d[55],w[55];
		cin>>n;//n����Ӱ
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=7;j++)
			{
				int tem;
				cin>>tem;
				if(tem==1)
					f[i][j]=1;
				else
					f[i][j]=0;
			}
			cin>>d[i]>>w[i];//����ĳ���,��ֹ����
			sum+=d[i];
			maxweek=max(maxweek,w[i]);
		}
		s=0,t=7*maxweek+n+1;
		di.init(t);
		for(int i=1;i<=maxweek*7;i++)//��ʼ��ͼ
			di.AddEdge(s,i,1);//Դ������ÿһ��
		for(int i=1;i<=n;i++)//��i����Ӱ
		{
			for(int j=1;j<=7;j++)
				if(f[i][j])//����j����
					for(int k=1;k<=w[i];k++)//������������w[i]
					{
							di.AddEdge((k-1)*7+j,7*maxweek+i,1);
					}
			di.AddEdge(7*maxweek+i,t,d[i]);
		}
		if(di.Maxflow(s,t)==sum)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
