//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e3+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn][maxn],dp[5][maxn][maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ans=0;
	cin>>n>>m;
//	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	dp[4][1][m+1]=0;//为什么给a读入会影响到dp数组?
//	for(int i=4;i<=4;i++)
//		for(int j=1;j<=n;j++)
//			for(int k=1;k<=m;k++)
//				printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1])+a[i][j];
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			dp[2][i][j]=max(dp[2][i+1][j],dp[2][i][j-1])+a[i][j];
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j+1])+a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			dp[4][i][j]=max(dp[4][i-1][j],dp[4][i][j+1])+a[i][j];
//	for(int i=1;i<=4;i++)
//		for(int j=1;j<=n;j++)
//			for(int k=1;k<=m;k++)
//				printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++)//上左+下右,左下+右上
		{
//			printf("[%d,%d]=%d\n",i,j,max(dp[1][i-1][j]+dp[3][i+1][j]+dp[2][i][j-1]+dp[4][i][j+1],dp[1][i][j-1]+dp[3][i][j+1]+dp[2][i+1][j]+dp[4][i-1][j]));
			ans=max({ans,dp[1][i-1][j]+dp[3][i+1][j]+dp[2][i][j-1]+dp[4][i][j+1],dp[1][i][j-1]+dp[3][i][j+1]+dp[2][i+1][j]+dp[4][i-1][j]});
		}
	cout<<ans<<endl;
	return 0;
}


