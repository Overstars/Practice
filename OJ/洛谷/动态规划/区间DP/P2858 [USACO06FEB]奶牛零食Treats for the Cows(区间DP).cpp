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
const int maxn=2005;
/*
 *n����ʳ,һ����һ��,��i�ݳ�ʼ��ֵvi
 *ֻ����������ϵ�
 *��a���ۼ�vi*a
 */
//#define DEBUG
int n,dp[maxn][maxn],v[maxn];
int main()//dp[i][j]
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,ans=-inf;//n����ʳ
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		dp[i][i]=n*v[i];//��i����ʳ���������
	}
	for(int l=2;l<=n;l++)//ö�����䳤��,Ҳ�ɱ�ʾΪ����
	{//�ӵ�n����ǰdp...
		for(int i=1;i+l-1<=n;i++)//ȡ�����i��
		{
			int j=i+l-1;//�����û���м���...
			int d=n-l+1;//��d��
			dp[i][j]=max(dp[i+1][j]+v[i]*d,dp[i][j-1]+v[j]*d);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
