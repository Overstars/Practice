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
ll n,m,q,g,sx,sy,ex,ey;
ll getpos(ll x,ll y)
{
	if(x==1)
		return (y-1)/(n/g);//内圈在n/g处截断
	else
		return (y-1)/(m/g);//外圈在m/g处截断
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
	cin>>n>>m>>q;
	g=__gcd(n,m);
	while(q--)
	{
		cin>>sx>>sy>>ex>>ey;
		ll s=getpos(sx,sy),e=getpos(ex,ey);
		cout<<(s==e?"YES\n":"NO\n");
	}
	return 0;
}


