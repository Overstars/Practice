#include<stdio.h>
int dp[100005];
int maxi(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	dp[0]=dp[1]=1;
	for(i=2;i<=n;i++)
		for(j=maxi(0,i-k);j<i;j++)
		{
			dp[i]+=dp[j];
			dp[i]%=100003;
		}
//	for(i=1;i<=n;i++)
//		printf("dp[%d]=%d\n",i,dp[i]);
	printf("%d\n",dp[n]);
	return 0;
}
