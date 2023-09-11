#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5010,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
int siz[maxn],n;//
bool dp[maxn][maxn],ok[maxn];
void dfs(int x,int fa)
{
	siz[x]=1;
	dp[x][0]=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
//		dp[x][siz[v]]=1;
		siz[x]+=siz[v];
		for(int i=siz[x];i>=siz[v];i--)//以x作为唯一的未染色点,进行树上背包
			dp[x][i]|=dp[x][i-siz[v]];
	}
	for(int i=n-2;i>=1;i--)
		dp[x][i]|=dp[x][n-i-1];
	for(int i=1;i<=n-1;i++)
		ok[i]|=dp[x][i];
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n-2;i++)
		if(ok[i])
			ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n-2;i++)
		if(ok[i])
			cout<<i<<' '<<n-i-1<<endl;
	return 0;
}


