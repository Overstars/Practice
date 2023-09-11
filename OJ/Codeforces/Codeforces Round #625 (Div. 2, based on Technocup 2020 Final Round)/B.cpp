#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll b[maxn],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];//选取的相邻两个b之间的差要等于下标差
	map<ll,ll>mp;
	for(int i=1;i<=n;i++)
	{
		mp[b[i]-i]+=b[i];//差值恒定
		ans=max(ans,mp[b[i]-i]);
	}
	cout<<ans<<endl;
	return 0;
}


