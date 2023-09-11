#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=5051;
struct node
{
	int v,w,next;
} e[MAXN];
int cnt,dist[MAXN],head[MAXN],num[MAXN];
bool vis[MAXN];
void add(int u,int v,int w)//链式前向星存图,无向则添加双向
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
	num[x]++;
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		QAQ.pop();
		vis[now]=0;//从队列中取出
		for(int i=head[now];i!=-1;i=e[i].next)//遍历以now开头的所有边,尝试以x->now->to松弛x->to
		{
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
	//题意:是否存在一个权值之和为负的环
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		int n,m,w;//n点,m正边,w负边
		scanf("%d%d%d",&n,&m,&w);
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);//走廊是双向的
		}
		for(int i=0;i<w;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,-c);//负边是单向的
		}
		cout<< (SPFA(n,1)?"YES":"NO") <<endl;
	}
	return 0;
}
