#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=998244353;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
long long qmod(long long a,long long b,long long mod)  //快速幂
{
	long long ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1==1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得,要保证a>b
{//传递x,y的引用
    if(b == 0)
    {//推理1，终止条件
        x = 1;
        y = 0;
        return a;//找到gcd,一路返回上去
    }
    ll r = exgcd(b, a%b, x, y);
    //先得到更底层的x2,y2,再根据计算好的x2,y2计算x1，y1。
    //推理2，递推关系x1=y2,y1=x2-(a/b)*y2;
    ll t = y;
    y = x - (a/b) * y;//(a/b)向下取整
    x = t;
//    printf("x1=%d,y1=%d,r=%d\n",x,y,r);
    return r;
}
ll inv1(ll a,ll mod)//扩展欧几里得求逆元
{//mod可为非素数
    ll x,y;
    exgcd(a,mod,x,y);
    return (x%mod+mod)%mod;//防止出现负数的情况
}
ll a[maxn],pre[maxn]={1};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=(pre[i-1]*a[i])%mod;
	}
	ll ans=0;
	for(int i=k;i<=n;i++)
	{
		printf("%lld,%lld,ans=%lld\n",pre[i],inv1(pre[i-k],mod),ans);
		ans=max(ans,(pre[i]*inv1(pre[i-k],mod))%mod);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 3
0 1 2 3 0
*/


