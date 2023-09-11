#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll x[maxn],h[maxn],dp[maxn][3];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>h[i];
	}
	x[n+1]=inf;
	//dp[i][j]第i棵树,0不砍,1左倒,2右倒最大数量
	dp[1][1]=1;
	if(x[1]+h[1]<x[2])
		dp[1][2]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<3;j++)//这个不倒
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
		if(x[i-1]+h[i-1]<x[i]-h[i])//上一个可以右倒
			dp[i][1]=max(dp[i-1][2],max(dp[i-1][0],dp[i-1][1]))+1;
		else if(x[i]-h[i]>x[i-1])//这个左倒,但上一个不能右倒
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
		else//不倒
			dp[i][1]=max(dp[i-1][0],max(dp[i-1][2],dp[i-1][1]));
		if(x[i]+h[i]<x[i+1])//可以右倒
			dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+1;
		else//不倒
			dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
	}
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<3;j++)
//			printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	cout<<max(dp[n][1],dp[n][2])<<endl;
	return 0;
}
