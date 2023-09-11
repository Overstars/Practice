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
int c[5005],p[5005],q[5005],dp[5005][5005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int a,b,m,n,time;//����ˮƽֵ,��Ŀ��m,֪ʶ����n
	cin>>a>>b>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]*=b/a;//֪ʶ��i�Ļ���ʱ��
	}
	for(int i=1;i<=m;i++)
		cin>>p[i]>>q[i];//��Ŀ֪ʶ��,����
	cin>>time;
	for(int i=1;i<=m;i++)//����Ŀi
	{
		for(int j=time;j>0;j--)//ʱ��Ϊj
		{
			if(j>=c[p[i]])//����ʱ��
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[p[i]]]+q[i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[m][time]<<endl;
	return 0;
}
