//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const ll maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll qmod(ll a,ll b,ll mod)  //快速幂
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,k,ans=0,ret=0;
	scanf("%lld%lld",&n,&k);
	ans=k%mod;//k=1时
	for(ll l=2,r=1;l<=n;l=r+1)//l为区间左端点,r为右端点
	{//xk
		r=n/(n/l);
		if(r>=k)
		{
			r=min(k,r);
			ans+=(r-l+1)%mod*((n/l)%mod)%mod;
			ans%=mod;
			break;
		}
		ans+=(r-l+1)%mod*((n/l)%mod)%mod;//这个区间所有的值都为(n/l)向下取整
		ans%=mod;
	}
	n--;
	for(ll l=1,r=1;l<=n;l=r+1)//l为区间左端点,r为右端点
	{//xk+1
		r=n/(n/l);
		if(r>=k)
		{
			r=min(k,r);
			ans+=(r-l+1)%mod*((n/l)%mod)%mod;
			ans%=mod;
			break;
		}
		ans+=(r-l+1)%mod*((n/l)%mod)%mod;//这个区间所有的值都为(n/l)向下取整
		ans%=mod;
	}
//	ans=(ans+ret%mod)%mod*2%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
9 9
ans=43
1000000000000 1000000000000
ans=904509013
100000000 123456789
ans=738479823
*/

