#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
ll a[maxn],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	memset(dp,inf,sizeof(dp));
	dp[0]=0;
	ll rec=inf;
	for(int i=k;i<=n;i++)
	{
		rec=min(rec,dp[i-k]-a[i-k+1]);
//		for(int j=1;j+k-1<=i;j++)
//			dp[i]=min(dp[i],dp[j-1]+a[i]-a[j]);
		dp[i]=rec+a[i];
	}
	cout<<dp[n]<<endl;
	return 0;
}


