#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=50005;
struct node
{
	int v,w,next;
} e[MAXN<<4];
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
//	memset(dist,-1,sizeof(dist));
	fill(dist,dist+MAXN,-inf);
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
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
			if(dist[to]<dist[now]+e[i].w)
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
int main()
{
	int t,n,a,b,c;
	bool fl=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int lim=0;
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			add(a,b+1,c);//这里不换方向,要求最长路
			lim=max(lim,b+1);
		}
		for(int i=1;i<=lim;i++)
		{//加上之间本身约束
			add(i-1,i,0);
			add(i,i-1,-1);
		}
		SPFA(n,0);
		cout<<dist[lim]<<'\n';
		if(!t)
			cout<<'\n';
	}
	return 0;
}
