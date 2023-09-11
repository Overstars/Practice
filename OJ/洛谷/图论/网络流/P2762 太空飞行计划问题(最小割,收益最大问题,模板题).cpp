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
		memset(vis, 0, sizeof(vis));//���vis
		memset(d, 0, sizeof(d));//������
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
				if (!vis[e.to] && e.cap > e.flow)//��ʣ������
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;//�����һ��
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
bool read(int &x)
{
//����ֵ�������Ƿ�����,1��0��
//��ʵ�ö����³���Ի������ã������ĩ�пո��GG��
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
	int m,n;//ʵ����,������
	scanf("%d%d",&m,&n);
	int s=0,t=m+n+1,sum=0;
	di.init(t);
	for(int i=1;i<=m;i++)
	{
		int profit,equ;
//		bool flag=read(profit);
//		cin>>profit;//����cin�����ᵼ�µ�һλ�ַ���ʧ
		scanf("%d",&profit);
		sum+=profit;
		di.AddEdge(s,i,profit);//Դ�㵽ʵ��
		while(1)
		{
			char ch;
			scanf("%d%c",&equ,&ch);
//			printf("%d:equ=%d\n",i,equ);
			di.AddEdge(i,m+equ,inf);//ʵ�鵽����
			if(ch=='\r'||ch=='\n')
				break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cost;
		scanf("%d",&cost);
		di.AddEdge(m+i,t,cost);//���ĵ����
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
 *Q:ʹ��d�����ж�ѡ������Щʵ��������,�����һ��BFS�������ĵ�,��ô���ͻ�Ҳ�ᱻ�����
 *A:BFS������������ȥ��ʵ��,��Ϊ������ʵ�顣BFS��������������������ΪҪ����ʵ�����������������
 *�������ë����Ϊ���е�ʵ���ֵ�ܺ͡�������Ϊʵ���ֵ�ܺ�-������ʵ���ֵ��-�������������Ļ���
 *��ͼ��������������С�������ʵ��߸�����������豸��Ҳ�ڸ��(����������Ҫ�����)������С�Ϊ��С����
 *�������һ��BFS������δ�������ʵ��Ϊ�Ǳ��ͻ������������ȡ�
 *����δ�������ʵ��(��ѡ��ȥ����ʵ��)�����ӵ��豸ͬ������������
*/
