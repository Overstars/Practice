//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5050,inf=0x3f3f3f3f,mod=1000000007;
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
int c[maxn],dp[maxn][maxn][2];
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
		cin>>c[i];
//	sort(c+1,c+n+1);
	n=unique(c+1,c+n+1)-c-1;
	fill(dp[0][0],dp[0][0]+maxn*maxn*2,inf);
	for(int i=1;i<=n;i++)
		dp[i][i][0]=dp[i][i][1]=0;
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			int r=l+len-1;
			dp[l][r][1]=min({//和右端点颜色一样
				dp[l][r-1][0]+(c[l]!=c[r]),//向右扩展
				dp[l][r-1][1]+1,//直接向右扩展
				dp[l+1][r][0]+1+(c[l]!=c[r]),//向左扩张+调成右面
				dp[l+1][r][1]+(c[l]!=c[r])*2
			});
			dp[l][r][0]=min({//和左面颜色一样
				dp[l+1][r][0]+1,//直接向左扩张
				dp[l+1][r][1]+(c[l]!=c[r]),//向左扩张
				dp[l][r-1][0]+(c[l]!=c[r])*2,//向右扩展+调成左面
				dp[l][r-1][1]+1+(c[r]!=c[l])//调成左面
			});
		}
	}
	cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
	return 0;
}
/*
 * 2021-04-18-20.47.08
*/

