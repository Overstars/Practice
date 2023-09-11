#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int a[maxn],sum[maxn];
int main()
{
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,ans=0;
	map<int,int>mp;
	cin>>n;
	mp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
//		printf("sum[%lld]=%d,ans=%lld\n",i,sum[i],ans);
		ans+=mp[sum[i]];
		mp[sum[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}


