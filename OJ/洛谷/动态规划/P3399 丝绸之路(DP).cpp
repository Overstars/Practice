#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn=1005;
int d[maxn],c[maxn],dp[maxn][maxn];
signed main()
{
//	freopen("P3399_3.in","r",stdin);
	int n,m;//n城市,m天到达
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	memset(dp,inf,sizeof(dp));
//	fill(dp,dp+maxn*maxn,inf);
	for(int i=0;i<=m;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)//第j天到达第i座城最小疲惫值
		{//由第j-1天休息或者j-1天由上一个城市走过来
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+d[i]*c[j]);
		}
	}
	int ans=inf;
	for(int i=1;i<=m;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
