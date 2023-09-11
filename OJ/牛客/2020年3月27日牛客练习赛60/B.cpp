#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5,inf=0x3f3f3f3f,mod=998244353;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct node
{
	ll x,y;
	node(ll x=0,ll y=0):
		x(x),y(y){}
}a[maxn];
ll dis(ll m,ll n)
{
	return (abs(a[m].x-a[n].x)%mod+abs(a[m].y-a[n].y)%mod)%mod;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,x,y,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			ans=(ans+dis(i,j)*(n-2)%mod)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}


