//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=20010,inf=0x3f3f3f3f,mod=1000000007;
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
//struct node
//{
//	int p,l,h;//位置,下沿,上沿
//} pipe[maxn];
int x[maxn],y[maxn],p[maxn][2],dp[maxn][1005],sum[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(dp,inf,sizeof(dp));
	int n,m,o,len=0;//长度,高度,管道数量
	cin>>n>>m>>o;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i],p[i][1]=m+1;
	p[n][1]=m+1;
	for(int i=1,q,l,h;i<=o;i++)
	{
		cin>>q>>l>>h;
		p[q][0]=l,p[q][1]=h;
		sum[q]++;
	}
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
	for(int i=1;i<=m;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{//x轴
		for(int j=1;j<=m;j++)
		{//y轴,到达dp(i,j)位置的最小点击次数
			if(j<=p[i][0]||j>=p[i][1])//(i,j)是墙
				continue;
//			if(j+y[i-1]<p[i-1][1])//不点击,掉落
//				dp[i][j]=min(dp[i][j],dp[i-1][j+y[i-1]]);
//			if(j>=x[i-1])
//			{//完全背包
//				dp[i][j]=min(dp[i][j],dp[i-1][j-x[i-1]]+1);
//				dp[i][j]=min(dp[i][j],dp[i][j-x[i-1]]+1);
//			}
			if(j==m)
			{//完全背包,一步到m
				for(int k=j-x[i-1];k<=m;k++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+1);
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
//					int cnt=max(1,(j-k)/x[i-1]+((j-k)%x[i-1]?1:0));
//					dp[i][j]=min(dp[i][j],dp[i-1][k]+cnt);
				}
			}
//			for(int k=j-x[i-1],cnt=1;k>p[i-1][0];k-=x[i-1],cnt++)//枚举上一步高度
//			{
//				if(k>p[i-1][1])//越过上界
//					continue;
//				dp[i][j]=min(dp[i][j],dp[i-1][k]+cnt);
//			}
			if(dp[i][j]<inf)
				len=i;
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
//			int l=max(0,(y[i-1]-j)/x[i-1]),r=(m+y[i-1]-j)/x[i-1];
//			for(int k=l;k<=r;k++)
//			{//点击次数
//				if(j<p[i][0]||j>p[i][1])
//					continue;
//			}
		}
		for(int j=p[i][0]+1;j<p[i][1];j++)
			if(j+y[i-1]<=m)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j+y[i-1]]);
				if(dp[i][j]<inf)
					len=i;
			}
		for(int j=1;j<=p[i][0];j++)
			dp[i][j]=inf;
		for(int j=p[i][1];j<=m;j++)
			dp[i][j]=inf;
	}
	int ans=-1;
	for(int i=1;i<=m;i++)
		if(dp[n][i]<inf&&(ans==-1||dp[n][i]<ans))
			ans=dp[n][i];
	if(ans>=0)
		cout<<1<<'\n'<<ans<<endl;
	else{
		cout<<0<<'\n'<<sum[len]<<endl;
	}
	return 0;
}


