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
int a[105],dp[105][105];//����DP
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int p,q;//һ��p��,�ͷ�q��
	cin>>p>>q;
	for(int i=1;i<=q;i++)
		cin>>a[i];//�ͷ�����a[1:q]
	sort(a+1,a+q+1);
	a[q+1]=p+1;//����q+1��������
//	fill(dp[0],dp[0]+105*105,1);
//	for(int i=1;i<=q;i++)
//		dp[i][i]=p;
	for(int l=1;l<=q;l++)//�ͷŵ����䳤��,(�����������ϲ�ʯ������...)
	{
		for(int i=1;i+l-1<=q;i++)//�ͷ��������ϵ�i��j����������С����
		{
			int j=i+l-1;
			dp[i][j]=inf;//��ʼ��
			for(int k=i;k<=j;k++)//�ͷŵ�k�ŷ�����С����
			{
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[j+1]-a[i-1]-1-1);
			}
		}
	}
	cout<<dp[1][q]<<endl;
	return 0;
}
