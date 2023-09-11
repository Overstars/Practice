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
ll a[maxn]={4,7,44,77,444,777,4444,7777,44444,77777,444444,777777,4444444,7777777,44444444,77777777,444444444,777777777,4444444444,7777777777};
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll l,r,ans=0;
//	for(int i=0;i<20;i++)
//		printf("%lld\n",a[i]);
	cin>>l>>r;
	while(l<=r)
	{
		ll nex=*lower_bound(a,a+20,l);
		if(nex>=r)
		{
			ans+=(r-l+1)*nex;
			break;
		}
		else{
			ans+=(nex-l+1)*nex;
			l=nex+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}


