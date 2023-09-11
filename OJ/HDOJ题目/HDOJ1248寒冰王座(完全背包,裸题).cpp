#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[10005],cost[3]={150,200,350};//面值为i的最大消费
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)
			dp[i]=0;
		for(i=0;i<3;i++)
		{
			for(j=cost[i];j<=n;j++)
			{
				dp[j]=max(dp[j],dp[j-cost[i]]+cost[i]);
			}
		}
		cout<<n-dp[n]<<endl;
	}
	return 0;
}
