//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=55,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn];
ll dp[maxn][maxn][maxn];
double f[maxn]={1};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,p,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	cin>>p;
	if(sum<=p)
		return cout<<n<<endl,0;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]*i;
	double ans=0;
	for(int x=1;x<=n;x++)
	{//第x号为恰好进不去的人
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{//前i个人
			for(int j=0;j<=i;j++)
			{//在装第j个人
				for(int k=0;k<=p;k++)
				{
					if(i==x)//直接跳过
					{
						dp[i][j][k]=dp[i-1][j][k];
						continue;
					}
					dp[i][j][k]=dp[i-1][j][k];
					if(k>=a[i]&&j>0)
						dp[i][j][k]+=dp[i-1][j-1][k-a[i]];
				}
			}
		}
		for(int j=1;j<n;j++)
			for(int k=max(0,p-a[x]+1);k<=p;k++)
				ans+=j*f[j]*f[n-j-1]*dp[n][j][k];
	}
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans/f[n]<<endl;
	return 0;
}
/*
 * 2021-05-04-23.24.21
 * dp[i][j][k]为前i个人选出j个体积为k的方案数
 * 总方案数为n!
 * 每种方案数的长度贡献不一样
 * 枚举第一个进不去的人x,进去的人为j,未进去的n-j人
 * 但是固定x为第一个进不去的,后面n-j-1可以任意排列
*/

