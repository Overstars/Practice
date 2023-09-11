//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
//#define int ll
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
ull dp[25][25];
int x,y,nx[]={-2,-1,1,2,2,1,-1,-2};
int ny[]={1,2,2,1,-1,-2,-2,-1};
bool jud(int i,int j)
{
	if(i==x&&j==y)
		return 1;
	for(int k=0;k<8;k++)
	{
		int xx=x+nx[k],yy=y+ny[k];
		if(xx<0||yy<0)
			continue;
		if(xx==i&&yy==j)
			return 1;
	}
	return 0;
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m>>x>>y;
//	for(int i=0;i<=n&&!jud(i,0);i++)
//		dp[i][0]=1;
//	for(int i=0;i<=m&&!jud(0,i);i++)
//		dp[0][i]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(jud(i,j))
				continue;
			if(i==0&&j==0)
				dp[i][j]=1;
			else if(i==0)
				dp[i][j]=dp[i][j-1];
			else if(j==0)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}


