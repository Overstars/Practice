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
int t[5][5]=
{
	0,-3,-4,-2,-1,
	-3,5,-1,-2,-1,
	-4,-1,5,-3,-2,
	-2,-2,-3,5,-2,
	-1,-1,-2,-2,5,
};
int dp[105][105];//dp[i][j]表示以a的i和b的j结尾的*相似度*
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,m,ans=0;
	char a[105],b[105];
	scanf("%d %s%d %s",&n,a+1,&m,b+1);
	map<char,int> TAT;
	TAT['A']=1,TAT['C']=2,TAT['G']=3,TAT['T']=4;
//	fill(dp[0],dp[0]+105*105,-inf);
	for(int i=1;i<105;i++)
		for(int j=1;j<105;j++)
			dp[i][j]=-inf;
	for(int i=1;i<=n;i++)//边界需要额外的初始化
		dp[i][0]=dp[i-1][0]+t[TAT[a[i]]][0];
	for(int i=1;i<=m;i++)
		dp[0][i]=dp[0][i-1]+t[0][TAT[b[i]]];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{//a[i]与b[j]配对,b[j]与空字符配对,a[i]与空字符配对
			dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]+t[TAT[a[i]]][TAT[b[j]]],max(dp[i-1][j]+t[TAT[a[i]]][0],dp[i][j-1]+t[0][TAT[b[j]]])));
//			ans=max(ans,dp[i][j]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
