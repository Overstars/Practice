#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
int head[maxn],cnt=0;
int gene[maxn][31],lg[maxn],depth[maxn];
struct edge
{
	int v,nex;
} e[maxn<<1];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=fa)
			dfs(e[i].v,x);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	while(depth[x]>depth[y])
		x=gene[x][lg[depth[x]-depth[y]-1]];
	if(x==y)
		return x;
	for(int i=lg[depth[x]];i>=0;i--)
		if(gene[x][i]!=gene[y][i])
		{
			x=gene[x][i];
			y=gene[y][i];
		}
	return gene[x][0];
}
inline void init(int n,int s)
{
	depth[s]=1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	dfs(s,0);
}
int ord[maxn],power[maxn];
void dfs(int x)
{
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=gene[x][0])
		{
			dfs(e[i].v);
			power[x]+=power[e[i].v];
		}
}
signed main()
{
//	freopen("P3258.in","r",stdin);
	memset(head,-1,sizeof(head));
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&ord[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	init(n,1);
	for(int i=1;i<n;i++)
	{
		int a=ord[i],b=ord[i+1];
		int l=lca(a,b);
		power[a]++;//画个简单图自己按差分思想推一下
		power[gene[b][0]]++;//可以发现每次终点就是下一轮的起点,所以终点不加权值
		power[l]--;
		power[gene[l][0]]--;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%d\n",power[i]);
	return 0;
}
