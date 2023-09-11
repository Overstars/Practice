#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int s[maxn][30],dp[maxn][30];
int main()
{
	int n,q,l,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
//		dp[i][0]=s[i];
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			s[i][j]=s[i][j-1]+s[i+(1<<j-1)][j-1];
			dp[i][j]=dp[i][j-1]+dp[i+(1<<j-1)][j-1];
			if(s[i][j]>=10)
			{
				s[i][j]-=10;
				dp[i][j]++;
			}
//			printf("s[%d][%d]=%d,dp[%d][%d]=%d\n",i,j,s[i][j],i,j,dp[i][j]);
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		int k=log2(r-l+1);
//		printf("k=%d\n",k);
		int ans=dp[l][k]+dp[l+(1<<k)][(int)log2(r-l-(1<<k))];
//		printf("ans=%d,dp[%d][%d]=%d+dp[%d][%d]=%d\n",ans,l,k,dp[l][k],l+(1<<k),(int)log2(r-l-(1<<k)+1),dp[l+(1<<k)][(int)log2(r-l-(1<<k)+1)]);
		if(l+(1<<k)<r&&s[l][k]+s[l+(1<<k)][(int)log2(r-l-(1<<k)+1)]>=10)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}
