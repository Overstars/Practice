#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w=0):
		u(u),v(v),w(w){}
};
vector<edge> G;
vector<int> isl[maxn];
int tot=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
bool vis[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++Index]=x;
	vis[x]=1;
	for(auto &v:isl[x])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;
		do{
			belong[stk[Index]]=cnt;
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
int dist[maxn][maxn],clost[maxn],lowcost[maxn];
bool tree[maxn];
ll prim(int n,int s)//这里用不到prim
{
	tree[s]=1;
	for(int i=1;i<=n;i++)
	{
		lowcost[i]=dist[s][i];
		clost[i]=s;
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=inf,t=s;
		for(int j=1;j<=n;j++)
		{
			if(!tree[j]&&lowcost[j]<tmp)
			{
				tmp=lowcost[j];
				t=j;
			}
		}
		if(t==s)
			break;
		tree[t]=1;
		for(int j=1;j<=n;j++)
		{
			if(!tree[j]&&dist[t][j]<lowcost[j])
			{
				lowcost[j]=dist[t][j];
				clost[j]=t;
			}
		}
	}
	ll ret=0;
	for(int i=1;i<=n;i++)
		ret+=lowcost[i];
	return ret;
}
int main()
{
//	freopen("P2941_2.in","r",stdin);
	int n,u,v,w;
	memset(dist,inf,sizeof(dist));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		isl[u].push_back(v);
		isl[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			u=belong[i],v=belong[j];
			dist[u][v]=dist[v][u]=min(dist[u][v],w);
		}
	}
	int ans=inf;
	for(int i=1;i<=cnt;i++)//i作为中心点
	{
		int now=0;
		for(int j=1;j<=cnt;j++)
			now+=dist[i][j];
		ans=min(ans,now);
	}
	cout<<2*ans<<endl;
	return 0;
}
/*
 *题面不清晰...
 *n个节点两两有距离
 *但是其中一些节点构成环,将这些环缩点,保留与其他缩点最小边
 *选择一个作为菊花图的心(题意就是这样...)
 *并没有用到prim...
 */
