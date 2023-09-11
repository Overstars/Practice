#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int val[maxn],n,m,ans=0;
vector<int> G[maxn];
void dfs(int x,int fa,int cnt)
{
	if(val[x])
		cnt++;
	else
		cnt=0;
	if(cnt>m)
		return;
	if(G[x].size()==1&&G[x][0]==fa)
	{
		ans++;
		return;
	}
//	printf("%d has been visted.\n",x);
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x,cnt);
	}
}
int main()
{
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
