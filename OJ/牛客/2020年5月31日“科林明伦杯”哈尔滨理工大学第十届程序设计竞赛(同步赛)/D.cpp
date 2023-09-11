#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,n,m,k;
	initccc();
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;//n枚硬币,m确定为反面,求k个正面的概率
		if(n==0||(n-k)<m)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=ccc(n,n-k),b=1;
//		for(ll i=1;i<=n;i++)
//			b=(b*quick(2,mod-2)%mod);
//		cout<<(ans*b)%mod<<endl;
		ll ans2=0;
		for(int i=0;i<m;i++)//至少m个反面
			ans2=(ans2+ccc(n,i))%mod;
		ans2=((quick(2,n)-ans2)%mod+mod)%mod;
		cout<<ans*quick(ans2,mod-2)%mod<<endl;
	}
	return 0;
}


