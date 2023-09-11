//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=305,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn][maxn];
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
		memset(a,0,sizeof(a));
//		for(int i=1;i<=n&&k;i++)
//			a[i][i]=1,k--;
		ll c=0,ans=0;
		while(k)
		{
			for(int i=0;i<n;i++)
			{
				int x=i,y=(i+c)%n;
				a[x][y]=1;
				if(--k==0)
					goto label;
			}
			c++;
		}
		label:
		ll ma=LLONG_MIN,mi=LLONG_MAX;
		for(int i=0;i<n;i++)
		{
			ll now=0;
			for(int j=0;j<n;j++)
				if(a[i][j])
					now++;
			ma=max(ma,now);
			mi=min(mi,now);
		}
		ans+=(ma-mi)*(ma-mi);
		ma=LLONG_MIN,mi=LLONG_MAX;
		for(int i=0;i<n;i++)
		{
			ll now=0;
			for(int j=0;j<n;j++)
				if(a[j][i])
					now++;
			ma=max(ma,now);
			mi=min(mi,now);
		}
		ans+=(ma-mi)*(ma-mi);
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}


