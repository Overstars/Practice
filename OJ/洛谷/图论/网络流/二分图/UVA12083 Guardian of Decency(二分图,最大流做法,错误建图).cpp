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
		if(!flow)//��֪���ɲ����Լ�
			d[x] = -2;//ը���Ż��ز�����,֤������Ҫ�ĵ���һ�ξͲ��ñ���
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
bool judge(int x,int y)//��������������,Ϊ��
{
	if(abs(arr[x].h-arr[y].h)>40)//��߲����40
		return 0;
	if(arr[x].sex==arr[y].sex)//�Ա���ͬ
		return 0;
//	if(arr[x].music.compare(arr[y].music))//����ͬ
//		cnt++;
//	if(!arr[x].sport.compare(arr[y].sport))//��ͬ
//		cnt++;
    if(strcmp(arr[x].music,arr[y].music))//����ͬ
		return 0;
    if(!strcmp(arr[x].sport,arr[y].sport))//��ͬ
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
                if(judge(i,j))//���������ܵ�������
                {
                    di.AddEdge(i,n+j,1);
//                    di.AddEdge(n+j,i,1);
                }
            }
//        for(int i=4*n;i<=di.edges.size();i+=2)
//        {
//            if(di.edges[i].flow)
//                cout<<"�ڵ�:"<<(di.edges[i].from)/2+1<<endl;
//        }
        printf("%d\n",n-di.Maxflow(s,t));
    }
    return 0;
}
