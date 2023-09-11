//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1005,inf=0x3f3f3f3f,mod=10000;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn][maxn],sum[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{//n^3的是没问题的
//		dp[i][0]=sum[i][0]=1;
		for(int j=0;j<=m&&j<=i*(i-1)/2;j++)
			for(int k=max(0,j-i+1);k<=j;k++)
				dp[i][j]+=dp[i-1][k],dp[i][j]%=mod;
		for(int j=0;j<=m;j++)
			fprintf(stderr,"dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
//	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=sum[i][0]=1;
		for(int j=1;j<=m;j++)
		{//
//			for(int k=1;k<=i;k++)//i-1个数有i个位置可以插
//			{//将i插入到第k个前面会产生i-k个逆序对
//				dp[i][j+i-k]+=dp[i-1][j];
//			}
//			for(int k=max(0,j-i+1);k<=j;k++)
//			{
//				dp[i][j]+=dp[i-1][k];
//			}
			if(j<=i*(i-1)/2)
			{
//				int sub=j-i+1;
				dp[i][j]=sum[i-1][j];
				if(j-i+1>0)//从j-i+1开始记录答案
					dp[i][j]-=sum[i-1][j-i];
				dp[i][j]=(dp[i][j]+mod)%mod;
			}
			sum[i][j]=sum[i][j-1]+dp[i][j];
			sum[i][j]%=mod;
		}
		for(int j=0;j<=m;j++)
			fprintf(stderr,"dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
/*
 * 2021-05-18-18.24.56
 * C:\Users\dell\Desktop\C++\OJ\洛谷\动态规划\dp优化\P2513 [HAOI2009]逆序对数列(前缀和优化).cpp
 * n排列组成逆序对为k的数列总数
 * dp[i][j]表示i排列逆序对为j的个数
*/


