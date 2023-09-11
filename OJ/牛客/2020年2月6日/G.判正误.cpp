#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
ll qmod(ll a,ll b)  //快速幂
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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,a,b,c,d,e,f,g;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>e>>f>>g;
		ll now=qmod(a,d)+qmod(b,e)+qmod(c,f);
		if(now==g)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}


