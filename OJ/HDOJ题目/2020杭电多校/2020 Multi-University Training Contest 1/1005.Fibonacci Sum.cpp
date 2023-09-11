//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000009;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll f[maxn]={0,1};
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
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(int i=2;i<=100;i++)
		f[i]=f[i-1]+f[i-2];
//	for(int k=1;k<=5;k++)
//		for(int c=1;c<=10;c++)


	for(int k=1;k<=5;k++)
	{
		for(int n=1;n<=10;n++)
		{
			for(int c=1;c<=10;c++)
			{
				ll sum=0;
				for(int i=0;i<=n*c;i+=c)
					sum=(sum+qmod(f[i],k,mod))%mod;
				printf("k=%d,n=%d,c=%d,\tsum=%lld\n",k,n,c,sum);
			}
		}
	}
	return 0;
}


