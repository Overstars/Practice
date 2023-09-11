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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<5;i++)
	{
		ll a=n/5,b=m/5;
		if(n%5&&(n%5)>=i&&i!=0)
			a++;
		if(m%5&&m%5>=(5-i))
			b++;
//		printf("a=%lld,b=%lld\n",a,b);
		ans+=a*b;
	}
	cout<<ans<<endl;
	return 0;
}


