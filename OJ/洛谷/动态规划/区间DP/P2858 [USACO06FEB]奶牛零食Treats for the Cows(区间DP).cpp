#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
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
const int maxn=2005;
/*
 *n份零食,一天卖一份,第i份初始价值vi
 *只能卖出最靠边上的
 *第a天售价vi*a
 */
//#define DEBUG
int n,dp[maxn][maxn],v[maxn];
int main()//dp[i][j]
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,ans=-inf;//n份零食
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		dp[i][i]=n*v[i];//第i份零食留到最后卖
	}
	for(int l=2;l<=n;l++)//枚举区间长度,也可表示为天数
	{//从第n天向前dp...
		for(int i=1;i+l-1<=n;i++)//取左面第i个
		{
			int j=i+l-1;//这里就没有中间了...
			int d=n-l+1;//第d天
			dp[i][j]=max(dp[i+1][j]+v[i]*d,dp[i][j-1]+v[j]*d);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
