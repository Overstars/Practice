#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
long long a[maxn],dp[maxn];//dp[i]为吃i颗糖的最小甜度
int main()
{
	int n,m;
	cin>>n>>m;//一天最多吃m块
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=1;i<=m;i++)
		dp[i]=dp[i-1]+a[i];
	sum=dp[m];
	for(int i=m+1;i<=n;i++)
	{
		sum+=a[i];
		dp[i]=dp[i-m]+sum;
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<' ';
	return 0;
}
