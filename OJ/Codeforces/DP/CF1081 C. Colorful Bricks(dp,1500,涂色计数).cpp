#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
const int maxn=2005,inf=0x3f3f3f3f,mod=998244353;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn][maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k;
	cin>>n>>m>>k;//n块,m种,k个与左面不同
	dp[1][0]=m;//dp[i][j]表示截止第i块,与前面相同的有j个
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=(dp[i-1][j]*(m-1))%mod;//与上一个不同
			if(j>0)
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	cout<<dp[n][(n-1)-k]<<endl;
	return 0;
}


