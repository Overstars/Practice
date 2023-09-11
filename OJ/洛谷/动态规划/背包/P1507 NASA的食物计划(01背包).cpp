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
struct node
{
	int v,w,cal;
} a[55];
int dp[55][405][405];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int v,w,n;
	cin>>v>>w>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].v>>a[i].w>>a[i].cal;
	for(int i=1;i<=n;i++)//ȡ��i����Ʒ
	{
		for(int j=v;j>0;j--)//���
		{
			for(int k=w;k>0;k--)//����
			{
				if(j>=a[i].v&&k>=a[i].w)
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-a[i].v][k-a[i].w]+a[i].cal);
				else
					dp[i][j][k]=dp[i-1][j][k];
			}
		}
	}
	cout<<dp[n][v][w]<<endl;
	return 0;
}
