#include<bits/stdc++.h>
using namespace std;
const int maxn=10000007,mod=1000000007;
int dp[maxn][5];
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=4;i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=4;k++)
			{
				if(k==j)
					continue;
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			}
		}
	cout<<dp[n][1]<<endl;
	return 0;
}
