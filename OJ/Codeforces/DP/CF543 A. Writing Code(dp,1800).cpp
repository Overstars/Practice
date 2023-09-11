//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=205,inf=0x3f3f3f3f;
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
int a[maxn];
int dp[maxn][maxn];
int dpp[maxn][maxn][maxn]={1};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,b,mod=1000000007,ans=0;
	cin>>n>>m>>b>>mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=a[i];k<=b;k++)
			{
//				dpp[i][j][k]+=dpp[i-1][j-1][k]+dpp[i-1][j-1][k-a[i]];
				dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
//				printf("dp[%d][%d]=%d\n",i,k,dp[i][k]);
			}
		}
	}
	for(int i=0;i<=b;i++)
		ans=(ans+dp[m][i])%mod;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)//n个程序员
		for(int j=0;j<=m;j++)//代码行数
		{
			for(int k=0;k<=b;k++)
			{
				if(k<a[i])
					dpp[i][j][k]=dpp[i-1][j][k];
				else
					dpp[i][j][k]+=dpp[i-1][j-1][k-a[i]];
				printf("dpp[%d][%d][%d]=%d\n",i,j,k,dpp[i][j][k]);
			}
		}
	int ans2=0;
	for(int i=1;i<=b;i++)
		ans2+=dpp[n][m][i];
	cerr<<"ans2 = "<<ans2<<endl;
	return 0;
}
/*
 *n种物品,每种物品体积为1,价值为a[i],背包容量为m
 *可重复取,求总价值不超过b的方案数
 *一共编写m行代码,求出bug不超过b个的方案数
 *似乎是背包问题
 *相当于多了"件数"的费用
 *dp[i][j][k]表示前i个人写了j行bug数为k的情况数
 *dp[i][j][k]=dp[i][j-1][k-a[i]]+dp[i-1][j-1][k-a[i]]
*/

