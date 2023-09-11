//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5005,inf=0x3f3f3f3f,mod=1000000007;
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
ll a[maxn],sum[maxn],dp[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,c,ans=0;
	cin>>n>>m>>c;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
//	for(ll i=m;i<=n;i++)
//	{//dp[i][j]表示以i作为第j段结尾的最大值
////		for(ll j=1;j*m<=i;j++)
////		{//每组长度为m,一共c组
////			for(int k=0;k<=i-m;k++)
////				dp[i][j]=max(dp[i][j],dp[k][j-1]+sum[i]-sum[i-m]);
//////			printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
////		}
//		for(ll j=1;j*m<=i;j++)//rec[i]表示前i个产生j-1个段的最大值
//			dp[i][j]=sum[i]-sum[i-1]+rec[j-1];
//		rec.resize(n+1,0);
//		for(ll j=1;j*m<=i;j++)
//			rec[j]=max(rec[j-1],)
//	}
	vector<ll> rec(n+1,0);
	for(ll j=1;j<=c;j++)
	{//j组
		for(ll i=m;i<=n;i++)
			dp[i][j]=sum[i]-sum[i-m]+rec[i-m];
		rec.resize(n+1,0);
		for(ll i=1;i<=n;i++)
			rec[i]=max(rec[i-1],dp[i][j]);
	}
	for(ll i=m*c;i<=n;i++)
		ans=max(ans,dp[i][c]);
	cout<<ans<<endl;
	return 0;
}
/*
20 5 3
96 46 67 36 59 95 88 43 92 58 1 31 69 35 36 77 56 27 3 23
ans=953
*/

