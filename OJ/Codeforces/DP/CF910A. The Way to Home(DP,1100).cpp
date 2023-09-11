#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
char s[105];
int dp[105];
int main()
{
	int n,d;
	memset(dp,inf,sizeof(dp));
	dp[0]=dp[1]=0;
	cin>>n>>d>>s+1;
	for(int i=2;i<=n;i++)
		if(s[i]=='1')
			for(int j=i-d;j<i;j++)
			{
				dp[i]=min(dp[i],dp[j]+1);
			}
//	for(int i=1;i<=n;i++)
//		printf("dp[%d]=%d\n",i,dp[i]);
	if(dp[n]<inf)
		cout<<dp[n]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
