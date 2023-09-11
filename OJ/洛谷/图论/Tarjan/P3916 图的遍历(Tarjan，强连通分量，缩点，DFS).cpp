#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
vector<int> G[maxn];
int tot=0,cnt=0,Index=0;
int dfn[maxn],low[maxn],belong[maxn],stk[maxn];
int ans[maxn];
bool vis[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++Index]=x;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(!dfn[G[x][i]])
		{
			tarjan(G[x][i]);
			low[x]=min(low[x],low[G[x][i]]);
		}
		else if(vis[G[x][i]])
			low[x]=min(low[x],dfn[G[x][i]]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;
		do{
			belong[stk[Index]]=cnt;
			ans[cnt]=max(ans[cnt],stk[Index]);
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
void dfs(int x)
{
	if(vis[x])
		return;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		dfs(G[x][i]);
		ans[belong[x]]=max(ans[belong[x]],ans[belong[G[x][i]]]);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	memset(vis,0,sizeof(vis));//重新利用
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);//搜索强连通分量
//	for(int i=n;i>0;i--)
//	{
//		for(int j=0;j<G[i].size();j++)
//		{
//			if(belong[i]!=belong[G[i][j]])
//			{
//				ans[belong[i]]=max(ans[belong[i]],ans[belong[G[i][j]]]);
//			}
//		}
//	}
	for(int i=1;i<=n;i++)
		cout<<ans[belong[i]]<<' ';
	return 0;
}
