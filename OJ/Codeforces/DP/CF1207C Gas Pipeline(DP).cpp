#include<bits/stdc++.h>
using namespace std;
const long long inf=1ll<<62;
typedef long long ll;
ll dp[200005][2];
char str[200005];
int main()
{
	int t;
	ll n,a,b;//长度n,单位管道价格,单位支柱价格
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>str;
		memset(dp,0,sizeof(dp));
		dp[0][0]=a+b,dp[0][1]=a*2+b;//dp[i][j]表示第i位高度为j的最小花费
		for(ll i=1;i<n;i++)
		{
			if(str[i]=='1')
			{
				dp[i][0]=inf;
				dp[i][1]=min(dp[i-1][1]+a+b*2,dp[i-1][0]+a*2+b*2);
			}
			else
			{
				dp[i][0]=min(dp[i-1][0]+a+b,dp[i-1][1]+a*2+b*2);
				dp[i][1]=min(dp[i-1][0]+a*2+b*2,dp[i-1][1]+a+b*2);
			}
		}
		cout<<dp[n-1][0]+b<<endl;
	}
	return 0;
}
