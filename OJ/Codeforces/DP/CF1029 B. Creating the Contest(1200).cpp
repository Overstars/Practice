#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int a[200005],dp[200005];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];//最难的题目难度不超过最简单的两倍
	dp[1]=1;//dp[i]表示以i号题目为最难题目最大数量
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1]*2)//
		{
			dp[i]=dp[i-1]+1;
//			printf("1:dp[%d]=%d\n",i,dp[i]);
		}
		else{
			dp[i]=1;
//			int pos=upper_bound(a+1,a+i+1,a[i]/2+a[i]%2)-a;
//			dp[i]=i-pos+1;
//			for(int j=i-dp[i-1];j<=i;j++)
//				if(a[i]<=2*a[j])
//				{
//					dp[i]=i-j+1;
//					break;
//				}
//			printf("2:dp[%d]=%d\n",i,dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
