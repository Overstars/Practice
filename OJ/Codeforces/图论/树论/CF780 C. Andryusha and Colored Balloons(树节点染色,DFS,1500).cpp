#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>G[maxn];
int n,ans=0,col[maxn];
bool vis[maxn];
void dfs(int x,int fa)
{
	int no=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		while(no==col[x]||no==col[fa])
			no++;
		col[v]=no++;//子节点之间颜色不同
		ans=max(ans,col[v]);
	}
	for(auto &v:G[x])
		if(v!=fa)
			dfs(v,x);
}
int main()
{
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	col[1]=1;
	dfs(1,0);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<col[i]<<' ';
	return 0;
}
/*
 *给你n个节点的树,进行染色,相邻三个节点颜色不同
 *问最小所需颜色数
 *emm,还真就暴力...干就完了
 */
