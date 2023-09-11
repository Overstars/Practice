//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=998244353;
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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{//每一位[1,2*len]
		int nl=1;//此时数字所在位
		while(a[i])
		{//dig在nl+1出现n次,在nl出现n次
			int dig=a[i]%10;
			ans=(ans+dig*qmod(10,nl-1,mod)%mod*n%mod)%mod;
			ans=(ans+dig*qmod(10,nl,mod)%mod*n%mod)%mod;
			a[i]/=10;
			nl+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *用了半小时,zml用了十五分钟
*/

