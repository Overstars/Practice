#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	string s;
	ll n,ans=0;
	cin>>s;
	if(s.length()>1)
		n=(ll)((s[s.length()-2]-'0')*10+s[s.length()-1]-'0');
	else
		n=(ll)(s[s.length()-1]-'0');
//	if(n>0)//很奇怪
	{
		n%=4;
		if(n==0)
			n=4;
		for(ll i=1;i<5;i++)
			ans=(ans+qmod(i,n,5))%5;
	}
	cout<<ans<<endl;
	return 0;
}


