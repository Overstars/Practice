#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dp[maxn],dp2[maxn];
char s[maxn];
int main()
{
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)//dp[i]为大写字母代价
		dp[i]=dp[i-1]+(islower(s[i])?1:0);
	for(int i=n;i>0;i--)//dp2[i]改为小写字母代价
		dp2[i]=dp2[i+1]+(isupper(s[i])?1:0);
//	for(int i=1;i<=n;i++)
//		printf("A[%d]=%d,B[%d]=%d\n",i,dp[i],i,dp2[i]);
	int ans=dp[n];
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i-1]+dp2[i]);
	cout<<ans<<endl;
	return 0;
}
