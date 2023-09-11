#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
const int maxl=31;
int lg[maxn],gene[maxn][maxl],depth[maxn];
int head[maxn],cnt=0,ans=0;
struct node
{
	int u,v,nex;
} G[maxn<<1];
inline void add(int u,int v)
{
	G[++cnt].u=u;
	G[cnt].v=v;
	G[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=head[x];~i;i=G[i].nex)
		if(G[i].v!=fa)
			dfs(G[i].v,x);
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
			x=gene[x][i],y=gene[y][i];
	return gene[x][0];
}
void init(int s,int n)
{
	memset(gene,0,sizeof(gene));
	depth[s]=1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	dfs(s,0);
}
int power[maxn];
void dfs(int x)
{
	for(int i=head[x];~i;i=G[i].nex)
		if(G[i].v!=gene[x][0])
		{
//			cout<<"AAAAAAAAA"<<endl;
			dfs(G[i].v);
			power[x]+=power[G[i].v];
		}
	ans=max(ans,power[x]);
}
int main()
{
//	freopen("P3128.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,x,y;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	init(1,n);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		int a=lca(x,y);
		power[x]++;
		power[y]++;
		power[a]--;
		power[gene[a][0]]--;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
