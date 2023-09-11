//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e7+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll qmod(ll a,ll b,ll mod)//快速幂
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
int ans[maxn];//,f[maxn]={1};
ll inve[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ans[1]=inve[1]=qmod(2,mod-2,mod);
	ll p=2,now=ans[1];
	for(int i=2;i<maxn;i++)
	{
		p=(p<<1ll)%mod;
		inve[i]=inve[i-1]*inve[1]%mod;//逆元
		now=now*((p-1+mod)%mod)%mod*inve[i]%mod;
//		f[i]=f[i-1]*((p-1+mod)%mod)%mod*inve[i]%mod;
		ans[i]=now^ans[i-1];
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}


