#include<bits/stdc++.h>
using namespace std;
int dp[70];
int main()
{
	int n;
	cin>>n;
	dp[1]=0,dp[2]=2;
	for(int i=3;i<=n;i++)
		if(i&1)
			dp[i]=0;
		else
			dp[i]=dp[i-2]*2;
	cout<<dp[n]<<endl;
	return 0;
}
