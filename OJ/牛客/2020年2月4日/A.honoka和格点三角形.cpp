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
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,ans=0;
	cin>>n>>m;
//	for(ll i=3;i<=n;i++)//n为2底,枚举所在位置
//	{
//		for(ll j=1;j<=m;j++)//n为底,枚举底所在层数
//		{
//			if(j==1||j==m)
//			{
//				ans=(ans+n)%mod;
//			}
//			else{
//				ans=(ans+2*n)%mod;
//			}
////			printf("ans=%lld\n",ans);
//		}
//	}
//	for(ll i=3;i<=m;i++)//m为2底,枚举所在位置
//	{
//		for(ll j=1;j<=n;j++)//枚举所在列
//		{
//			if(j==1||j==n)
//			{
//				ans=(ans+m)%mod;
//			}
//			else
//				ans=(ans+2*m)%mod;
////			printf("ans=%lld\n",ans);
//		}
//	}
//	for(ll i=2;i<=n&&m>=3;i++)//n为1底,枚举所在列
//	{
//		for(ll j=1;j<=m;j++)//枚举行
//		{
//			if((m-j)<2&&(j-1)<2)
//				continue;
//			if(j<=2||j+1>=m)
//				ans=(ans+n-2)%mod;
//			else
//				ans=(ans+2*(n-2))%mod;
//		}
//	}
//	for(ll i=2;i<=m&&n>=3;i++)
//	{
//		for(ll j=1;j<=n;j++)
//		{
//			if((n-j)<2&&(j-1)<2)
//				continue;
//			if(j<=2||j+1>=n)
//				ans=(ans+m-2)%mod;
//			else
//				ans=(ans+2*(m-2))%mod;
//		}
//	}
	ans=((n-2)*(m-1)%mod*n%mod*2)%mod;//2在n,上+下
	ans=(ans+((m-2)*(n-1)%mod*m%mod*2)%mod)%mod;//2在m,左+右
	ll now=((n-1)*(m-2)%mod*(n-2)%mod*2)%mod;//1在n
	ans=(ans+now)%mod;
	now=((m-1)*(n-2)%mod*(m-2)%mod*2)%mod;
	ans=(ans+now)%mod;
	cout<<ans<<endl;
	return 0;
}


