#include<bits/stdc++.h>
using namespace std;
const int lim=32800;
int dp[lim][5];
int main()
{
	int t,n;
	dp[0][0]=1;//dp[i][j]为i的j个数的表示方法有多少种
//	for(int i=1;i*i<lim;i++)
//		dp[i][1]=1;
	for(int i=1;i*i<lim;i++)//枚举平方数
	{
//		dp[i*i][1]=1;
		for(int j=i*i;j<lim;j++)
		{
			for(int k=1;k<=4;k++)
				dp[j][k]+=dp[j-i*i][k-1];
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=4;i++)
			ans+=dp[n][i];
		cout<<ans<<endl;
	}
	return 0;
}
