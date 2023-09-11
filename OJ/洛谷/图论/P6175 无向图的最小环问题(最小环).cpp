#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn][maxn],mp[maxn][maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	memset(dp,inf,sizeof(dp));
//	memset(mp,inf,sizeof(mp));
	int n,m,u,v,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=mp[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>d;
		dp[u][v]=dp[v][u]=mp[u][v]=mp[v][u]=min(dp[u][v],d);
	}
	int ans=inf;
	for(int k=1;k<=n;k++)
	{//i->k->j->i
		for(int i=1;i<k;i++)//k为这个环上最大点,直接连接i与j
			for(int j=i+1;j<k;j++)//dp[i][j]表示<i,j>只经过1~k-1优化的最短路
				ans=min(ans,dp[i][j]+mp[i][k]+mp[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)//如果经过k可以优化,那么它之前一定不经过k
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	}
	if(ans==inf)
		cout<<"No solution."<<endl;
	else
		cout<<ans<<endl;
	return 0;
}


