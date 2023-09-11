//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2505,inf=0x3f3f3f3f,mod=1000000007;
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
int p[maxn],dp[maxn],sum[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;//同一个机房膜拜人数差不超过m
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==1)
			sum[i]=sum[i-1]+1;
		else
			sum[i]=sum[i-1]-1;
	}
	memset(dp,inf,sizeof(dp));
//	for(int l=1;l<=n;l++)
//	{
//		dp[l][l]=1;
//		for(int i=1;i<=n-l+1;i++)
//		{
//			int j=i+l-1,num=sum[j]-sum[i-1];
//			if(num==l||num==0||abs(l-2*num)<=m)
//				dp[i][j]=1;
//			else{
//				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
//			}
//		}
//	}
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{//dp[i]表示[1,i]的最小分割数
		for(int j=1;j<=i;j++)
		{
			if(abs(sum[i]-sum[j-1])<=m||abs(sum[i]-sum[j-1])==i-j+1)
				dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}


