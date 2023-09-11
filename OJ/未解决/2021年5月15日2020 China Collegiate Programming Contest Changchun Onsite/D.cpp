//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
ll fac[maxn],inv[maxn],a[maxn];
ll quick(ll a,ll b){//快速幂
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans%mod;
}
ll ccc(ll n,ll m){//求组合数C(n,m)=n!/m!(n-m)!
	if(n<m)
		return 0;
	else if(n==m)
		return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
//	return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) % mod)%mod;
}
void initccc(ll n)
{
	fac[0] = 1;
	for (int i = 1; i <= n ;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[n]=quick(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1ll)%mod;
}
char s[maxn];
int suf[maxn],pre[maxn],c;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t=100;
	initccc(maxn-1);
//	while(t--)
	{
		cin>>s+1>>c;
		int n=strlen(s+1);
		if(n==1&&s[1]=='0')
			return cout<<1<<endl,0;
	//	for(int i=0;i<=10;i++)
	//		for(int j=0;j<=i;j++)
	//			printf("c(%d,%d)=%lld\n",i,j,ccc(i,j));
		for(int i=n;i>=1;i--)
		{
			if(s[i]=='1')
				suf[i]++;
			suf[i]+=suf[i+1];
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
				pre[i]++;
			pre[i]+=pre[i-1];
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
				continue;
			for(int j=0;j<=n-i;j++)
			{//[1,i-1]的1都固定,第i位固定为0
				ans+=ccc(n-i,j)*quick(c,pre[i]-1+j)%mod;
				ans%=mod;
			}
			if(suf[i]==1)
			{
				ans+=quick(c,pre[i]);
				ans%=mod;
				break;
			}
	//		printf("%d,ans=%lld\n",i,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-05-15-14.45.00
*/

