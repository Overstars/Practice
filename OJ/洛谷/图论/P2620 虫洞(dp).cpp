//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll b[maxn],e[maxn],dp[maxn];
signed main()
{//dp[x]表示到达x号虫洞的最早时间
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int w,s,p;//目的地,限制距离,虫洞数目
	while(cin>>w&&w)
	{
		cin>>s>>p;
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=p;i++)
			cin>>b[i]>>e[i];//开始结束
		for(int i=1;i<=p;i++)
		{
			dp[i]=b[i]/s+((b[i]%s)?1:0);
//			printf("ins[%d]=%lld\n",i,dp[i]);
		}
		ll ans=w/s+((w%s)?1:0);
//		printf("ans=%lld\n",ans);
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=p;j++)
			{
				if(e[j]<=b[i])
					dp[i]=min(dp[i],(ll)(dp[j]+(b[i]-e[j])/s+((b[i]-e[j])%s?1:0)));
			}
		}
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=p;j++)
			{
				if(e[j]<=b[i])
					dp[i]=min(dp[i],(ll)(dp[j]+(b[i]-e[j])/s+((b[i]-e[j])%s?1:0)));
			}
		}
		for(int i=1;i<=p;i++)
		{
			ans=min(ans,(ll)(dp[i]+(w-e[i])/s+((w-e[i])%s?1:0)));
//			printf("dp[%d]=%lld\n",i,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


