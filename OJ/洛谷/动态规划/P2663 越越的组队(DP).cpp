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
bool dp[105][10005];//dp[i][j]
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,a[105],sum=0,v,m;
	cin>>n;//��α�֤����Ϊn/2��ͷ��
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	v=sum/2;//��������(�ֵܷ�һ��)
	m=n/2;//����������
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		{
			for(int k=v;k>=a[i];k--)
			{
				if(dp[j-1][k-a[i]])
					dp[j][k]=1;
			}
		}
	}
//	cout<<"sum="<<sum<<endl;
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=v;j++)
//			cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=v;i>=0;i--)
		if(dp[m][i])//ǡ����m����
		{
			cout<<i<<endl;
			break;
		}
	return 0;
}
