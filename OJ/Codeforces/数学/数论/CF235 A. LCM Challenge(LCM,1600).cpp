#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
const int MAXN=1e6+6;
int prime[MAXN+1],psize;//psize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist(void)
{
	memset(isprime,1,sizeof(isprime));
	psize=0;
	isprime[1]=false;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++psize]=i;
		for(int j=1;j<=psize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	getlist();
	ll n;
	cin>>n;
	if(n<4)
	{
		if(n==1||n==2)
			cout<<n<<endl;
		else if(n==3)
			cout<<6<<endl;
	}
	else if(n&1)
		cout<<n*(n-1)*(n-2)<<endl;
	else{
		ll tmp=(n-2)/2;
		for(ll i=n-2;i>=(n-2)/2;i--)
		{
			if(isprime[i]&&n%i&&(n-1)%i)
			{
				tmp=i;
				break;
			}
		}
//		printf("tmp=%lld\n",tmp);
		ll ans=max(n*(n-1)*tmp,(n-1)*(n-2)*(n-3));
		ans=max(ans,n*(n-1)*(n-3)/(gcd(n,n-3)*gcd(n-1,n-3)));
		cout<<ans<<endl;
	}
	return 0;
}


