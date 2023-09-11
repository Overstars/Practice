#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1005;
const int maxl=30;
int depth[maxn],gene[maxn][maxl],lg[maxn];
vector<int> G[maxn];
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=fa)
			dfs(G[x][i],x);
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
void init(int s)
{
	memset(gene,0,sizeof(gene));
	depth[s]=0;
	dfs(s,0);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	for(int i=1;i<1005;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==1);
	int t,n,m,q;
	cin>>t;
	for(int i=1;i<=t;i++)//t组数据
	{
		cin>>n;
		for(int i=0;i<=n;i++)
			G[i].clear();
		for(int j=1;j<=n;j++)
		{
			cin>>m;//j号节点有m个子节点
			while(m--)
			{
				int v;
				cin>>v;
				G[j].push_back(v);
				G[v].push_back(j);
			}
		}
		init(1);
		cin>>q;
		cout<<"Case "<<i<<":"<<endl;
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<lca(u,v)<<endl;
		}
	}
	return 0;
}
