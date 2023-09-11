#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int a[1000005],dp[2][1000005];//dp[i][j]表示在第j个元素选出前i段的最大和(so,j为i段的结尾元素)
int main()
{
	int m,n,i,j,flag=0;
	while(cin>>m>>n){//在n个数中找出不重合的m段,使总和最大
		flag=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++){
			dp[flag][i]=dp[1-flag][i-1]+a[i];//把这个放前面就AC了？是有比-inf更小的数？防止初始化为0的干扰？
			int maxpre=dp[1-flag][i-1];
//			int maxpre=INT_MIN;
			for(j=i+1;j<=n;j++){//i-1段至少用掉i-1个元素
				maxpre=max(maxpre,dp[1-flag][j-1]);
				dp[flag][j]=max(dp[flag][j-1]+a[j],maxpre+a[j]);
			}//①让a[j]加入到第i段中,②让a[j]单独成为第i段
			flag=1-flag;
		}
		int maxn=dp[1-flag][m];
		for(i=m+1;i<=n;i++)
			maxn=max(maxn,dp[1-flag][i]);
		cout<<maxn<<endl;
	}
	return 0;
}
