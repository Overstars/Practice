#include<bits/stdc++.h>
using namespace std;
int a[105],dp[105][105];
int main()
{
	int n;
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])
			flag=0;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=a[i];//dp[i][j]统计i到j的1有多少个
		for(int j=i+1;j<=n;j++)//
		{
			dp[i][j]=dp[i][j-1]+a[j];
		}
	}
	int ans=1-dp[1][1];//必须做一次更改
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=max(ans,dp[1][n]-2*dp[i][j]+(j-i+1));
	cout<<ans<<endl;
	return 0;
}
