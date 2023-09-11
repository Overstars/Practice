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
vector<ll>luck;
void dfs(ll x)
{
	if(x>5e9)
		return;
	luck.push_back(x);
	dfs(x*10+4);
	dfs(x*10+7);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	dfs(0);
	sort(luck.begin(),luck.end());
	cout<<luck.size()<<endl;
	ll l,r,ans=0;
	cin>>l>>r;
	while(l<=r)
	{
		ll nex=*lower_bound(luck.begin(),luck.end(),l);
		if(nex>=r)
		{
			ans+=(r-l+1)*nex;
			break;
		}
		ans+=(nex-l+1)*nex;
		l=nex+1;
	}
	cout<<ans<<endl;
	return 0;
}


