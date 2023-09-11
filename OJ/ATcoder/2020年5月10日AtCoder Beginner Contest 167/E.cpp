#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=998244353;
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
ll n,m,k;//n块,m色,k块
ll get(ll x)//有k个和左面颜色相同
{//第一块m个颜色
	ll ret=0,oth=n-x-1;//其他的颜色块
	ret=(m*(ccc(n-1,x)*qmod(m-1,oth,mod)%mod)%mod)%mod;
	return ret;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	initccc();
	cin>>n>>m>>k;
	ll ans=0;
	for(ll i=0;i<=k;i++)
		ans=(ans+get(i))%mod;
//	ll ans=qmod(m,n,mod);
//	for(ll i=k+1;i<=n;i++)
//	{
//		ll now=get(i);
//		ans=((ans-now)+mod)%mod;
//	}
	cout<<ans<<endl;
	return 0;
}


