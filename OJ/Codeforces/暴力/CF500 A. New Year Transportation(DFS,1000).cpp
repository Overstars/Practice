#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int a[maxn];
bool vis[maxn];
bool dfs(int x,int t)
{
	if(x==t)
		return 1;
	if(vis[x])
		return 0;
	vis[x]=1;
	dfs(x+a[x],t);
}
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1;i<n;i++)
		cin>>a[i];
	if(dfs(1,t))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
