//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll a[maxn],s[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll ans=0;
	map<ll,ll>mp;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];//分成连续的三部分
	if(s[n]%3)//不能分成三份
		return cout<<0<<endl,0;
	ll sum=s[n]/3;
	for(int i=1,pre=0;i<n;i++)
	{
		if(s[i]==2*sum)
			ans+=pre;
		if(s[i]==sum)
			pre++;
	}
	cout<<ans<<endl;
//	int l=1,r=0;
//	for(int l=1,r=0;r<=n;l++)
//	{
//		while(s[r]!=2*sum)
//			r++;
//
//	}
//	if(sum==0)
//		cout<<(mp[0]-1)*(mp[0]-2)/2<<endl;//C(n-1,2)
//	else
//		cout<<mp[sum]*mp[2*sum]<<endl;
	return 0;
}


