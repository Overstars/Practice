#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxk=1e7+5;
int head[maxn],tot=0;
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
int n,m,root,sum;
int siz[maxn],maxp[maxn];
bool vis[maxn];
void getrt(int x,int fa)
{//找重心
	siz[x]=1;
	maxp[x]=0;
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
int tmp[maxn],dist[maxn],cnt=0;
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
int q[105];
bool jud[maxk],ans[105];
queue<int> QwQ;
void cal(int x)
{
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		cnt=0;
		dist[v]=e[i].w;
		getdist(v,x);
		for(int j=1;j<=cnt;j++)//遍历得到的边
			for(int k=1;k<=m;k++)//遍历问题
				if(q[k]>=tmp[j])
					ans[k]|=jud[q[k]-tmp[j]];
		for(int j=1;j<=cnt;j++)
		{
			jud[tmp[j]]=1;
			QwQ.push(tmp[j]);
		}
	}
	while(!QwQ.empty())
	{
		jud[QwQ.front()]=0;
		QwQ.pop();
	}
}
void divide(int x)
{//分治
	jud[0]=vis[x]=1;//标记删除
	cal(x);//计算路径
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
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=m;i++)
		cin>>q[i];
	maxp[0]=sum=n;
	getrt(1,0);
	getrt(root,0);
	divide(root);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"AYE":"NAY")<<'\n';
	return 0;
}
