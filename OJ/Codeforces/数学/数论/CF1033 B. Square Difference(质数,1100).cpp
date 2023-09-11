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
bool prime(ll x)
{
	if(x <= 1)
		return 0;
	if( x == 2 || x == 3 || x == 5 )
		return 1;
	if( x%2 == 0 || x%3 == 0 )	/*判断是否为2,3的倍数*/
		return 0;
	ll lim=sqrt((float)x)+1;
	for(ll i=6; i<=lim; i += 6 ){//这里可能会有错
		if( x % (i-1) == 0 || x % (i+1) == 0 )
			return 0;
	}
	return 1;
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
	ll t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a-b!=1||!prime(a+b))
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}


