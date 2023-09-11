#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int t[105],dp[2][105];//dp[0][i]表示以i结束的LIS长度
int main()//dp[1][i]表示以i开始的LDS长度
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif // DEBUG
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		dp[0][i]=dp[1][i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(t[j]<t[i])
				dp[0][i]=max(dp[0][i],dp[0][j]+1);
		}
	}
	for(int i=n-1;i>=1;i--)//反向LIS
	{
		for(int j=n;j>i;j--)
		{
			if(t[j]<t[i])
				dp[1][i]=max(dp[1][i],dp[1][j]+1);
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<dp[0][i]<<",";
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[0][i]+dp[1][i]-1);
	cout<<n-ans<<endl;
	return 0;
}
