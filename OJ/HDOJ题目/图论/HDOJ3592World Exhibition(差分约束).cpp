#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=1051;
struct edge
{
	int v,w,next;
} e[MAXN<<6];
int cnt,dist[MAXN],head[MAXN],num[MAXN];
bool vis[MAXN];
inline void add(int u,int v,int w)//链式前向星存图,无向则双向添加
{
	e[cnt].v=v;//边的结尾节点
	e[cnt].w=w;
	e[cnt].next=head[u];//去找以u为起始的上一个节点(相当于链表,起始为-1)
	head[u]=cnt++;//保存该边(最后的边)在e[i]中的编号
}
bool SPFA(int n,int x)//节点数量n,起点编号x
{
	memset(dist,inf,sizeof(dist));
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
		for(int i=head[now];i!=-1;i=e[i].next)
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
int main()
{
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(0);
	int t,n,x,y,u,v,w;
	scanf("%d",&t);
	while(t--)
	{//输出1和n分开的最大距离,若不存在则-1,若任意则-2
		memset(head,-1,sizeof(head));
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<n;i++)
			add(i+1,i,0);
		for(int i=1;i<=x;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		for(int i=1;i<=y;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,-w);
		}
		if(SPFA(n,1))
			printf("-1\n");
		else if(dist[n]>=inf)
			printf("-2\n");
		else
			printf("%d\n",dist[n]);
	}
	return 0;
}
