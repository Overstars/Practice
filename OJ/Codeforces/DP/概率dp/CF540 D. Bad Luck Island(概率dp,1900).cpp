//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
double dp[maxn][maxn][maxn][3];
bool vis[maxn][maxn][maxn][3];
double dfs(int a,int b,int c,int x)
{
//	if(a==0&&b==0&&c==0)
//		return 0;
	if(a>0&&c==0&&x==0)
		return 1;
	if(b>0&&a==0&&x==1)
		return 1;
	if(c>0&&b==0&&x==2)
		return 1;
	if(vis[a][b][c][x])
		return dp[a][b][c][x];
	if(a>0&&b>0)//有效组合中选出来一组b被a吃的
		dp[a][b][c][x]+=(double)(a*b)/(a*b+b*c+c*a)*dfs(a,b-1,c,x);
	if(b>0&&c>0)//c被b吃
		dp[a][b][c][x]+=(double)(b*c)/(a*b+b*c+c*a)*dfs(a,b,c-1,x);
	if(c>0&&a>0)//a被c吃
		dp[a][b][c][x]+=(double)(c*a)/(a*b+b*c+c*a)*dfs(a-1,b,c,x);
//	printf("dp[%d][%d][%d][%d] = %.3f\n",a,b,c,x,dp[a][b][c][x]);
	vis[a][b][c][x]=1;
	return dp[a][b][c][x];
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int a,b,c;
	cin>>a>>b>>c;
//	for(int i=1;i<=a;i++)
//		dp[i][0][0][0]=1;
//	for(int i=1;i<=b;i++)
//		dp[0][i][0][1]=1;
//	for(int i=1;i<=c;i++)
//		dp[0][0][i][2]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=1;k<=n;k++)
//			{
//				dp[i][j][k][1]=dp[]
//			}
//		}
//	}
	for(int i=0;i<3;i++)
		cout<<setiosflags(ios::fixed)<<setprecision(9)<<dfs(a,b,c,i)<<' ';
	return 0;
}
/*
 * 2021-05-03-17.31.22
 * a吃b,b吃c,c吃a
 * 从初始状态推向结果
*/

