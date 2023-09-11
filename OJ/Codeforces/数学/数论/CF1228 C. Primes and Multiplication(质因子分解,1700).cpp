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
ll qmod(ll a,ll b,ll mod)  //快速幂
{
	b%=(mod-1);
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll ans=1,x,y;
	cin>>x>>y;
	ll n=x;
	vector<ll>f;
	for(ll i=2;i*i<=n;i++)//sqrt(x)
		if(n%i==0)
		{
			f.push_back(i);
			while(n%i==0)
				n/=i;
		}
	if(n>1)
		f.push_back(n);
	for(ll &p:f)
	{
		for(ll now=y,pp=1;now>0;now/=p,pp=(p*pp)%mod)
		{
			ll inc=qmod(pp,now-now/p,mod);
			ans=(ans*inc)%mod;
		}
//		for(ll now=p,k=1;now<=y;now*=p)//这个是计算小于x的最大p^k的...
//		{//y<p都是1,[p,p^2)为p,[p^2,p^3)为p^2
//			if(now*p>y)
//			{
//				ans=(ans*qmod(now,(y-now+1),mod)%mod)%mod;
//				break;
//			}
//			else
//				ans=(ans*(qmod(now,(now*p-now),mod)%mod))%mod;
//		}
//		printf("ans=%lld\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *对于给出的x,y
 *对于x的每个质因子p
 *都有g(1,p)*g(2,p)*...*g(y,p)
 *我把整除关系看成小于了...可以出道新题...
 */

