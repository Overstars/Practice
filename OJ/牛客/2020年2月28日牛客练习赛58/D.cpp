#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char mp[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	memset(dp,inf,sizeof(dp));
	dp[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='1')
			{//这个到不了,看下一行
				continue;
			}
			if(mp[i][j+1]=='0')
			{//(i,j+1)添加障碍
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]);//向右走
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);//向下走
			}
			else if(mp[i+1][j]=='0')//直接向下走
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		}
	}
	cout<<(dp[n][m]==inf?-1:dp[n][m])<<endl;
	return 0;
}
