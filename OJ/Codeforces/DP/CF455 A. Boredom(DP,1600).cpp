#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll a[maxn],dp[maxn],cnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,ans=0,lim=0;//dp[i]拿掉i后得到的点数
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lim=max(lim,a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=lim;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+i*cnt[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}


