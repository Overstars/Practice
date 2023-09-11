//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int __int128
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn],b[maxn],c[maxn];
vector<int>G[maxn];
__int128 dp[maxn];//dp[x]表示x子树可以多出来的数量
bool ok=1;
bool dfs(int x,int fa)
{
	dp[x]=b[x]-a[x];
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		if(min(dp[v],dp[x])<=-1e18||(__int128)dp[v]*c[v]<=-1e18)
		{
			ok=0;
			break;
		}
		if(dp[v]>0)
			dp[x]+=dp[v];//多余的v传递上来
		else//补足v子树
			dp[x]+=dp[v]*c[v];//转化为v的代价
	}
	if(dp[x]<=-1e18||!ok)
		dp[x]=-1e18;
	return dp[x]>=0;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,u;
	read(n);
//	cin>>n;
	for(int i=1;i<=n;i++)
		read(b[i]);
//		cin>>a[i];
	for(int i=1;i<=n;i++)
		read(a[i]);
//		cin>>b[i];
	for(int i=2;i<=n;i++)
	{
		read(u,k);
//		cin>>u>>k;
		c[i]=k;
		G[u].push_back(i);//u可以以消耗k转化为i
		G[i].push_back(u);
	}
	printf("%s\n",(dfs(1,0)&&ok?"YES":"NO"));
//	cout<<(dfs(1,0)?"YES":"NO")<<endl;
	return 0;
}
/*
 * 2021-05-17-22.05.28
 * https://www.luogu.com.cn/problem/CF846E
 * 22点20分摸鱼
 *
*/

