#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100005;
const int maxl=30;
int father[maxn];
struct Edge
{
	int u,v,w;
	Edge(int a=0, int b=0, int c=0):
		u(a), v(b), w(c) {}
} e[maxn<<3];
vector<Edge> G[maxn];
bool cmp(const Edge &a,const Edge &b)
{
	return a.w>b.w;
}
int findfa(int x)
{
	if(father[x]!=x)
		father[x]=findfa(father[x]);
	return father[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		father[b]=a;
	else
		father[a]=b;
	return 1;
}
int kruskal(int n,int m)
{
	sort(e,e+m,cmp);
	int ans=0;
	for(int i=0;i<=n;i++)
		father[i]=i;
	for(int i=0;i<m;i++)
	{
		if(Merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			G[e[i].u].push_back(Edge(e[i].u,e[i].v,e[i].w));//建立新图：最大生成树
			G[e[i].v].push_back(Edge(e[i].v,e[i].u,e[i].w));
			n--;
			if(n==1)
				return ans;
		}
	}
	return 0;
}
int gene[maxn][maxl],depth[maxn],lg[maxn];
int weight[maxn][maxl];
bool vis[maxn];
void dfs(int x,int fa)
{
	vis[x]=1;
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
	{
		gene[x][i]=gene[gene[x][i-1]][i-1];
		weight[x][i]=min(weight[x][i-1],weight[gene[x][i-1]][i-1]);
	}
	for(int i=0;i<G[x].size();i++)
		if(G[x][i].v!=fa&&!vis[G[x][i].v])
		{
			weight[G[x][i].v][0]=G[x][i].w;
			dfs(G[x][i].v,x);
		}
}
int lca(int x,int y)
{
	if(findfa(x)!=findfa(y))
		return -1;
	int ans=inf;
	if(depth[x]<depth[y])
		swap(x,y);
	while(depth[x]>depth[y])
	{
		ans=min(ans,weight[x][lg[depth[x]-depth[y]-1]]);
		x=gene[x][lg[depth[x]-depth[y]-1]];
	}
	if(x==y)
		return ans;
	for(int i=lg[depth[x]];i>=0;i--)
		if(gene[x][i]!=gene[y][i])
		{
			ans=min(ans,min(weight[x][i],weight[y][i]));
			x=gene[x][i];
			y=gene[y][i];
		}
	return min(ans,min(weight[x][0],weight[y][0]));
}
void init(int n)
{
	memset(gene,0,sizeof(gene));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!depth[i])
		{
			depth[i]=1;
			dfs(i,0);
		}
	depth[1]=1;
	dfs(1,0);
//	for(int i=1;i<=maxl;i++)
//		for(int x=1;x<=n;x++)
//		{
//			weight[x][i]=min(weight[x][i-1],weight[gene[x][i-1]][i-1]);
//		}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++)//lg数组应该这么写
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e[i].u=x,e[i].v=y,e[i].w=z;
	}
	kruskal(n,m);
	init(n);
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
