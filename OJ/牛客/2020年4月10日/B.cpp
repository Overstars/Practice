#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll ans=0;
		if(n>m)
			swap(n,m);
		while(n*2<m)
		{
			n*=2;
			ans++;
		}
		if(n==m)
		{
			cout<<ans+n<<endl;
			continue;
		}
		ll x=2*n-m;//吃x天,m为n的二倍,m-x个
		ans+=1+m;//翻倍的一天
		cout<<ans<<endl;
	}
	return 0;
}


