//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll a,b,t,x,y,g;
	read(a,b,t);
//	cin>>a>>b>>t;
	g=__gcd(a,b);
	vector<ll>v;
	for(ll i=1;i*i<=g;i++)
		if(g%i==0)//找所有约数
			v.push_back(i),v.push_back(g/i);
	sort(v.begin(),v.end());
	while(t--)
	{
		read(x,y);
//		cin>>x>>y;
		ll ans=*(upper_bound(v.begin(),v.end(),y)-1);
//		printf("%lld\n",ans);
		printf("%lld\n",(ans<x)?-1:ans);
	}
	return 0;
}


