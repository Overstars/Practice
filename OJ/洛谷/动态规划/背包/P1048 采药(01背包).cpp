#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int v[105],w[105],dp[105][1005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=t;j>=0;j--)
		{
			if(j>=v[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	cout<<dp[m][t]<<endl;
	return 0;
}
