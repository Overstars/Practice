#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=210,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll c[maxn],dp[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,l,x,y;
	cin>>n>>l;
	for(int i=0;i<n;i++)
		cin>>c[i];
	dp[0]=c[0];
	for(int i=1;i<n;i++)//购买2^i最小代价
		dp[i]=min(c[i],dp[i-1]*2);
	ll ans=LLONG_MAX,sum=0;
	for(ll i=n-1;i>=0;i--)
	{//高位到低位
		ll des=l/(1ll<<i);
		sum+=des*dp[i];
		l&=(1<<i)-1;//保留低位
//		l-=(des<<i);//购买总数
		ans=min(ans,sum+(l>0)*dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}


