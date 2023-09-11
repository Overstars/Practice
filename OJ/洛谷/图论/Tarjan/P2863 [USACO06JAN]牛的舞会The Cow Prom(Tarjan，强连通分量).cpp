#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=50005;
struct edge
{
	int v,nex;//链式前向星
} e[maxn];
int head[maxn];//head[u]表示以u为起点的边的索引
int dfn[maxn],low[maxn],stk[maxn],cnt,tot,Index,ans;
bool vis[maxn];
void add(int u,int v)
{
	e[++cnt].nex=head[u];
	e[cnt].v=v;
	head[u]=cnt;
}
void tarjan(int x)//处理x号节点
{//dfn[x]记录当前访问时间,low[x]记录所属强连通子图的最小时间戳
	dfn[x]=low[x]=++tot;//新点的初始化
	stk[++Index]=x;//进栈
	vis[x]=1;//表示x节点在栈里
	for(int i=head[x];i!=-1;i=e[i].nex)//x向下延伸到v节点(e[i].v)
	{//遍历的顺序与存边的顺序相反
		if(!dfn[e[i].v])//v之前未访问过
		{
			tarjan(e[i].v);//向下延伸
			low[x]=min(low[x],low[e[i].v]);//x是否为v的子节点
		}
		else if(vis[e[i].v])//v在栈里
		{
			low[x]=min(low[x],dfn[e[i].v]);//v是否为x的更小祖先
		}//若v被访问且不在栈中,直接略过
	}
	if(low[x]==dfn[x])//x是整个强连通分量子树里的最小根
	{
		int tem=0;
		do{
//			printf("%d ",stk[Index]);
			vis[stk[Index]]=0;
			Index--;
			tem++;
		}while(stk[Index+1]!=x);//退栈
		if(tem>1)//该强连通图节点大于1
			ans++;
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])//i没有被访问(图不连通)
			tarjan(i);
	cout<<ans<<endl;
	return 0;
}
