#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],dp[maxn][4];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=3;i++)
		dp[1][i]=1;
	int ans=1;
	for(int i=2;i<=n;i++)//dp1表示以第i个数字结尾时,各装态最长串长度
	{
		if(a[i-1]==a[i])
		{
			dp[i][1]=max(dp[i-1][2],dp[i-1][1])+1;//j==1,最大值比当前大
			dp[i][2]=dp[i-1][2]+1;//j==2,全部一样
			dp[i][3]=max(dp[i-1][2],dp[i-1][3])+1;//j==3,最小值比当前小
		}
		else if(a[i-1]<a[i])//比上一个大
		{
			dp[i][2]=dp[i][1]=1;
			dp[i][3]=max(dp[i-1][2],dp[i-1][1])+1;
		}
		else{//比上一个小
			dp[i][3]=dp[i][2]=1;
			dp[i][1]=max(dp[i-1][2],dp[i-1][3])+1;
		}
		ans=max(ans,max(dp[i][1],max(dp[i][2],dp[i][3])));
	}
	cout<<ans<<endl;
	return 0;
}
