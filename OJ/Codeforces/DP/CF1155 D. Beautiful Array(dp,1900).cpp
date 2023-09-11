//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn];
void solve(int n,int x)
{
	ll dp[3]={0},ans=0;
	for(int i=1;i<=n;i++)
	{
		dp[0]=max(0ll,dp[0]+a[i]);//头
		dp[1]=max(dp[0],dp[1]+x*a[i]);//乘x
		dp[2]=max(dp[1],dp[2]+a[i]);//尾
		ans=max(ans,dp[2]);
	}
	cout<<ans<<endl;
	exit(0);
}
int dp[maxn],l[maxn],r[maxn],s[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve(n,x);
	for(int i=1;i<=n;i++)
	{//(左数量+1)*(右数量+1)
		dp[i]=(i)*(n-i+1)*a[i];
		s[i]=s[i-1]+dp[i];
		fprintf(stderr,"dp[%lld]=%lld\n",i,dp[i]);
	}
	ll sum=0,ans,val=0,l=0,r=0,ansr=0,ansl=0;
	if(x<0)
	{//求最小<0子段
		for(int i=1;i<=n;i++)
		{
			sum+=dp[i];
			if(sum>0)
			{
				sum=0;
				l=i+1;
			}
			if(sum<val)
			{
				val=sum;
				ansl=l;
				ansr=i;
			}
		}
		ans=s[n]-s[r]+s[l-1]+x*(s[r]-s[l-1]);
	}
	else{//求最大子段
		for(int i=1;i<=n;i++)
		{
			sum+=dp[i];
			if(sum<0)
			{
				sum=0;
				l=i+1;
			}
			if(sum>val)
			{
				val=sum;
				ansl=l;
				ansr=i;
			}
		}
		ans=s[n]-s[r]+s[l-1]+x*(s[r]-s[l-1]);
	}
	ans=max(ans,s[n]);
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-04-18-15.53.20
 * 让负变->正
 * 读了假题意,以为要算每一个数的贡献
*/

