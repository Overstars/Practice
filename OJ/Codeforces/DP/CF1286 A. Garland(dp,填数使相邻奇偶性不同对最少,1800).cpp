//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
int p[maxn],sum[maxn],dp[maxn][maxn][maxn][2];
signed main(signed argc, char const *argv[])
{
	int n,even=0,tot=0;
	memset(dp,inf,sizeof(dp));
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	cin>>n;
	even=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==0)
			tot++,sum[i]++;
		else if(p[i]%2==0)
			even--;
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{//枚举位置
		for(int j=0;j<=sum[i];j++)
		{//枚举0的数量
			int k=sum[i]-j;
			if(p[i])//这一位是固定的
			{
				int op=p[i]&1;
				dp[i][j][k][op]=min(dp[i-1][j][k][op],dp[i-1][j][k][!op]+1);
			}
			else{
				dp[i][j][k][1]=min(dp[i-1][j][k-1][1],dp[i-1][j][k-1][0]+1);
				dp[i][j][k][0]=min(dp[i-1][j-1][k][0],dp[i-1][j-1][k][1]+1);
			}
		}
	}
	cout<<min(dp[n][even][tot-even][0],dp[n][even][tot-even][1])<<endl;
	return 0;
}
//int p[maxn],dp[maxn][maxn][maxn][2],sum[maxn],even,tot;//第i位一共消耗了j个0,k个1,并p[i]补上的最小值
//bool vis[maxn][maxn][maxn][2],ope[maxn],rec[maxn][maxn][maxn];//记录状态
//int dfs(int x,int c0,int c1,bool op)
//{//第x位,消耗c1个
////	printf("dp[%d][%d][%d][%d]=%d\n",x,c0,c1,op,dp[x][c0][c1][op]);
//	if(x==1)
//	{
//		return 0;
//	}
//	if(c0<0||c1<0)
//		return 10000;
//	if(vis[x][c0][c1][op])
//		return dp[x][c0][c1][op];
//	if(ope[x])//要填一个数
//	{
//		vis[x][c0][c1][op]=1;
//		int n0=inf,n1=inf;
//		if(c0)
//			n0=dfs(x-1,c0,c1,0)+(rec[x-1][c0-1][c1]^0);
//		if(c1)
//			n1=dfs(x-1,c0,c1,1)+(rec[x-1][c0][c1-1]^1);
//		rec[x][c0][c1]=((n0<n1)?0:1);
//		return dp[x][c0][c1][op]=min(n0,n1);
//	}
//	else{
//		vis[x][c0][c1][op]=1;
//		rec[x][c0][c1]=p[x];
//		int n0=dfs(x-1,c0,c1,0)+(rec[x-1][c0][c1]^p[x]);
//		int n1=dfs(x-1,c0,c1,1)+(rec[x-1][c0][c1]^p[x]);
//		return dp[x][c0][c1][op]=min(n0,n1);
//	}
//}
//signed main(signed argc, char const *argv[])
//{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
//	//	freopen("output.out", "w", stdout);
//	#endif
//	memset(dp,inf,sizeof(dp));
//	int n,c[2]={0};
//	cin>>n;
//	even=n/2,tot=0;//缺失的0,总缺失
////	for(int i=1;i<=n;i++)
////	{
////		cin>>p[i];
////		if(p[i]==0)
////			p[i]=-1,tot++,sum[i]++,ope[i]=1;
////		else{
////			p[i]%=2;
////			if(p[i]==0)
////				even--;
////		}
////		sum[i]+=sum[i-1];
////	}
////	for(int i=1;i<=n;i++)
////	{
////		for(int j=1;j<=)
////		{
////			if(~p[i])
////			{
////
////			}
////			else{
////				dp[i][]
////			}
////		}
////	}
////	cout<<min(dfs(n,even,tot-even,0),dfs(n,even,tot-even,1))<<endl;
//	return 0;
//}


