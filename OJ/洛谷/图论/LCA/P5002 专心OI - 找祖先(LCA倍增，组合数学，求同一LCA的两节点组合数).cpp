#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int maxl=30;
const int mod=1000000009;
int head[maxn],gene[maxn][maxl],depth[maxn],nodes[maxn],lg[maxn],cnt=0;
struct nodes
{
	int v,nex;
} edges[maxn<<3];
inline void add(int u,int v)
{
	edges[++cnt].nex=head[u];
	edges[cnt].v=v;
	head[u]=cnt;
}
int ans[maxn];
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	nodes[x]=1;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=head[x];~i;i=edges[i].nex)
		if(edges[i].v!=fa)
		{
			dfs(edges[i].v,x);
			ans[x]+=nodes[x]*nodes[edges[i].v]*2;//新加入的子树与之前存在的该节点的子树进行组合
			nodes[x]+=nodes[edges[i].v];
		}
//	for(int i=head[x];~i;i=edges[i].nex)
//		ans[x]+=nodes[edges[i].v]*2;//
	ans[x]++;//自己和自己,答案+1
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
inline void init(int s)
{
	memset(gene,0,sizeof(gene));
	memset(nodes,0,sizeof(nodes));
	memset(ans,0,sizeof(ans));
	depth[s]=1;
	dfs(s,0);
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,r,m,u,v,p;
	cin>>n>>r>>m;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	init(r);
	for(int i=0;i<m;i++)
	{
		cin>>p;//树上以p为LCA的组合有多少对
		cout<<ans[p]<<endl;
	}
	return 0;
}
