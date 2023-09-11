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
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],dp[maxn][2],cnt[maxn][2];
pii check(int n,int k)
{
	int sum=0,num=0;
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++)
		a[i]-=k;
	for(int i=1;i<=n;i++)
	{//不能相邻
		if(dp[i-1][0]>dp[i-1][1])
		{//不选
			dp[i][0]=dp[i-1][0];
			cnt[i][0]=cnt[i-1][0];
		}
		else{
			dp[i][0]=dp[i-1][1];
			cnt[i][0]=cnt[i-1][1];
		}
		dp[i][1]=dp[i-1][0]+a[i];
		cnt[i][1]=cnt[i-1][0]+1;
	}
	if(dp[n][0]>dp[n][1])
		sum=dp[n][0],num=cnt[n][0];
	else
		sum=dp[n][1],num=cnt[n][1];
	for(int i=1;i<=n;i++)
		a[i]+=k;
	return make_pair(sum,num);
}
signed main(signed argc, char const *argv[])
{
//	#define DEBUG
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P1484_7.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=-1e6+5,r=1e6+5,ans=-1,ans2=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;//当前斜率k
		pii now=check(n,mid);
		int b=now.ff,x=now.ss;//截距b,切点x
//		printf("k = %lld, b=%lld, x=%lld\n",mid,b,x);
		if(x>=m)//b=g(x)-kx
		{//让斜率变大,使得切点左移,即种树的收益变小
			ans=b+mid*m;
			l=mid+1;
		}
		else{//在合法范围内
			ans2=max(ans2,b+mid*x);
			if(mid>0)
				r=mid-1;
			else
				l=mid+1;
		}
	}
	if(ans==-1)
	{//
		pii now=check(n,0);
		if(now.ss<=m)
			ans=max(0ll,now.ff);
	}
	cout<<max(ans,ans2)<<endl;
	return 0;
}
/*
 * 2021-05-01-11.47.10
 * 令g(x)为种x棵树时取得的最大收益
 * 是一个上凸包,求[1,k]区间的最大值
 * 应该让斜率更接近0吧?
*/

