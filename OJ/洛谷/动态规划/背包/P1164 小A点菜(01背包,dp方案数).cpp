#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int dp[10005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("P1164.in", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,m,a[105];//����,����
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
//	fill(dp,dp+10005,-inf);
	dp[0]=1;//0Ԫʱ1�ֵ�˷�ʽǡ�û���
	int cnt=0;
	for(int i=1;i<=n;i++)//n����
		for(int j=m;j>=a[i];j--)
		{
			if(dp[j-a[i]]>0)//�����i����
				dp[j]+=dp[j-a[i]];//
		}
	cout<<dp[m]<<endl;
	return 0;
}
