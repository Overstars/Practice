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
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
ll dp[40][1005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	ll n,a[40],sum=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		a[i]=i;
		sum+=i;
	}
	if(sum&1)
		cout<<0<<endl;
	else{
		ll v=sum>>1,cnt=0;
//		fill(dp[0],dp[0]+40*1005,-inf);
		dp[1][0]=1;
		dp[1][1]=1;
		for(int i=2;i<=n;i++)//
		{
			for(int j=v;j>=0;j--)
			{
				if(j>=i)//在1~i中拿到和为j的可能数=不拿i即为j的种数+拿了i为j的种数
					dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n][v]/2<<endl;
	}
	return 0;
}
