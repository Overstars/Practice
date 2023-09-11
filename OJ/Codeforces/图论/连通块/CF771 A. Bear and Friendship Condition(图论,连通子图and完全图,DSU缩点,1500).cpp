#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
vector<int> G[maxn];
ll fa[maxn],siz[maxn],deg[maxn];
bool vis[maxn];
int findfa(int x)
{
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
	{
		fa[b]=a;
		siz[a]+=siz[b];
		siz[b]=0;
		deg[a]+=deg[b];
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
		siz[a]=0;
		deg[b]+=deg[a];
	}
	return 1;
}
bool jud(int x)
{
	int fa=findfa(x);
	return siz[fa]*(siz[fa]-1)==deg[fa];
}
void solve(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(auto &v:G[i])
			Merge(i,v);
	}
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	solve(n);
	for(int i=1;i<=n;i++)
		if(siz[i]&&!jud(i))
		{
			cout<<"NO\n";
			exit(0);
		}
	cout<<"YES\n";
	return 0;
}
/*
 *题意:给定无向图,要求若<A,B>且<B,C>则有<A,C>,求判定
 可以看出来图中所有连通块都为完全图
 */
