//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll fun(ll x)
{
	ll ret=0;
	while(x)
	{
		ret+=x%10;
		x/=10;
	}
	return ret;
}
ll get(ll x)
{
	ll ret=0;
	while(x)
	{
		ret=ret*10+x;
		x-=9;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		bool ok=0;
		if(n<(k-1)*k/2)
		{
			printf("-1\n");
			continue;
		}
		for(ll i=0;!ok;i++)
		{
			ll sum=0,now=fun(i);
			for(ll j=0;j<=k;j++)
				sum+=fun(i+j);
			if(sum==n)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}


