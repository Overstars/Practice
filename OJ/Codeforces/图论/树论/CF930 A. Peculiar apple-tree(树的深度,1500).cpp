#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> G[maxn];
int dep[maxn],cnt[maxn];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	cnt[dep[x]]++;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
	}
}
int main()
{
	int n,u,v;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>u;
		G[u].push_back(i);
		G[i].push_back(u);
	}
	int ans=0;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(cnt[i]&1)
			ans++;
	cout<<ans<<endl;
	return 0;
}
