#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
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
	 *n����������,��i����Ϊh[i],��Ϊ1
	 *ˢ�ӿ�Ϊ1,ÿ��ˢ����,���ˢ��ľ������ٶ�����
	 */
	int n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	memset(dp,inf,sizeof(dp));

	return 0;
}
