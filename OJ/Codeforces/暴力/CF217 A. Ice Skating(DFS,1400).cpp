#include<bits/stdc++.h>
using namespace std;
int x[1005],y[1005];
bool vis[1005];
void dfs(int now,int n)
{
	vis[now]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&(x[i]==x[now]||y[i]==y[now]))
		{
			dfs(i,n);
		}
	}
}
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,n);
			ans++;//连通块个数
		}
	}
	cout<<ans-1<<endl;
	return 0;
}
