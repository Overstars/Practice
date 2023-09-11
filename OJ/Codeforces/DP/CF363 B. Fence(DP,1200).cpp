#include<bits/stdc++.h>
using namespace std;
int a[150005],dp[150005];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];//前缀和
	}
	int Min=0x3f3f3f3f;
	for(int i=k;i<=n;i++)
	{
		if(a[i]-a[i-k]<Min)
		{
			dp[i]=i-k+1;
			Min=a[i]-a[i-k];
		}
		else
			dp[i]=dp[i-1];
	}
	cout<<dp[n]<<endl;
	return 0;
}
