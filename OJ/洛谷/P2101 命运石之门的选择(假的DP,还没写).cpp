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
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
int h[5005],dp[5005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	/*https://www.luogu.org/problem/P2101
	 *n个矩形连接,第i个高为h[i],宽都为1
	 *刷子宽为1,每下刷到底,求出刷完木板的最少多少下
	 */
	int n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	memset(dp,inf,sizeof(dp));

	return 0;
}
