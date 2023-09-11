//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=4010,inf=0x3f3f3f3f,mod=1000000007;
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
int mp[maxn][maxn],dp[2][maxn];
int q[maxn],head=1,tail=0;
//map<int,int>mp[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P3800_1.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,t,ans=0,x,y,v;
	cin>>n>>m>>k>>t;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y>>v;
		mp[x][y]=v;
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{//先把[1,1+t]塞进队列,队列单调递减
		head=1,tail=0;
//		for(int j=1;j<=m;j++)
//			dp[now][j]=mp[i][j];
		for(int j=1;j<=t&&j<=m;j++)
		{
			while(head<=tail&&dp[!now][q[tail]]<=dp[!now][j])
				tail--;
			q[++tail]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(j+t<=m)
			{
				while(head<=tail&&dp[!now][q[tail]]<=dp[!now][j+t])
					tail--;
				q[++tail]=j+t;
			}
			while(head<=tail&&q[head]+t<j)
				head++;
			dp[now][j]=dp[!now][q[head]]+mp[i][j];
		}
		now=!now;
	}
	for(int i=1;i<=m;i++)
		ans=max(ans,dp[!now][i]);
	cout<<ans<<endl;
	return 0;
}
/*
 *n行m列,有k个物品分布其上,每个物品有一个权值
 *在第一行选一个格子开始,每秒向下走一格,并可最多左右瞬移t格
 *求可取得最大权值
 *好像可以滚动数组...每次询问dp[i-1][j-t]~dp[i-1][j+t]的最大值
*/

