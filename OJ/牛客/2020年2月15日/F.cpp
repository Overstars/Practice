#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read() {}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll r[maxn],c[maxn],mp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,h,x,y,z,res=0;
	read(n,m,h);
	ll sum=0;
	while(h--)
	{
		read(x,y,z);
//		sum=((((z*m%mod)+z*n%mod)%mod-z)%mod+sum)%mod;
		r[x]=(r[x]+z)%mod;
		c[y]=(c[y]+z)%mod;
		mp[x][y]=(mp[x][y]+z)%mod;
		res=(res+z)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ll now=((r[i]+c[j])%mod-mp[i][j])%mod;
			sum=(sum+now*(i+j)%mod)%mod;
		}
	}
	printf("%lld\n",(sum+mod)%mod);
	return 0;
}


