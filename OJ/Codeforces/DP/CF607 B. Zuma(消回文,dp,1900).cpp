//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],dp[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
//		for(int len=1;i-len>=1&&i+len<=n;len++)
//			if(a[i-len]==a[i+len])
//				dp[i-len][i+len]=1;
//			else
//				break;
	}
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			int r=l+len-1;
			if(a[l]==a[r])
			{//
				if(r-l<=1)
					dp[l][r]=1;
				else
					dp[l][r]=dp[l+1][r-1];
			}
//			if(a[l]!=a[r])
//			{
				for(int k=l;k<=r;k++)
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
//			}
//			else{
//				if(r-l<=1)
//					dp[l][r]=1;
//				else
//					dp[l][r]=dp[l+1][r-1];
//			}
			printf("dp[%d][%d]=%d\n",l,r,dp[l][r]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
/*
6
1 2 1 1 3 1
*/
/*
 * 2021-04-11-19.33.55
 * abbbdbb aca ba
 * 令dp[l][r]为消掉[l,r]区间的最小次数
 * 若a[l]=a[r],则dp[l][r]可以=dp[l+1][r-1]但不一定最优
 * 仍需要枚举分割点
 * 否则只能将子段分割
*/

