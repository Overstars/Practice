#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[105],dp[3][105];//dp[i][j]第j天做第i种活动
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];//可以休息/健身/比赛,健身/比赛不可连续
	memset(dp,inf,sizeof(dp));
	dp[0][0]=dp[1][0]=dp[2][0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)//只能休息
		{
			for(int j=0;j<3;j++)
				dp[0][i]=min(dp[0][i],dp[j][i-1]+1);
		}
		else if(a[i]==1)//健身/休息
		{
			dp[1][i]=min(dp[0][i-1],dp[2][i-1]);
			for(int j=0;j<3;j++)
				dp[0][i]=min(dp[0][i],dp[j][i-1]+1);
		}
		else if(a[i]==2)//比赛/休息
		{
			dp[2][i]=min(dp[0][i-1],dp[1][i-1]);
			for(int j=0;j<3;j++)//休息
				dp[0][i]=min(dp[0][i],dp[j][i-1]+1);
		}
		else{//都可
			dp[1][i]=min(dp[0][i-1],dp[2][i-1]);//健身
			dp[2][i]=min(dp[0][i-1],dp[1][i-1]);//比赛
			for(int j=0;j<3;j++)//休息
				dp[0][i]=min(dp[0][i],dp[j][i-1]+1);
		}
	}
	cout<<min(dp[0][n],min(dp[1][n],dp[2][n]))<<endl;
	return 0;
}
