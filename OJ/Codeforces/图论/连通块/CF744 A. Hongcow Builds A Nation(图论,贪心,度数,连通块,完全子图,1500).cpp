#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
vector<int> G[maxn];
ll fa[maxn],siz[maxn],deg[maxn];
bool c[maxn],vis[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
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
		deg[a]+=deg[b];
		siz[a]+=siz[b];
		c[a]|=c[b];
	}
	else{
		fa[a]=b;
		deg[b]+=deg[a];
		siz[b]+=siz[a];
		c[b]|=c[a];
	}
	return 1;
}
int main()
{
	int n,m,k,u,v;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		c[u]=1;//警察局
	}
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{//完全图边数=n(n-1)/2;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	for(int u=1;u<=n;u++)//完全读入后进行合并
		for(auto &v:G[u])
			Merge(u,v);//连通
	ll maxc=0,ans=0;//最大的一个有警察连通块编号
	for(int i=1;i<=n;i++)
	{
		ll now=findfa(i);
		if(c[now]&&siz[now]>siz[maxc])
			maxc=now;
	}
	ans+=siz[maxc]*(siz[maxc]-1)/2-deg[maxc]/2;
	for(int i=1;i<=n;i++)
	{
		ll now=findfa(i);
		if(vis[now]||now==maxc)
			continue;
		ans+=siz[now]*(siz[now]-1)/2-deg[now]/2;//变为完全子图
		if(!c[now])//和最大的联通
		{
			ans+=siz[maxc]*siz[now];
			siz[maxc]+=siz[now];
		}
		vis[now]=1;//连通块已访问
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *题意,稳定图定义:无重边,无自环,一个联通块内只有一个警察局
 *k个警察局编号,初始图保证稳定
 *保证图稳定情况下,最多加边数
 */
