#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll a[maxn],sum[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0,ma=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
			ma+=i*a[i];
//			printf("%d:ans=%lld\n",i,ans);
		}
//		printf("%lld\n",ans);
		for(int i=k+1;i<=n;i++)
		{
			ans=max(ans,ma-a[i]*k+sum[i-1]-sum[i-k-1]);
//			printf("ans=%lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


