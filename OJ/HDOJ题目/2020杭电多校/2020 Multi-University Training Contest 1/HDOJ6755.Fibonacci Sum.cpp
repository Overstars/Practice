//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000009;
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
ll fac[maxn],a[maxn];
ll quick(ll a,ll b){//快速幂
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans%mod;
}
ll ccc(ll n,ll m){//求组合数
	return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) % mod)%mod;
}
void initccc()
{
	fac[0] = 1;
	for (int i = 1; i <maxn ;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	initccc();
	int T,n,c,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>c>>k;
		int A=691504013,B=308495997;//A=(1+sqrt5)/2,B=(1-sqrt5)/2
		A=qmod(A,c%(mod-1)),B=qmod(B,c%(mod-1));//欧拉降幂
	}
	return 0;
}


