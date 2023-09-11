#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct edge
{
	int v,nex;
} e[maxn<<1];
double dp[maxn];
int head[maxn],cnt,deg[maxn];
inline add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		deg[x]++;//统计出度
		dfs(v,x);
	}
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;//回溯,计算期望
		dp[x]+=(double)(1.0/deg[x])*(dp[v]+1);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<dp[1]<<endl;
	return 0;
}
