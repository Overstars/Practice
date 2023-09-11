#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn][maxn];
int dp[maxn][maxn];
int query(int x,int y,int l,int r)
{//查询l行r列
	return dp[x][y]-dp[x-l][y]-dp[x][y-r]+dp[x-l][y-r];
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1')
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=i;k++)
				for(int l=1;l<=j;l++)
					if(query(i,j,k,l)==0)
						ans=max(ans,2*(k+l));
		}
	cout<<ans<<endl;
	return 0;
}


