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
//#define DEBUG
ll l[1005],w[1005],u[1005],dp[1005][1005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,x;//n个人,x瓶药
	cin>>n>>x;
	for(int i=1;i<=n;i++)//输了得到的经验,赢了得到的经验\花费
		cin>>l[i]>>w[i]>>u[i];
//	for(int i=1;i<=n;i++)
//		dp[i][0]=dp[i-1][0]+l[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j>=0;j--)
		{
			if(j>=u[i])
				dp[i][j]=max(dp[i-1][j]+l[i],dp[i-1][j-u[i]]+w[i]);
			else
				dp[i][j]=dp[i-1][j]+l[i];//不用药,认输
		}
	}
	cout<<dp[n][x]*5<<endl;
	return 0;
}
