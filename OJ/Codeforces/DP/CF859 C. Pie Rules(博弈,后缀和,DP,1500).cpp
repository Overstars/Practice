#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int arr[maxn],sum[maxn],dp[maxn];
int main()//正着dp不符合无后效性
{//dp[i]表示当前在选的人,一直到游戏结束可获得的最大收益
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]+arr[i];//后缀和
		dp[i]=max(dp[i+1],sum[i]-dp[i+1]);//给对方/给自己
	}
	cout<<sum[1]-dp[1]<<' '<<dp[1]<<endl;
	return 0;
}
