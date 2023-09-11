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
ll a[maxn],w[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll ans=0;
		int l=1,r=n,cnt=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=k;i++)
		{
			cin>>w[i];
			if(w[i]==1)
				cnt++;
		}
		sort(w+1,w+k+1,greater<ll>());
		for(int i=1;i<=cnt;i++)
			ans+=a[r--]*2;
		for(int i=1;i<=k-cnt;i++)
		{
//			printf("w[%d]=%lld\n",i,w[i]);
			ll now=a[r--];
			if(w[i]==1)
				ans+=now*2;
			else
				ans+=now+a[l];
			l+=w[i]-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
// 26,19,48
100
5 2
2 4 6 8 10
3 2

7 2
1 2 3 4 5 6 7
2 5

5 4
3 5 5 5 10
1 1 2 1
*/

