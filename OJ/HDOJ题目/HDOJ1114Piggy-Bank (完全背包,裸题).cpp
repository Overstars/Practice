#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
struct coin
{
	long long p,w;
} a[505];
long long dp[10005];//重量为i的钱最小价值
int main()
{
	int t,i,j,e,f;
	cin>>t;
	while(t--){
		cin>>e>>f;
		int weight=f-e;//钱币重量
		int n;//硬币种类
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%lld%lld",&a[i].p,&a[i].w);
		memset(dp,inf,sizeof(dp));
		dp[0]=0;
		for(i=0;i<n;i++)//每个硬币
		{
			for(j=a[i].w;j<=weight;j++)
			{
				dp[j]=min(dp[j],dp[j-a[i].w]+a[i].p);
			}
		}
		if(dp[weight]<inf)
			printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[weight]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}
