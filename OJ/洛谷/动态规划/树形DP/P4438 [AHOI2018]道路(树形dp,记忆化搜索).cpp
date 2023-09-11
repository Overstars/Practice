//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e4+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],b[maxn],n;
int lc[maxn],rc[maxn];
ll c[maxn],dp[maxn][45][45];
//vector<int>g[maxn],g2[maxn];
ll dfs(int x,int y,int z)
{//dp[x][y][z]表示从x到根节点有y条未修公路,z条未修铁路
	if(x>n)
	{
		x-=n;
		return c[x]*(a[x]+y)*(b[x]+z);
	}
	if(dp[x][y][z]!=INF)
		return dp[x][y][z];
	return dp[x][y][z]=min(dfs(lc[x],y+1,z)+dfs(rc[x],y,z),dfs(lc[x],y,z)+dfs(rc[x],y,z+1));
//	dfs(lc[x],y+1,z);//左儿子(多了一条公路)
//	dfs(rc[x],y,z+1);//右儿子(多了一条铁路)
//	for(int i=0;i<=y;i++)
//		for(int j=0;j<=z;j++)//修右儿子的铁路,修左儿子的公路
//			dp[x][i][j]=min(dp[lc[x]][i+1][j]+dp[rc[x]][i][j],dp[lc[x]][i][j]+dp[rc[x]][i][j+1]);
//	printf("dp[%d][%d][%d] = %lld\n",x,y,z,dp[x][y][z]);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(dp,INF,sizeof(dp));
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		lc[i]=(u>0)?u:-u+n;
		rc[i]=(v>0)?v:-v+n;
//		if(u>0)//公路
//			G[i].push_back(u);
//		else
//			G[i].push_back(-u+n);
//		if(v>0)//铁路
//			G[i].push_back(v);
//		else
//			G[i].push_back(-v+n);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
//		for(int j=0;j<=40;j++)
//			for(int k=0;k+j<=40;k++)
//			{
//				dp[i][j][k]=c[i]*(a[i]+j)*(b[i]+k);
////				printf("dp[%d][%d][%d] = %lld\n",i,j,k,dp[i][j][k]);
//			}
	}
	dfs(1,0,0);
	cout<<dp[1][0][0]<<endl;
	return 0;
}
/*
 *2021-04-09-20.54.08
 *一棵(n-1)+n二叉树,每个非叶子节点都有两个儿子
 *且这个点到儿子的两条边不一样,修理只能二选一
 *每个叶子有贡献c*(a+x)*(b+y)
 *x是该叶子到根节点
*/

