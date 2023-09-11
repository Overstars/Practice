#include<bits/stdc++.h>
using namespace std;
const int maxn=20005;
int n,tot,head[maxn];
struct edge
{
	int v,w,nex;
} e[maxn<<1];
inline void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot;
}
int root,sum,siz[maxn],maxp[maxn];
bool vis[maxn];
void getrt(int x,int fa)
{
	siz[x]=1,maxp[x]=0;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		getrt(v,x);
		siz[x]+=siz[v];
		maxp[x]=max(maxp[x],siz[v]);
	}
	maxp[x]=max(maxp[x],sum-siz[x]);
	if(maxp[x]<maxp[root])
		root=x;
}
int cnt,tmp[maxn],dist[maxn],ans=0;
void getdist(int x,int fa)
{
	tmp[++cnt]=dist[x];
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		dist[v]=dist[x]+e[i].w;
		getdist(v,x);
	}
}
int ret[3];//0,1,2
void solve(int x)
{
//	printf("root=%d\n",x);
	ans++;//单个节点
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		dist[v]=e[i].w;
		cnt=0;
		getdist(v,x);
		for(int j=1;j<=cnt;j++)
		{
			int now=tmp[j]%3;
			if(now==0)
			{
				ans+=2;//单独一个就可以
				ans+=ret[0]*2;//正着来一次,反着来一次
			}
			else if(now==1)
				ans+=ret[2]*2;
			else
				ans+=ret[1]*2;
		}
		for(int j=1;j<=cnt;j++)
		{
			ret[tmp[j]%3]++;
//			printf("%d已加入,ret[%d]=%d\n",j,tmp[j]%3,ret[tmp[j]%3]);
		}
	}
	memset(ret,0,sizeof(ret));
//	printf("\n****ans=%d***\n",ans);
}
void divide(int x)
{
	vis[x]=1;
	solve(x);
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		maxp[root=0]=sum=siz[v];
		getrt(v,0);
		getrt(root,0);
		divide(root);
	}
}
int main()
{
	int u,v,w;
	memset(head,-1,sizeof(head));
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	maxp[0]=sum=n;
	getrt(1,0);
	getrt(root,0);
	divide(root);
	int total=n*n;
	int g=__gcd(ans,total);
//	g=1;
	cout<<ans/g<<'/'<<total/g<<endl;
	return 0;
}
