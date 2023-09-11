#pragma comment(linker,"/STACK:102400000,102400000")
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
const int maxn = 100200;//�ϴ��ģ��
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
int main()
{
	//https://codeforc.es/problemset/problem/727/D
	map<string,int> TAT;
	string sizes[7]={"","S","M","L","XL","XXL","XXXL"};
	for(int i=1;i<=6;i++)
		TAT[sizes[i]]=i;
	int s=0,n,t,si[7];
	for(int i=1;i<=6;i++)
	{
		cin>>si[i];
	}
	cin>>n;
	t=n+6+1;
	di.init(t+10);
	for(int i=1;i<=6;i++)
		di.AddEdge(s,i,si[i]);
	for(int i=1;i<=n;i++)
	{
		string str;
		char tem[15];
		cin>>tem;
		int len=strlen(tem);
		for(int j=0;j<=len;j++)
		{
			if(tem[j]!=','&&tem[j]!='\0')
				str+=tem[j];
			else if(tem[j]==','){
				di.AddEdge(TAT[str],6+i,1);
//				cout<<"��"<<i<<"��ͬѧ="<<str<<endl;
				str.clear();
			}
			else{
				di.AddEdge(TAT[str],6+i,1);
//				cout<<"��"<<i<<"��ͬѧ="<<str<<endl;
				break;
			}
		}
		di.AddEdge(6+i,t,1);
	}
	if(di.Maxflow(s,t)==n)
	{
		cout<<"YES"<<endl;
		for(int i=12;i<di.edges.size();i+=2)
		{
			if(di.edges[i].from<=6&&di.edges[i].from>=1&&di.edges[i].to<=6+n&&di.edges[i].to>6)
				if(di.edges[i].flow>0)
					cout<<sizes[di.edges[i].from]<<endl;
		}
	}
	else
		cout<<"NO"<<endl;
	return 0;
}
