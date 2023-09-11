//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=100000000;
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
int dp[maxn][maxn][maxn][2];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	ll ans=0;
	dp[1][0][1][0]=dp[0][1][1][0]=1;
	for(int i=0;i<=n1;i++)
	{//1取i个,2取j个,结尾连续k个l
		for(int j=0;j<=n2;j++)
		{
			if(i>0)//结尾放0
			{
				for(int k=2;k<=k1;k++)//之前结尾放0,继续放
					dp[i][j][k][0]=dp[i-1][j][k-1][0];
				for(int k=1;k<=k2;k++)//之前结尾放1的
					dp[i][j][1][0]=(dp[i][j][1][0]+dp[i-1][j][k][1])%mod;
			}
			if(j>0)//结尾放1
			{
				for(int k=2;k<=k2;k++)//之前的结尾是放1的
					dp[i][j][k][1]=dp[i][j-1][k-1][1];
				for(int k=1;k<=k1;k++)//之前放0的
					dp[i][j][1][1]=(dp[i][j][1][1]+dp[i][j-1][k][0])%mod;
			}
		}
	}
//	for(int i=1;i<=n1+n2;i++)
//	{//总人数
//		for(int a=0;a<=min(i,n1);a++)
//		{//0的个数
//			int b=i-a;//1的个数
//			for(int k=1;k<=)
//		}
//	}
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
			for(int k=1;k<=k1;k++)
				for(int l=0;l<=1;l++)
					printf("dp[%d][%d][%d][%d]=%d\n",i,j,k,l,dp[i][j][k][l]);
	for(int i=1;i<=n1;i++)
		ans=(ans+dp[n1][n2][i][0])%mod;
	for(int i=1;i<=n2;i++)
		ans=(ans+dp[n1][n2][i][1])%mod;
	cout<<ans<<endl;
	return 0;
}


