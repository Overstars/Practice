//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
ll fac[maxn],a[maxn];
ll quick(ll a,ll b){//快速幂
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans%mod;
}
ll ccc(ll n,ll m){//求组合数
	if(m>n)
		return 0;
	return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) % mod)%mod;
}
void initccc()
{
	fac[0] = 1;
	for (int i = 1; i <maxn ;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
}
int dp[maxn],pre[maxn],suf[maxn];
char s[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	initccc();
	cin>>s+1;
	int n=strlen(s+1),ans=0,lambda=1,sum=0;
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
//	dp[1]=1;//dp[2]=1+10,dp[3]=1+10+100
	for(int i=1;i<=n;i++,lambda=(lambda*10)%mod)
		dp[i]=(i*lambda%mod+dp[i-1])%mod;
	for(int i=2;i<=n;i++)//第i位作为后段有效部分时的贡献
	{//C(n-i,2)选择开头结尾,再加上只有一个的部分
//		ans=(ans+a[i]*(i-1)%mod*quick(10,n-i)%mod)%mod;
		sum=(sum+i-1)%mod;
		ans=(ans+a[i]*sum%mod*quick(10,n-i)%mod)%mod;
//		printf("ans = %lld\n",ans);
	}//7+7+7 (07+7+17)
//	printf("wtf\n");//17+1+10
	for(int i=1;i<n;i++)//1*(20+1)+0*(10)
	{//第i位作为前段有效部分时的贡献
		ans=(ans+a[i]*dp[n-i]%mod)%mod;
//		printf("ans = %lld\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*2
 *234,34,4,134,14,1,124,12,123
 *第一部分贡献计算:1234,处于后部
 *1无贡献
 *2的贡献为2*(100+)  //2*(100+10*2+1*1)
 *3的贡献为3*(20+)  //3*(10*3+1)
 *4的贡献为4*(6)  //4*(6)
 *第二部分贡献计算:1234
 *4无贡献
 *3的贡献为3*1,123
 *2的贡献为2*(20+1),124+12
 *1的贡献为1*(300+20+1),134+14+1
*/

