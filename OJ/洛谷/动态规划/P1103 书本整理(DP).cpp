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
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=200005;
//#define DEBUG
struct node
{
	int h,w;
} a[105];
bool cmp(const node &a,const node &b)
{
	return a.h<b.h;
}
int dp[105][105];//dp[i][j]��ʾǰi���鱣��j������С
//int sub[105];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,lim;
	cin>>n>>lim;
	for(int i=1;i<=n;i++)
		cin>>a[i].h>>a[i].w;
	sort(a+1,a+n+1,cmp);
//	for(int i=2;i<=n;i++)
//		sub[i]=(int)abs(a[i].w-a[i].w);
	memset(dp,inf,sizeof(dp));
	dp[1][0]=0;
//	for(int i=2;i<=n;i++)//����ǰn����
//	{
//		dp[i][0]=dp[i-1][0]+(int)abs(a[i].w-a[i-1].w);
//		for(int j=1;j<=lim;j++)
//		{
//			dp[i][j]=dp[i][j-1]+(int)abs(a[i].w-a[i-1].w);//һ����������
//		}
//		for(int j=1;j<i;j++)
//		{
//			for(int k=1;k<=lim;k++)
//			{
//				dp[i][k]=min(dp[i-1][k],dp[i-1][k-1]-);//�����ߵ�i����/���ߵ�i����
//			}
//		}
//	}
	for(int i=1;i<=n;i++)
		dp[i][1]=0;
	for(int i=2;i<=n;i++)//ǰi����,�Ե�i����β
	{
		for(int j=1;j<=n;j++)//ѡ��j��
		{
			for(int k=1;k<i;k++)//ǰһ��Ϊ��k��,���ڵ�k������
				dp[i][j]=min(dp[i][j],dp[k][j-1]+(int)abs(a[k].w-a[i].w));
		}
	}
	int ans=inf;
	for(int i=2;i<=n;i++)
		ans=min(ans,dp[i][n-lim]);
	cout<<ans<<endl;
	return 0;
}
