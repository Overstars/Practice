#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005,inf=0x3f3f3f3f;
int a[maxn],dp[maxn][2];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]&1)
		dp[1][1]=a[1];
	else
	{
		dp[1][0]=max(a[1],0);
		dp[1][1]=-inf;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]&1)
		{
			dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
		}
		else
		{
			dp[i][1]=max(dp[i-1][1],dp[i-1][1]+a[i]);
			dp[i][0]=max(dp[i-1][0],dp[i-1][0]+a[i]);
		}
	}
	cout<<dp[n][1]<<endl;
	return 0;
}
