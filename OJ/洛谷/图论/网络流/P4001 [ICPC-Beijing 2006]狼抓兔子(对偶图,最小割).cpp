#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5,inf=0x3f3f3f3f;
struct qnode{
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];//使用前必须清空0~n
bool vis[MAXN];
int dist[MAXN];//到这个点的最近队员的
void Dijkstra(int n,int start)//传入总数及起点
{//点的编号从 1 开始
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dist[i]=inf;
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
	dist[start]=0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty())
	{
		tmp=que.top();
		que.pop();
		int u=tmp.v;
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=0;i<E[u].size();i++)
		{
			int v=E[tmp.v][i].v;
			int cost=E[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void add(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
}
int n,m;
inline int getid(int x,int y,int op)
{//边x行y列
	int no=(x-1)*(m-1)+(y-1);
	no=no*2;
//	printf("(%d,%d,%d)=%d\n",x,y,op,no+1+op);
	if(op==0)
		return no+1;
	else
		return no+2;
}
inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("P4001_10.in","r",stdin);
	int u,v,x,y,w;//内部一共n*m块
//	cin>>n>>m;
//	scanf("%d%d",&n,&m);
	read(n),read(m);
	int s=(n-1)*(m-1)*2+1,t=s+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
//			cin>>w;
//			scanf("%d",&w);
			read(w);
			u=s,v=t;
			if(i!=1)
				u=getid(i-1,j,0);
			if(i!=n)
				v=getid(i,j,1);
			add(u,v,w);
			add(v,u,w);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			cin>>w;
//			scanf("%d",&w);
			read(w);
			u=t,v=s;
			if(j!=1)
				u=getid(i,j-1,1);
			if(j!=m)
				v=getid(i,j,0);
			add(u,v,w);
			add(v,u,w);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
//			cin>>w;
//			scanf("%d",&w);
			read(w);
			u=getid(i,j,0);
			v=getid(i,j,1);
			add(u,v,w);
			add(v,u,w);
		}
	}
	Dijkstra(t,s);
	printf("%d\n",dist[t]);
//	cout<<dist[t]<<endl;
	return 0;
}
