#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2005,inf=0x3f3f3f3f,mod=1e9+7;
ll dp[maxn][maxn];//dp[i][j]表示第i位以j结尾的种类数
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		dp[1][i]=1;//1~n
	for(int i=2;i<=k;i++)//k个
	{
		for(int j=1;j<=n;j++)//
		{
			for(int v=n/j;v>0;v--)
				dp[i][j*v]=(dp[i][j*v]+dp[i-1][j])%mod;
//			for(int v=j;v<=n;v+=j)
//			{
//				dp[i][v]=(dp[i][v]+dp[i-1][j])%mod;
//			}
		}
	}
//	for(int i=1;i<=k;i++)
//		for(int j=1;j<=n;j++)
//			printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[k][i])%mod;
	cout<<ans<<endl;
	return 0;
}
