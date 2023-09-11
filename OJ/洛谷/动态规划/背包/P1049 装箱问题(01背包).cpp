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
int v[35],dp[20005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int c,n;//容量,个数
	cin>>c>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
		for(int j=c;j>=v[i];j--)
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
	cout<<c-dp[c]<<endl;
	return 0;
}
