#include<bits/stdc++.h>
using namespace std;
const int maxn=1250;
int dp[maxn][maxn];//第i秒速度j行驶最大距离
int main()
{
	int v1,v2,t,d,ans=0;
	cin>>v1>>v2>>t>>d;
	dp[1][v1]=v1;
	int lim=v1;
	for(int i=2;i<=t;i++)
	{
		lim+=d;
		for(int j=1;j<=lim;j++)
		{
			for(int k=max(-d,1-j);k<=d;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j+k]+j);
			}
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	cout<<dp[t][v2]<<endl;
	return 0;
}
