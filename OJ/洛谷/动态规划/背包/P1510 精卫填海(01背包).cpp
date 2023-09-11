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
int v[10005],w[10005],dp[10005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int V,n,C;
	cin>>V>>n>>C;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>w[i];
	fill(dp,dp+10005,-inf);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{//dp[i]表示体力为i拿到的最大体积
		for(int j=C;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	}
	int ans=inf;
	for(int i=0;i<=C;i++)
	{
		if(dp[i]>=V)
		{
			ans=i;
			break;
		}
	}
	if(ans==inf)
		cout<<"Impossible"<<endl;
	else
		cout<<C-ans<<endl;
	return 0;
}
