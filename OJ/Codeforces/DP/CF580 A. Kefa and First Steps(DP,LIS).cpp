#include<bits/stdc++.h>
using namespace std;
int a[100005],dp[100005];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1]=ans=1;
	for(int i=2;i<=n;i++)
		if(a[i]>=a[i-1])
		{
			dp[i]=dp[i-1]+1;
			ans=max(ans,dp[i]);
		}
		else
			dp[i]=1;
	cout<<ans<<endl;
	return 0;
}
