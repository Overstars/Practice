#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=10005;
struct node
{
	int v,w,next;
} e[MAXN];
int cnt,dist[MAXN],head[MAXN],num[MAXN];
bool vis[MAXN];
void add(int u,int v,int w)//链式前向星存图,无向则双向添加
{
	e[cnt].v=v;//边的结尾节点
	e[cnt].w=w;
	e[cnt].next=head[u];//去找以u为起始的上一个节点(相当于链表,起始为-1)
	head[u]=cnt++;//保存该边(最后的边)在e[i]中的编号
}
bool SPFA(int n,int x)//节点数量n,起点编号x
{
	memset(dist,inf,sizeof(dist));
//	memset(vis,0,sizeof(vis));
//	memset(num,0,sizeof(num));
	dist[x]=0;//该题起点任意
	num[x]++;//入队次数++
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		QAQ.pop();
		vis[now]=0;//从队列中取出
		for(int i=head[now];~i;i=e[i].next)
		{//遍历以now开头的所有边,尝试以x->now->to松弛x->to
			int to=e[i].v;//尝试松弛x->to的当前距离
			if(dist[to]>dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;//成功用x->now->to松弛x->to
				if(!vis[to])//x->to被成功松弛且to不在队列
				{
					vis[to]=1;//标记to加入队列
					QAQ.push(to);
					num[to]++;//to加入队列次数++
					if(num[to]>n)
						return 1;//有负权回路,无法求最短路径
				}
			}
		}
	}
	return 0;
}
bool spfa(int x)//DFS优化
{
	vis[x]=1;
	for(int i=head[x];~i;i=e[i].next)
	{
		int v=e[i].v;
		if(dist[v]>dist[x]+e[i].w)
		{
			dist[v]=dist[x]+e[i].w;
			if(vis[v])//存在负权环
				return 0;
			if(!spfa(v))//搜到了存在负权环
				return 0;
		}
	}
	vis[x]=0;
	return 1;//未找到负权环
}
int main()
{
//	freopen("P1993.in","r",stdin);
	memset(head,-1,sizeof(head));
	int n,m,a,b,c,ope;
	cin>>n>>m;
	while(m--)
	{
		cin>>ope;
		if(ope==1)
		{
			cin>>a>>b>>c;
			add(a,b,-c);
		}
		else if(ope==2)
		{
			cin>>a>>b>>c;
			add(b,a,c);
		}
		else{
			cin>>a>>b;
			add(a,b,0);
			add(b,a,0);
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{//图是不连通的
		dist[i]=1;
		if(!(flag=spfa(i)))
			break;
	}
	if(!flag)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
