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
char s[maxn];
int dp[maxn],dp2[maxn];//dp[i]以i结束的最长长度
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("1.in", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n>>s+1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
		ans=max(ans,dp[i]);
	}
	dp2[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(s[i]!=s[i+1])
			dp2[i]=dp2[i+1]+1;
		else
			dp2[i]=1;
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",dp[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)
//		printf("%d ",dp2[i]);
//	printf("\n");
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])
		{//反转dp2[i]这一段
			ans=max(ans,dp[i-1]+dp2[i]+dp2[i+dp2[i]]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *读错题了,以为反转一段区间,使得010串最长
 *结果是要求最长01子序列
 */
