//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn],h[maxn],dp[maxn][2],cnt[maxn][2];
pii check(int n,int k)
{
	int sum=0,num=0;
	for(int i=1;i<=n;i++)
		h[i]-=k;
	for(int i=1;i<=n;i++)
	{
		if(dp[i-1][0]<dp[i-1][1])
		{
			dp[i][0]=dp[i-1][0];
			cnt[i][0]=cnt[i-1][0];
		}
		else{
			dp[i][0]=dp[i-1][1];
			cnt[i][0]=cnt[i-1][1];
		}
		dp[i][1]=dp[i-1][0]+h[i];//代价
		cnt[i][1]=cnt[i-1][0]+1;
	}
	if(dp[n][0]<dp[n][1])
	{
		sum=dp[n][0];
		num=cnt[n][0];
	}
	else{
		sum=dp[n][1];
		num=cnt[n][1];
	}
	for(int i=1;i<=n;i++)
		h[i]+=k;
	return make_pair(sum,num);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		h[i-1]=a[i]-a[i-1];
	int l=0,r=1e9+5,ans=LLONG_MAX;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		pii now=check(n-1,mid);
//		printf("b=%lld , k=%lld, cnt=%lld\n",now.ff,mid,now.ss);
		if(now.ss<k)
		{
			l=mid+1;
		}
		else{
			ans=now.ff+mid*k;
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
2
4
1 1000000000 1000000001 2000000000
g(1)=1,g(2)=2e9,斜率增长离谱
*/
/*
 * 2021-05-02-10.01.40
 * g(x)关于选择数量x是一个下凸包的右半部分
 * 斜率递减的时候保留答案,非常诡异
*/

