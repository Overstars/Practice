#include<bits/stdc++.h>
using namespace std;
int a[105][105],dp[105][105];
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				dp[i][j]=max(dp[i][j],1);
			}
			if(a[i][j]==1&&dp[i-1][j-1]&&dp[i-1][j]&&dp[i][j-1])
			{
				dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
				dp[i][j]=min(dp[i][j],min(i,j));
			}
			ans=max(ans,dp[i][j]);
		}
	}
//	cout<<"*****\n";
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<dp[i][j]<<(j==m?'\n':' ');
	cout<<ans<<endl;
//	cout<<dp[n][m]<<endl;
	return 0;
}
