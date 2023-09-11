#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2005,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,h,l,r;
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//dp[i][j]表示第i次入睡后时间余数为j的最大值
	for(int i=1;i<h;i++)
		dp[0][i]=-inf;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int c=a[i];
		for(int j=0;j<h;j++)
		{
			int t1=(j-c+h)%h,t2=(j-c+1+h)%h,val=(j>=l&&j<=r?1:0);
			dp[i][j]=max(dp[i-1][t1]+val,dp[i-1][t2]+val);
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	for(int i=0;i<h;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
/*
 *一天有h小时,在[l,r]区间内入睡才有贡献
 *可以在ai和ai-1二选一
*/

