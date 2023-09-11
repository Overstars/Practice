//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
	return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) % mod)%mod;
}
void initccc()
{
	fac[0] = 1;
	for (int i = 1; i <maxn ;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
}
ll qmod(ll a,ll b)  //快速幂
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	initccc();
	ll d,u,v;
	cin>>d>>t;
	ll now=d;
	vector<ll>rec;
	map<ll,ll>mp;
	for(ll i=2;i*i<=now;i++)
	{
		if(now%i==0)
		{
			rec.push_back(i);
			while(now%i==0)
			{
				now/=i;
//				rec[rec.size()-1].ss++;
			}
		}
	}
	if(now>1)
		rec.push_back(now);
	while(t--)
	{
		cin>>u>>v;
		ll g=__gcd(u,v),n1=0,n2=0;
		ll now=u/g,tot=0;
		vector<ll>fff;
		for(ll &x:rec)
		{//要把路线上的因子做排列
			if(now%x==0)
			{
				ll cnt=0;
				while(now%x==0)
				{
					now/=x;
					cnt++;
				}
				fff.push_back(cnt);
				tot+=cnt;
			}
		}
		n1=fac[tot];
		for(ll &x:fff)
			n1=(n1*qmod(fac[x],mod-2)%mod);
		fff.clear();
		now=v/g,tot=0;
		for(ll &x:rec)
		{//要把路线上的因子做排列
			if(now%x==0)
			{
				ll cnt=0;
				while(now%x==0)
				{
					now/=x;
					cnt++;
				}
				fff.push_back(cnt);
				tot+=cnt;
			}
		}
		n2=fac[tot];
		for(ll &x:fff)
			n2=(n2*qmod(fac[x],mod-2)%mod);
		cout<<n1*n2%mod<<endl;
	}
	return 0;
}
/*
 *https://www.luogu.com.cn/problem/CF1334E
 *可以发现两点之间权值只能是1或2
 *y/x=p,p为质数
 *当x|p或x=1时,y为1.否则为2
 *若u|v,则为u质因子集合-v质因子集合作排列(有相同多个元素)
 *否则abs(u与v每个质因子数量之差)做排列
 *感觉复杂度好高啊,应该在D上预处理吧
 *2020年11月10日接着写
 *例如d(4)=3,f(4)={1,2,4},d(12)=6,f(12)={1,2,3,4,6,12}
 *4原本有3个因子,[新增]一个质因子3后因子数量翻倍
 *结论,最短路线x->gcd(x,y)->y
 *这个式子是Edmond_Y推的%%%
*/

