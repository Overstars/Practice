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
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int p[maxn],sum[maxn],dp[maxn],cnt[maxn];
//inline int w(int l,int r)
//{
//	int mid=(l+r)>>1;
//	return sum[r]+sum[l-1]-2*sum[mid]+(2*mid-l-r+1)*p[mid];
//}
pii check(int n,int k)
{//建造一个邮局的额外开销-k
	auto w = [](int l,int r)
	{//a[mid]处花费最小,左面贡献=,右面
		int mid=(l+r)>>1;
		return sum[r]+sum[l-1]-2*sum[mid]+(2*mid-l-r+1)*p[mid];
	};
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{//前i个村庄安放邮局后的最小代价
		for(int j=1;j<=i;j++)
		{//在[j,i]村庄安放一个邮局
			if(dp[j-1]+w(j,i)-k<dp[i])
			{
				dp[i]=dp[j-1]+w(j,i)-k;
				cnt[i]=cnt[j-1]+1;
			}
		}
	}
	return make_pair(dp[n],cnt[n]);
}
signed main(signed argc, char const *argv[])
{
//	#define DEBUG
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P4767_5.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	read(n,m);
//	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		read(p[i]);
//		cin>>p[i];
		sum[i]=sum[i-1]+p[i];
	}
//	vector<int> dp(n+1,inf),cnt(n+1,0);
//	sort(p+1,p+1+n);
	int l=-m*p[n]-10,r=10,ans=INF;
	while(l<=r)
	{
		int k=(l+r)>>1;
		for(int i=1;i<=n;i++)
			dp[i]=inf,cnt[i]=0;
		pii now=check(n,k);
//		printf("k = %d,b =%d,c = %d\n",k,now.ff,now.ss);
		if(now.ss<=m)
		{
			ans=now.ff+m*k;
			l=k+1;
		}
		else
			r=k-1;
	}
	printf("%d\n",ans);
//	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-05-04-20.08.31
 * 函数图像大概是下凸包求谷底,下凸包的左半部
 * 每造一个邮局额外花费-k的代价
*/

