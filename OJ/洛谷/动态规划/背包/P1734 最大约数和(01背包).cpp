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
int dp[1005];//输入为i的和
int fun(int x)
{
	int ret=0;
	for(int i=1;i<x;i++)
		if(x%i==0)
			ret+=i;
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int s;
	cin>>s;
	for(int i=1;i<=s;i++)
		for(int j=i;j<=s;j++)//
			dp[j]=max(dp[j],dp[j-i]+fun(i));
	cout<<dp[s]<<endl;
	return 0;
}

