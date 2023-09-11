#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long a[2][maxn],dp[2][maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		dp[1][i]=max(dp[0][i-1]+a[1][i],dp[1][i-1]);
		dp[0][i]=max(dp[1][i-1]+a[0][i],dp[0][i-1]);
	}
	cout<<max(dp[0][n],dp[1][n])<<endl;
	return 0;
}
