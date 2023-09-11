#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn][3];//0未反转,1反转,2
char s[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n>>s+1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		{
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=max(dp[i-1][0],dp[i-1][1]+1);
			dp[i][2]=max(dp[i-1][1],dp[i-1][2]+1);
		}
		else{
			dp[i][0]=dp[i-1][0];
			dp[i][1]=max(dp[i-1][0]+1,dp[i-1][1]);
			dp[i][2]=max(dp[i-1][1]+1,dp[i-1][2]);
		}
		for(int j=0;j<=2;j++)
			ans=max(ans,dp[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *dp[i][0]表示以i结尾,未开始反转的最大序列长度
 *dp[i][1]表示以i结尾,正在反转的
 *dp[i][2]表示以i结尾,已经用掉了反转次数的(即这一段未反转)
 */

