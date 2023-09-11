#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100005;
vector<int>G[maxn];
int tot=0,Index=0,ans=0,cnt=0;
int dfn[maxn],low[maxn],stk[maxn];
bool vis[maxn],isc[maxn];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	int child=0;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(x==fa)
				child++;
			if(x!=fa&&low[v]>=dfn[x])
			{
				isc[x]=1;
			}
		}
		else if(v!=fa)//¢Ú
			low[x]=min(low[x],dfn[v]);
	}
	if(x==fa&&child>=2)
	{
		isc[x]=1;
	}
}
void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	vis[x]=1;
	stk[++Index]=x;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(!dfn[v])
		{
			tarjan(v,x);
			if(low[v]>=dfn[x]&&x!=fa)//¢Ù
			{
				isc[x]=1;
			}
			low[x]=min(low[x],low[v]);
		}
		else if(dfn[x]>dfn[v]&&v!=fa)//¢Ú
			low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;
		do{
			vis[stk[Index]]=0;
//			belong[stk[Index]]=cnt;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
//#define DEBUG
int main()
{
	#ifdef DEBUG
	freopen("P3388.in","r",stdin);
	#endif // DEBUG
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	memset(isc,0,sizeof(isc));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	for(int i=1;i<=n;i++)
//		if(!dfn[i])
//			tarjan(i,i);
//	cout<<ans<<endl;
//	for(int i=1;i<=n;i++)
//		if(isc[i])
//			cout<<i<<' ';
//	cout<<endl;
//	memset(vis,0,sizeof(vis));
//	memset(dfn,0,sizeof(dfn));
//	memset(low,0,sizeof(low));
//	memset(isc,0,sizeof(isc));
//	ans=0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i,i);
	for(int i=1;i<=n;i++)
		if(isc[i])
			ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(isc[i])
			cout<<i<<' ';
	return 0;
}
