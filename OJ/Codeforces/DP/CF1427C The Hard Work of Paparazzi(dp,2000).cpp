//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int t[maxn],x[maxn],y[maxn];
int dp[maxn],mx[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int r,n,ans=0;
	cin>>r>>n;
	x[0]=y[0]=1;//必须从(1,1)出发
	for(int i=1;i<=n;i++)
		cin>>t[i]>>x[i]>>y[i],dp[i]=-inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
				dp[i]=max(dp[i],dp[j]+1);
			if(dp[i]>=mx[j]+1)
				break;
		}
		mx[i]=max(mx[i-1],dp[i]);
	}
	cout<<mx[n]<<endl;
	return 0;
}


