#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
long long qmod(long long a,long long b)  //快速幂
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
	ll a,b,c;
	cin>>a>>b>>c;
	vector<ll>ans;
	for(ll i=1;i<=81;i++)//枚举s(x)
	{
		ll x=b*qmod(i,a)+c;//尝试用s(x)凑出x来
		if(x<=0||x>=1e9)
			continue;
		string tar=to_string(x);
		for(ll j=0,tot=0;j<tar.length();j++)
		{
			tot+=tar[j]-'0';
			if(tot==i&&j==tar.length()-1)
				ans.push_back(x);
		}
	}
	cout<<ans.size()<<endl;
	for(ll &i:ans)
		cout<<i<<' ';
	return 0;
}


