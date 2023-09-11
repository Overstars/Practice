#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int a[100005][11];
long long dp[100005][11];
long long llmax3(long long a,long long b,long long c)
{
	return (a>b?a:b)>c?a>b?a:b:c;
}
int main()
{
	int n,i,j,time;
	while(cin>>n&&n){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		time=0;
		for(i=0;i<n;i++){
			int t,loc;
			scanf("%d%d",&loc,&t);
			a[t][loc]++;
			time=max(time,t);
		}
		for(int i=1;i<5;i++)//0s位于5，1s时只能取到4、5、6位置
			for(int j=0;j<5-i;j++)
				a[i][j]=0,a[i][10-j]=0;
		for(i=1;i<=time;i++)
		{
			for(j=0;j<11;j++)
			{
				if(j>0&&j<10)
					dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
//					dp[i][j]=llmax3(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
				else if(j==0)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]);
				else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
				dp[i][j]+=a[i][j];
			}
		}
		long long maxn=0;
		for(i=0;i<11;i++)
			maxn=max(maxn,dp[time][i]);
		cout<<maxn<<endl;
	}
	return 0;
}

