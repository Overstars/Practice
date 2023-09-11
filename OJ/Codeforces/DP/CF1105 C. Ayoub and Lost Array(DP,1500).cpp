#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[200005][3];//i位和的余数为0,1,2
int main()
{
	ll n,l,r,a[3];
	cin>>n>>l>>r;
	if((r-l+1)%3==0)
		a[0]=a[1]=a[2]=(r-l+1)/3;
	else if((r-l+1)%3==1)
	{
		a[l%3]=(r-l+1)/3+1;//分到最多
		a[(l+1)%3]=a[(l+2)%3]=(r-l+1)/3;
	}
	else{
		a[l%3]=a[(l+1)%3]=(r-l+1)/3+1;//分到最多
		a[(l+2)%3]=(r-l+1)/3;
	}
	for(int i=0;i<3;i++)
		dp[1][i]=a[i];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][k]*a[(3-k+j)%3])%mod;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<3;j++)
//			printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	cout<<dp[n][0]<<endl;
	return 0;
}
