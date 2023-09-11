//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll ans[maxn]={0,1},dp[maxn]={1,1};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,k,l,r;
	ll p=qmod(2,mod-2,mod);
	cin>>t>>k;
	for(ll i=1;i<maxn;i++)
	{
		if(i>=k)
			dp[i]=(dp[i-1]+dp[i-k])%mod;
		else
			dp[i]=dp[i-1];
//		ans[i]=(ans[i-1]+dp[i])%mod;
//		ans[i]=(ans[i-1]+1)%mod;
//		ll now=(i/k)*(i-k+1+(i-i/k*k+1))%mod*p%mod;//不对,可以有多个k块组合
//		printf("%lld:%lld,%lld\n",i,now+1,dp[i]);
//		if(now+1!=dp[i])
//		{
//			printf("HERE!!!\n");
//			system("pause");
//		}
		ans[i]=(ans[i]+now)%mod;
	}
	while(t--)
	{
		cin>>l>>r;
		cout<<(ans[r]-ans[l-1]+mod)%mod<<endl;
	}
	return 0;
}
/*
1859 48096
95515 99613
ans=887284912
*/
/*
 * k=2,W个数必须是k的倍数
 * 1:R
 * 2:RR WW
 * 3:RRR RWW WWR
 * 4:RRRR RRWW RWWR WWRR WWWW
 * 等差数列前n项和求含W的组合个数...
 * 我读错题了?
 * 按洛谷翻译写吧,唔好像确实是相同的
 * 嗯,k个是一个整体,i/k个k,要用隔板法求,i/k个k连接起来会少情况
 * 用隔板法求复杂度爆炸
*/

