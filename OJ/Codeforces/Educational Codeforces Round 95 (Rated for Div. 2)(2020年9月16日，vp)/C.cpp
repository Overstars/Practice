//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll a[maxn],dp[maxn][2][3];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int k=1;k<=2;k++)
				dp[i][0][k]=dp[i][1][k]=inf;
//		dp[0][0]=dp[0][1]=0;//第i个怪,0朋友打,1我打,连着打k轮
		if(a[1])
			dp[1][0][1]=1;
		else
			dp[1][0][1]=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i])//hard,
			{
				dp[i][0][1]=min(dp[i-1][1][1],dp[i-1][1][2])+1;
				dp[i][0][2]=dp[i-1][0][1]+1;
				dp[i][1][1]=min(dp[i-1][0][1],dp[i-1][0][2]);
				dp[i][1][2]=dp[i-1][1][1];
			}
			else{//easy
				dp[i][0][1]=min(dp[i-1][1][1],dp[i-1][1][2]);
				dp[i][1][1]=min(dp[i-1][0][1],dp[i-1][0][2]);
				dp[i][0][2]=dp[i-1][0][1];
				dp[i][1][2]=dp[i-1][1][1];
			}
		}
		ll ans=LLONG_MAX;
		for(int k=1;k<=2;k++)
			ans=min(ans,min(dp[n][0][k],dp[n][1][k]));
		cout<<ans<<endl;
	}
	return 0;
}


