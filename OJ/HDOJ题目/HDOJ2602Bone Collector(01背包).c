/*
Problem Description
Many years ago , in Teddy’s hometown there was a man who was called “Bone Collector”. This man like to collect varies of bones , such as dog’s , 
cow’s , also he went to the grave …The bone collector had a big bag with a volume of V ,and along his trip of collecting there are a lot of bones , 
obviously , different bone has different value and different volume, now given the each bone’s value along his trip , can you calculate out 
the maximum of the total value the bone collector can get ?
Input
The first line contain a integer T , the number of cases.
Followed by T cases,each case three lines,the first line contain two integer N,V,(N<=1000,V<=1000)representing the number of bones and the volume of his
bag.And the second line contain N integers representing the value of each bone.The third line contain N integers representing the volume of each bone.
Output
One integer per line representing the maximum of the total value (this number will be less than 231)*/
#include<stdio.h>
long max(long a,long b);
long dp[1005][1005]={0},value[1005],volum[1005];
int main(void)
{
	int t;
	int n,v;//分别为组数，当前组的骨头数量，背包的体积
	scanf("%d",&t);
	while(t-->0){
		scanf("%d %d",&n,&v);
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%ld",&value[i]);//第i件的价值 
		for(i=1;i<=n;i++)
			scanf("%ld",&volum[i]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)//注意：存在v=0,volum=0,value>0的情况 
			for(j=0;j<=v;j++)//表示前i根骨头，体积v的最优解 
				if(j<volum[i]) dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-volum[i]]+value[i]);
		printf("%ld\n",dp[n][v]);
		}
	return 0;
}
long max(long a,long b)
{
	return (a>b)?a:b;
}
