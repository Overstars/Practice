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
ll a[maxn],cnt[66];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;1<<(j-1)<=a[i];j++)
		{
			if(a[i]&(1<<(j-1)))
				cnt[j]++;
		}
	}
	for(int i=1;i<32;i++)
	{
		ans+=(cnt[i]*cnt[i])*(1<<(i-1));
	}
	cout<<ans<<endl;
	return 0;
}


