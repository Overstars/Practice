#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int p[maxn];
bool vis[maxn];
void dfs(int x)
{
	if(vis[x])
	{
		cout<<x<<' ';
		return;
	}
	vis[x]=1;
	dfs(p[x]);
	vis[x]=0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		dfs(i);
	return 0;
}
