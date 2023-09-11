//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
int a[maxn],dp[maxn],f[maxn],sum[maxn];
int q[maxn],h=1,t=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P2627_2.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	q[++t]=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&q[h]<i-k)
			h++;
		f[i]=max(f[i-1],dp[i-1]);
		while(h<=t&&f[q[t]]-sum[q[t]]<=f[i]-sum[i])
			t--;
		q[++t]=i;
		dp[i]=f[q[h]]-sum[q[h]]+sum[i];
//		printf("dp[%d] = %d\n",i,dp[i]);
	}
	cout<<max(dp[n],f[n])<<endl;
	return 0;
}
/*
 *dp[i]表示以i结尾且连续段不超过k长的最大值
 *在[i-k+1,i-1]之中必有一个不能选
 *令f[i]表示没有选择f[i]的最大值,f[i]=max(f[i-1],dp[i-1])
 *dp[i]=max_{0<=j<=k}{f[i-j]+sum[i]-sum[i-j-1]}
 *维护一个单调递减的队列
*/

