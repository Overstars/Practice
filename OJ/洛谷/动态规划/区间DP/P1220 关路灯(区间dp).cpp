//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=106,inf=0x3f3f3f3f,mod=1000000007;
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
ll dp[maxn][maxn][2],sum[maxn];
int p[maxn],w[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,c;
	cin>>n>>c;
	fill(dp[0][0],dp[0][0]+maxn*maxn*2,inf);
	for(int i=1;i<=n;i++)
		cin>>p[i]>>w[i],sum[i]=sum[i-1]+w[i];
	dp[c][c][0]=dp[c][c][1]=0;
	//dp[l][r][0]表示关掉[l,r]区间后,在左/右端点最小开销
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			int r=l+len-1;//目标区间[l,r]
			dp[l][r][0]=min({
				dp[l+1][r][0]+(sum[n]-sum[r]+sum[l]-sum[0])*(p[l+1]-p[l]),//[l+1,r,0]向左扩展
				dp[l+1][r][1]+(sum[n]-sum[r]+sum[l]-sum[0])*(p[r]-p[l]),//[l+1,r,1]跑到左端点
				dp[l][r-1][0]+(sum[n]-sum[r-1]+sum[l-1]-sum[0])*(p[r]-p[l])+(sum[n]-sum[r]+sum[l-1]-sum[0])*(p[r]-p[l]),//[l,r-1,0]跑到右端点再跑回来
				dp[l][r-1][1]+(sum[n]-sum[r-1]+sum[l-1]-sum[0])*(p[r]-p[r-1])+(sum[n]-sum[r]+sum[l-1]-sum[0])*(p[r]-p[l])//[l,r-1,1]向右扩展再跑左端点
			});
			dp[l][r][1]=min({
				dp[l][r-1][1]+(sum[n]-sum[r-1]+sum[l-1]-sum[0])*(p[r]-p[r-1]),//[l,r-1,1]向右扩展
				dp[l][r-1][0]+(sum[n]-sum[r-1]+sum[l-1]-sum[0])*(p[r]-p[l]),//[l,r-1,0]跑到右端点
				dp[l+1][r][1]+(sum[n]-sum[r]+sum[l]-sum[0])*(p[r]-p[l])+(sum[n]-sum[r]+sum[l-1]-sum[0])*(p[r]-p[l]),//[l+1,r,1]跑到左端点再跑回来
				dp[l+1][r][0]+(sum[n]-sum[r]+sum[l]-sum[0])*(p[l+1]-p[l])+(sum[n]-sum[r]+sum[l-1]-sum[0])*(p[r]-p[l])//[l+1,r,0]向左扩张再跑到右端点
			});
//			fprintf(stderr,"dp[%d,%d]=%lld\n",l,r,min(dp[l][r][0],dp[l][r][1]));
		}
	}
	cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
	return 0;
}
/*
 * 2021-04-18-10.02.29
 * 如何统计区间外所有路灯在逛该时的额外消费？
 * 之前是额外dp时间,非常的迷
 * 也许可以直接一起dp,将[1,l]+[r,n]的开销也计入花费
*/
//以下废稿
//ll dp[maxn][maxn],dp2[maxn][maxn][2],sum[maxn];//[l,r]区间最后一步在左/右,已经花费的最小时间
//int p[maxn],w[maxn];
//signed main(signed argc, char const *argv[])
//{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
//	//	freopen("output.out", "w", stdout);
//	#endif
//	int n,c;
//	cin>>n>>c;
//	fill(dp[0],dp[0]+maxn*maxn,(ll)inf);
//	fill(dp2[0][0],dp2[0][0]+maxn*maxn*2,(ll)inf);
//	for(int i=1;i<=n;i++)
//	{
//		cin>>p[i]>>w[i];
//		sum[i]=sum[i-1]+p[i];
//	}
//	dp[c][c]=0;
////	dp2[c][c][0]=dp2[c][c][1]=0;
//	for(int len=2;len<=n;len++)
//	{
//		for(int l=1;l<=n-len+1;l++)
//		{
//			int r=l+len-1;
////			if((dp2[l][r-1][1]+p[r]-p[r-1])*w[r]<dp[l][r])
////			{
////				dp2[l][r][1]=min(dp2[l][r][1],min(dp2[l][r-1][0],dp2[l][r-1][1])+p[r]-p[r-1]);
////				dp2[l][r][0]=min(dp2[l][r][0],min(dp2[l][r-1][0],dp2[l][r-1][1])+p[r]-p[l]);
////				dp[l][r]=(dp2[l][r-1][1]+p[r]-p[r-1])*w[r];
////			}
////			if((dp2[l+1][r][0]+p[l+1]-p[l])*w[l]<dp[l][r])
////			{
////				dp2[l][r][0]=min(dp2[l][r][0],min(dp2[l+1][r][0],dp2[l+1][r][1])+p[l+1]-p[l]);
////				dp2[l][r][1]=min(dp2[l][r][1],min(dp2[l+1][r][0],dp2[l+1][r][1])+p[r]-p[l]);
////				dp[l][r]=(dp2[l+1][r][0]+p[l+1]-p[l])*w[l];
////			}
////			fprintf(stderr,"dp2[%d][%d]=%d\n",l,r,dp2[l][r]);
//			fprintf(stderr,"dp[%d][%d]=%d\n",l,r,dp[l][r]);
////            dp[l][r]=min(dp[l][r-1]+(p[r]-p[r-1])*w[r],dp[l+1][r]+(p[l+1]-p[l])*w[l]);
//		}
//	}
//	cout<<dp[1][n]<<endl;
//	return 0;
//}
/*
 * 2021-04-17-10.47.00
 * 使得消耗总功率最低
 * 时间怎么计算
*/

