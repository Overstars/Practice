//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
double a[20][20],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	int st=(1<<n)-1;
	dp[st]=1;
	for(int now=st;now>0;now--)
	{//dp[x]表示从st到达x的概率
		int tot=__builtin_popcount(now);
		int g=tot*(tot-1)/2;
		for(int i=0;i<n;i++)
		{//在now状态中,抽出两条鱼pk
			if(!(now&(1<<i)))
				continue;
			for(int j=i+1;j<n;j++)
			{
				if(!(now&(1<<j)))
					continue;
				dp[now^(1<<j)]+=dp[now]*a[i][j]/g;
				dp[now^(1<<i)]+=dp[now]*a[j][i]/g;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<setiosflags(ios::fixed)<<setprecision(9)<<dp[1<<i]<<' ';
	return 0;
}
/*
 * 2021-05-03-19.58.40
 * 尝试记忆化搜索
 * n^2枚举复杂度2^18 * 18*18*18 = 1.5e9,lowbit也救不了
 * 尝试从初始状态递推每一个状态到达的概率
 * 复杂度2^18 *18*18
*/
//以下为TLE代码
//double a[20][20],dp[maxn][19];
//bool vis[maxn][20];
//int n;
//double dfs(int st,int x)
//{
//	int tot=__builtin_popcount(st);
//	if(tot<=0)
//		return 0;
//	if(tot==1)
//	{
//		if(st==(1<<x))
//			return 1;//x存活
//		return 0;//存活的不是x
//	}
//	if(vis[st][x])
//		return dp[st][x];
//	int g=(tot-1)*tot/2;//C(n,2)
//	#define lowbit(x) ((x) & -(x))
//	for(int i=st;i>0;i-=lowbit(i))
//	{
//		int na=log2(lowbit(i)),nb;
//		for(int p=i-lowbit(i);p>0;p-=lowbit(p))
//		{//并不能优化多少
//			nb=log2(lowbit(p));
//			dp[st][x]+=(dfs(st^lowbit(p),x)*a[na][nb]+dfs(st^lowbit(i),x)*a[nb][na])/g;//i把j吃掉,j把i吃掉
//		}
//	}
////	for(int i=0;i<n;i++)
////	{//组合(tot-1)*(tot-1)种
//////		cout<<bitset<4>(st)<<endl;
////		if(!(st&(1<<i)))
////			continue;
////		for(int j=i+1;j<n;j++)
////		{
////			if(!(st&(1<<j)))
////				continue;
//////			printf("wtf\n");
////			dp[st][x]+=(dfs(st^(1<<j),x)*a[i][j]+dfs(st^(1<<i),x)*a[j][i])/g;//i把j吃掉,j把i吃掉
////		}
////	}
////	printf("tot = %d,dp[%d][%d] = %.3f\n",tot,st,x,dp[st][x]);
//	vis[st][x]=1;
//	return dp[st][x];
//}
//signed main(signed argc, char const *argv[])
//{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
//	//	freopen("output.out", "w", stdout);
//	#endif
////	cin>>n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			scanf("%lf",&a[i][j]);
////			cin>>a[i][j];
//	}
//	for(int i=0;i<n;i++)
//		printf("%.7f ",dfs((1<<n)-1,i));
////		cout<<setiosflags(ios::fixed)<<setprecision(9)<<dfs((1<<n)-1,i)<<' ';
////	for(int i=0;i<n;i++)
////		cout<<dp[(1<<n)-1][i]<<endl;
//	return 0;
//}


