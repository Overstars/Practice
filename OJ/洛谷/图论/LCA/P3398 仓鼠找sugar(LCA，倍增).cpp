#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100005;
const int maxl=30;
int gene[maxn][maxl],depth[maxn];
int lg[maxn];
vector<int> G[maxn];
void dfs(int x,int fa)
{
//	cout<<x<<" has been visited"<<endl;
	gene[x][0]=fa;
	depth[x]=depth[fa]+1;
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
int init(int s)
{
	memset(gene,0,sizeof(gene));
	depth[s]=0;
	dfs(s,0);
}
int dist(int x,int y)
{
	int a=lca(x,y);
	return int(abs(depth[x]-depth[a])+abs(depth[y]-depth[a]));
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("P3398.in","r",stdin);
//		freopen("P3398.ans", "w", stdout);
	#endif
	int n,q,u,v;
	cin>>n>>q;
	for(int i=1;i<=n;i++)//lg数组应该这么写
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(1);
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		u=lca(a,b);
		v=lca(c,d);
//		bool flag=0;
//		if(depth[u]>=depth[v])//
//		{
//			if(lca(u,c)==u||lca(u,d)==u)
//				flag=1;
//		}
//		if(depth[v]>=depth[u]&&!flag)
//		{
//			if(lca(v,a)==v||lca(v,b)==v)
//				flag=1;
//		}
		if(dist(u,c)+dist(u,d)==dist(c,d)||dist(v,a)+dist(v,b)==dist(a,b))//u是否在c->d上或v是否在a->b上
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
