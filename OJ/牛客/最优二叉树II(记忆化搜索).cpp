//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=310,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],dp[maxn][maxn][maxn];
int dfs(int l,int r,int x)
{//以x为根的子树最小值(不包括x->v的权值)
	if(dp[l][r][x])
		return dp[l][r][x];
	if(l>=r)
		return dp[l][r][x]=0;
	int lval=inf,rval=inf;
	for(int i=l;i<x;i++)
	{
		lval=min(lval,dfs(l,x-1,i)+a[x]*a[i]);
	}
	if(l==x)
		lval=0;
	for(int i=x+1;i<=r;i++)
	{
		rval=min(rval,dfs(x+1,r,i)+a[x]*a[i]);
	}
	if(x==r)
		rval=0;
//	printf("dp[%lld][%lld][%lld]=%lld\n",l,r,x,lval+rval);
	return dp[l][r][x]=lval+rval;
//	int val=inf;
//	for(int i=l;i<=r;i++)
//	{
//		val=min(val,dfs(l,x-1,i)+dfs(x+1,r,i)+a[])
//	}
}
int f(int l,int r,int fa)
{//fa作为[l,r]的父节点
	if(dp[l][r][fa])
		return dp[l][r][fa];
	if(l>r)
		return dp[l][r][fa]=0;
//	if(l==r)
//		return dp[l][r][fa]=a[l]*a[fa];
	int val=inf;
	for(int i=l;i<=r;i++)
		val=min(val,f(l,i-1,i)+f(i+1,r,i)+a[fa]*a[i]);
	return dp[l][r][fa]=val;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<f(1,n,0)<<endl;
//	int ans=inf;
//	for(int i=1;i<=n;i++)
//		ans=min(ans,dfs(1,n,i));
////	for(int i=1;i<=n;i++)
////		for(int j=i;j<=n;j++)
////			for(int k=i;k<=j;k++)
////				printf("dp[%lld][%lld][%lld]=%lld\n",i,j,k,dp[i][j][k]);
//	cout<<ans<<endl;
	return 0;
}


