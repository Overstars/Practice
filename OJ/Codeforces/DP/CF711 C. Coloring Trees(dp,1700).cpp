//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int dp[maxn][maxn][maxn],c[maxn],p[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,d;
	cin>>n>>m>>d;//n棵树m颜色d段
	for(int i=1;i<=n;i++)//颜色,0表示未涂
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{//第i棵树涂成j颜色的花费
			cin>>p[i][j];
		}
	}
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<=m;i++)
		dp[0][0][m]=0;
	if(c[1])
		dp[1][1][c[1]]=0;
	else{
		for(int i=1;i<=m;i++)
			dp[1][1][i]=p[1][i];
	}
	for(int i=1;i<=n;i++)
	{//前i点涂成j段,最后一段颜色为k的最小代价
		for(int j=1;j<=i&&j<=d;j++)
		{//j段
			if(c[i])//有颜色
			{
				for(int k=1;k<=m;k++)
				{//上一段结尾用k
					if(c[i]==k)//和上一段颜色相同
						dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
					else
						dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][k]);
				}
			}
			else{
				for(int k=1;k<=m;k++)
				{//这一段k结尾
					for(int w=1;w<=m;w++)
					{//上一段w结尾
						if(k==w)
							dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][w]+p[i][k]);
						else
							dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][w]+p[i][k]);
					}
				}
			}
		}
	}
	int ans=INF;
	if(c[n])
		ans=dp[n][d][c[n]];
	else
		for(int i=1;i<=m;i++)
			ans=min(ans,dp[n][d][i]);
	if(ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}


