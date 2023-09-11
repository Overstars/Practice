#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn]={1,1},dp2[maxn]={1,1};//长度为i的路径数
signed main()//所有边都小于d的长度为i的路径数
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,d;
	cin>>n>>k>>d;
	if(d==1)
		dp2[0]=dp2[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=k&&i-j>=0;j++)
			dp[i]=(dp[i]+dp[i-j])%mod;
		for(int j=1;j<d&&i-j>=0;j++)
			dp2[i]=(dp2[i]+dp2[i-j])%mod;
//		printf("%d:%d,%d\n",i,dp[i],dp2[i]);
	}
	cout<<(dp[n]-dp2[n]+mod)%mod<<endl;
	return 0;
}


