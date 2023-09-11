#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
ll dp[65][4][4];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	dp[1][1][1]=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		dp[i][1][3]=dp[i-1][1][2]*2+1;
		dp[i][3][1]=dp[i-1][2][1]*2;
		dp[i][2][1]=dp[i][3][2]=dp[i-1][1][2]+dp[i-1][3][1];
		dp[i][1][2]=dp[i][2][3]=dp[i-1][1][3]+dp[i-1][2][1];
	}
	ll tot=0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i==j)
				continue;
			tot+=dp[n][i][j];
			printf("%c->%c:%lld\n",'A'+i-1,'A'+j-1,dp[n][i][j]);
		}
	}
	printf("SUM:%lld\n",tot);
	return 0;
}


