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
const int inf=0x3f3f3f3f,maxn=1005;
struct node
{
	int v,w,next;
} e[maxn];
int cnt,dist[maxn],head[maxn];//这题不用统计入队次数
bool vis[maxn];
void add(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
bool SPFA(int n,int x,int t)//传入节点数及起点
{
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[x]=0;
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		vis[now]=0;
		QAQ.pop();
		for(int i=head[now];i!=-1;i=e[i].next)
		{
			int to=e[i].v;
			if(dist[to]>dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;
				if(!vis[to])
				{
					vis[to]=1;
					QAQ.push(to);
				}
			}
//			printf("now=%d,to=%d\n",now,to);
		}
	}
	return dist[t]<inf;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,m,s,t;
	while(cin>>n>>m)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		scanf("%d%d",&s,&t);
		if(s>=n||t>=n)
		{
			printf("-1\n");
			continue;
		}
		cout<<(SPFA(n,s,t)?dist[t]:-1)<<endl;
	}
	return 0;
}
