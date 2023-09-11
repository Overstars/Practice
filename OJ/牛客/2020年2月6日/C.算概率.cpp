#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
ll p[maxn],ans[maxn];
ll quick_mod(ll a, ll b)
{
    ll ans = 1;
    a %= mod;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % mod;
            b--;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
ll C(ll n, ll m)
{
    if(m > n) return 0;
    ll ans = 1;
    for(int i=1; i<=m; i++)
    {
        ll a = (n + i - m) % mod;
        ll b = i % mod;
        ans = ans * (a * quick_mod(b, mod-2) % mod) % mod;
    }
    return ans;
}
ll Lucas(ll n, ll m)
{
    if(m == 0) return 1;
    return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
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
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		ans[i]=Lucas(n,i)*quick_mod(p[i],i)%mod*quick_mod((1-p[i]%mod),n-i)%mod;
		cout<<ans[i]<<' ';
	}
	return 0;
}
