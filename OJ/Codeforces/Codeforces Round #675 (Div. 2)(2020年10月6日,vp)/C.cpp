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
char s[maxn];
ll l[maxn],r[maxn],pre[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1;
	int ans=0,n=strlen(s+1);
	pre[1]=10;
	for(int i=2;i<=n;i++)
		pre[i]=(pre[i-1]*10)%mod;
	initccc();
	for(int i=1;i<=n;i++)
		l[i]=(l[i-1]*10%mod+(ll)(s[i]-'0'))%mod;
	for(ll i=n,f=1;i>=1;i--,f=(f*10)%mod)
		r[i]=(r[i+1]+(ll)(s[i]-'0')*f%mod)%mod;
	for(int i=1;i<=n;i++)
		ans=(ans+(ll)(s[i]-'0'))%mod;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+l[i])%mod;
		if(i<n-1)//n-i-1个
			ans=(ans+l[i]*pre[n-i-1]);
		ans=(ans+r[i])%mod;
		if(i>2)//作为右端
			ans=(ans+r[i]*(i-2)%mod)%mod;
		printf("ans=%d\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *删掉一段连续非空子段
*/

