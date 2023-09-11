#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
ll dp[maxn][maxn],p[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)//dp[i][j]表示前i题做对j道
	{
		dp[i][0]=(dp[i-1][0]*((mod+1-p[i])%mod))%mod;
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]*p[i]%mod+(dp[i-1][j]*((mod+1-p[i])%mod))%mod)%mod;
		}
	}
	for(int i=0;i<=n;i++)
		cout<<dp[n][i]<<' ';
	return 0;
}


