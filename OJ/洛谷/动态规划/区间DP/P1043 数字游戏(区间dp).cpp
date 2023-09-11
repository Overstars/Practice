//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
ll a[maxn],sum[maxn],dp[maxn][maxn][11],dp2[maxn][maxn][11];
ll f(int l,int r)
{
	return ((sum[r]-sum[l-1])%10+10)%10;
}
signed main(int argc, char const *argv[])
{//将[i,j]分成k段的最大值
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{//n个数字分成m块
		cin>>a[i];
		a[i+n]=a[i];
	}
	ll len=2*n,MAX=0,MIN=inf;
	for(int i=1;i<=len;i++)
		sum[i]=sum[i-1]+a[i];
	fill(dp2[0][0],dp2[0][0]+maxn*maxn*11,400000000);
	for(int l=1;l<=len;l++)
		for(int i=1;i<=len-l+1;i++)
		{//一定要初始化好
			int j=i+l-1;
			dp[i][j][1]=dp2[i][j][1]=f(i,j);
//			printf("dp[%d][%d][%d]=%lld,dp2=%lld\n",i,j,1,dp[i][j][1],dp2[i][j][1]);
		}
	for(int i=2;i<=m;i++)
	{//i块
		for(int j=2;j<=len;j++)
		{//长度
			if(j<i)
				continue;
			for(int l=1;l<=len-j+1;l++)
			{//[l,r],分成i段
				int r=l+j-1;
				for(int k=l;k<r;k++)
				{//断点
					dp[l][r][i]=max(dp[l][r][i],dp[l][k][i-1]*f(k+1,r));
					dp2[l][r][i]=min(dp2[l][r][i],dp2[l][k][i-1]*f(k+1,r));
				}
//				printf("dp[%d][%d][%d]=%lld,dp2=%lld\n",l,r,i,dp[l][r][i],dp2[l][r][i]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		MAX=max(MAX,dp[i][n+i-1][m]);
		MIN=min(MIN,dp2[i][n+i-1][m]);
	}
	cout<<MIN<<'\n'<<MAX<<endl;
	return 0;
}


