#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
char mp[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='R')
				dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			else if(mp[i][j]=='D')
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			else if(mp[i][j]=='B')
			{
				dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}


