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
ll v[30],w[30],p[30],dp[30][30005]={0};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("P1060.in", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,m;//Ǯ,��Ʒ����.dp[i][j]��ʾ��ǰi����Ʒ,Ԥ��jԪ�����Ž�
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i];//vΪ���
		w[i]=v[i]*p[i];//��ֵ
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(j>=v[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
			else
				dp[i][j]=dp[i-1][j];//Ҫ��֮ǰ��״̬���ƹ���
		}
	}
//	#ifdef DEBUG
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%lld,",dp[i][j]);
//		}
//		printf("\n");
//	}
//	#endif // DEBUG
	cout<<dp[m][n]<<endl;
	return 0;
}
