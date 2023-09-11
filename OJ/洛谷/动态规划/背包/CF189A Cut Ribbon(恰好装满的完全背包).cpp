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
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int dp[4005];//dp[i]��ʾ����Ϊi���������(����ǡ�ü���)
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,l[4];
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		cin>>l[i];
//		dp[l[i]]=1;
	}
	fill(dp,dp+4005,-inf);
	dp[0]=0;
	for(int i=1;i<=n;i++)//ö�ٳ���
	{
		for(int j=1;j<=3;j++)//ö������
		{
			if(i>=l[j])
				dp[i]=max(dp[i],dp[i-l[j]]+1);//���´�i-l[j]~i��һ��
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<"dp["<<i<<"]="<<dp[i]<<endl;
	cout<<dp[n]<<endl;
	return 0;
}
