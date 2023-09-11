//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	map<ll,ll>mp[2];
	int n;
	cin>>n;//有多少偶数长度的
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll pre=0,ans=0;
	mp[0][0]++;
	for(int i=1;i<=n;i++)
	{
		ll odd=i&1;
		pre^=a[i];
		ans+=mp[odd][pre];
		mp[odd][pre]++;
//		printf("%d:ans=%d\n",odd,ans);
	}
	cout<<ans<<endl;
	return 0;
}


