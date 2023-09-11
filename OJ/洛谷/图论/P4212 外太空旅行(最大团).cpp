#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int G[maxn][maxn],tmp[maxn][maxn];//tmp[i][j]搜到第i层
int n,ans,tot,f[maxn];
bool dfs(int dep,int num)//深度(团大小),备选集合
{
	if(num==0)
	{
		if(dep>ans)
		{
			ans=dep;
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=num;i++)
	{
		if(dep+num-i+1<=ans)
			return 0;
		int v=tmp[dep][i];
		if(dep+f[v]<=ans)
			return 0;
		int cnt=0;
		for(int j=i+1;j<=num;j++)
		{
			int vv=tmp[dep][j];
			if(G[v][vv])
				tmp[dep+1][++cnt]=vv;
		}
		if(dfs(dep+1,cnt))
			return 1;
	}
	return 0;
}
int maxClique(int n)
{
	if(n==0)
		return 0;
	memset(f,0,sizeof(f));
	f[n]=ans=1;
	for(int i=n-1;i>=1;i--)
	{
		tot=0;
		for(int j=i+1;j<=n;j++)
			if(G[i][j])
				tmp[1][++tot]=j;
		dfs(1,tot);
		f[i]=ans;
	}
	return ans;
}
int main()
{//回溯法求最大团
	scanf("%d",&n);
	int u,v;
	while(~scanf("%d%d",&u,&v))
	{
		G[u][v]=G[v][u]=1;
	}
	printf("%d\n",maxClique(n));
	return 0;
}
/*
 *求最大团裸题
 *模板来源:https://www.songhn.com/maxclique/
 */

