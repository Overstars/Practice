//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int dp[maxn][maxn][20];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,c,x,y,z,x2,y2;
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		dp[x][y][z]++;//亮度为z
	}
	for(int k=0;k<=c;k++)
	{
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
	}
	while(q--)
	{
		cin>>z>>x>>y>>x2>>y2;
		ll ans=0;
		for(int i=0;i<=c;i++)
		{
			ll num=dp[x2][y2][i]-dp[x2][y-1][i]-dp[x-1][y2][i]+dp[x-1][y-1][i];
			ans+=((i+z)%(c+1))*num;
		}
		cout<<ans<<endl;
	}
	return 0;
}


