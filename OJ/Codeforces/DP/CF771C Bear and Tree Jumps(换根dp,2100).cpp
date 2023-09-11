//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
/*
 *sum[x][y]表示x子树上距离x模k为y的节点的数量
 *dp[x][y]表示x子树上距离x模k为y的节点的路程贡献
*/
int dep[maxn],sum[maxn][6],dp[maxn][6],dp2[maxn],k,ans=0;
vector<int>G[maxn];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	sum[x][0]=1;
//	dp[x]=dep[x]/k+(dep[x]%k?1:0);
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
//		dp[x][1]++;
		for(int i=0;i<k;i++)
		{//0再向上会突破一级
			dp[x][i]+=dp[v][(i-1+k)%k];
			sum[x][i]+=sum[v][(i-1+k)%k];
		}
		if(k>1)
			dp[x][1]+=sum[v][0];//步数全部+1
		else
			dp[x][0]+=sum[v][0];
	}
//	for(int i=0;i<k;i++)
//		printf("dp[%d][%d]=%d\n",x,i,dp[x][i]);
}
int ret[maxn][6];//表示到x点模数为y的点的个数
void dfs2(int x,int fa)
{//转移下来时,x补树上距离为0的点贡献+1
	if(x!=1)
	{
		dp2[x]=dp2[fa];
		dp2[x]+=ret[fa][0]-sum[x][(k-1+k)%k];//x补树上到fa距离为0的点贡献+1
		dp2[x]-=sum[x][0];//x子树上所有到x为0的点贡献-1
	}
//	for(int i=0;i<k;i++)
//		printf("ret[%lld][%lld]=%lld\n",x,i,ret[x][i]);
//	cerr<<"dp2["<<x<<"] = "<<dp2[x]<<endl;
	ans+=dp2[x];
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		for(int i=0;i<k;i++)
		{//先假设上一层所有点距离增大,0->1
			ret[v][i]=ret[x][(i-1+k)%k];//子树是错误的,下面两行修正
			ret[v][i]-=sum[v][(i-2+k)%k];//虚假的子树,
			ret[v][i]+=sum[v][i];//真正的子树
		}
		dfs2(v,x);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	if(n==2)
//		return cout<<1<<endl,0;
	dep[0]=-1;
	dfs(1,0);
	for(int i=0;i<k;i++)
	{
		dp2[1]+=dp[1][i];
		ret[1][i]=sum[1][i];
	}
//	#define wtf
	#ifdef wtf
	ans+=dp2[1];
	for(int &v:G[1])
		dfs2(v,x);
	#endif // wtf
	dfs2(1,1);
	cout<<ans/2<<endl;
	return 0;
}
/*
 *可以从u点一次跳到任何与当前节点不超过k的节点
 *f[u,v]为u->v最少次数,求对所有点对的f总和
 *换根dp,以根节点深度为0dfs,f[v]=dep[v]
 *k很小的时候才容易转移,记录对k取模后的余数
 *dp[x][k]表示在以x为根的子树上距离为k的节点的步数和
*/

