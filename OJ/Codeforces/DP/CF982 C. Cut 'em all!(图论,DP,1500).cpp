#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
vector<int> G[maxn];
int dp[maxn],siz[maxn];
void dfs(int x,int fa)
{//dp[x]表示x为根子树删除最多边数
	siz[x]=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[v]%2==0)//偶-偶=偶,
			dp[x]+=dp[v]+1;
		else
			dp[x]+=dp[v];
	}
}
int main()
{
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n&1)
	{
		cout<<"-1\n";
		exit(0);
	}
	dfs(1,0);
	cout<<dp[1]<<endl;
	return 0;
}
