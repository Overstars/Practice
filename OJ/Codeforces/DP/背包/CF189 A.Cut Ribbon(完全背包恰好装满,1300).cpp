#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[4005];
int main()
{
	fill(dp,dp+4005,-inf);
	int n,a[3];
	cin>>n;
	for(int i=0;i<3;i++)
		cin>>a[i];
	dp[0]=0;
	for(int i=0;i<3;i++)
		for(int j=a[i];j<=n;j++)
			dp[j]=max(dp[j],dp[j-a[i]]+1);
//	for(int i=0;i<=n;i++)
//		cout<<"dp["<<i<<"]="<<dp[i]<<endl;
	cout<<dp[n]<<endl;
	return 0;
}
/*
 *求容量为n的背包恰好被装满的最小数量
 *
 */
