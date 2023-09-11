#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll dp[maxn][15];
void init()
{
	for(int i=0;i<=9;i++)
		dp[2][i]=1;
	for(int i=3;i<=1000;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
		}
	}
}
ll num[maxn];
ll solve(ll x)
{
	ll len=0,ans=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	}
	for(int i=len-1;i>=1;i--)
		for(int j=1;j<=9;j++)
			ans=(ans+dp[i][j])%mod;
	for(int i=1;i<num[len];i++)
		ans=(ans+dp[len][i])%mod;
	for(int i=len-1;i>=1;i--)
	{
		for(int j=0;j<=num[i];j++)
		{
			ans=(ans+dp[i][])%mod;
		}
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll l,r;
	cin>>l>>r;
	return 0;
}


