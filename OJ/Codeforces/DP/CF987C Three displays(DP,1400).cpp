#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=3005,inf=0x3f3f3f3f;
int s[maxn],c[maxn],dp[maxn][4];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int ans=inf;
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=c[i];
		for(int j=1;j<i;j++)
		{
			if(s[j]<s[i])
			{
				dp[i][2]=min(dp[i][2],dp[j][1]+c[i]);
				dp[i][3]=min(dp[i][3],dp[j][2]+c[i]);
			}
		}
//		for(int j=1;j<=3;j++)
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		ans=min(ans,dp[i][3]);
	}
	cout<<(ans<inf?ans:-1)<<endl;
	return 0;
}
//signed main()
//{
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>s[i];
//	for(int i=1;i<=n;i++)
//		cin>>c[i];
//	int ans=INT_MAX;
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++)
//		{
//			if(s[i]<s[j])
//			{
//				for(int k=j+1;k<=n;k++)
//					if(s[j]<s[k])
//						ans=min(ans,c[i]+c[j]+c[k]);
//			}
//			else
//				continue;
//		}
//	cout<<(ans<inf?ans:-1)<<endl;
//	return 0;
//}
