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
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)>0){
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
	ll t,a;
	cin>>t;
	while(t--)
//	for(ll a=511;a<1e8;a=a*2+1)
	{
		cin>>a;
		bool flag=0;
		for(ll i=1;i<=26;i++)
		{
			if((1ll<<(i-1))-1==a)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			ll tmp=a;
			vector<ll>rec;
			for(ll i=2;i*i<=tmp;i++)
			{
				if(tmp%i==0)
				{
					rec.push_back(i);
					while(tmp%i==0)
						tmp/=i;
				}
			}
			if(tmp>1)
				rec.push_back(tmp);
			cout<<a/rec[0]<<endl;
		}
		else{
			for(ll i=26;i>=1;i--)
			{
				if(a&(1ll<<(i-1)))
				{
					cout<<(1ll<<i)-1<<endl;
					break;
				}
			}
		}
//		ll ans=0;
//		for(ll i=1;i<a;i++)
//		{
////			cout<<a<<"^"<<i<<":"<<(bitset<8>)(a^i)<<",&:"<<(bitset<8>)(a&i)<<endl;
//			if((a^i)==0||(a&i)==0)
//			{
//				ans=max(ans,max(a^i,a&i));
//				continue;
//			}
//			ans=max(ans,gcd(a^i,a&i));
//		}
//		cout<<"ans["<<a<<"]="<<ans<<endl;
//		cout<<ans<<endl;
	}
	return 0;
}


