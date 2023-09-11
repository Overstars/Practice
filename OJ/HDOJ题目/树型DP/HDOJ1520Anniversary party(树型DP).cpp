#include<bits/stdc++.h>
using namespace std;
const int maxn=6005;
int head[maxn],cnt=0,val[maxn],dp[maxn][2];
struct edge
{
	int v,nex;
} e[maxn<<2];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	dp[x][0]=0;
	dp[x][1]=val[x];
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,x);
		dp[x][0]+=max(dp[v][0],dp[v][1]);
		dp[x][1]+=max(0,dp[v][0]);
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
		}
		int u,v;
		while(scanf("%d%d",&u,&v)&&u&&v)
		{
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		printf("%d\n",max(dp[1][1],dp[1][0]));
	}
	return 0;
}
