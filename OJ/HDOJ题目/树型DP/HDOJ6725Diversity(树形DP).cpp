#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
ll dp[2][maxn],l[maxn],r[maxn];
vector<int>G[maxn];
void dfs(int x,int fa)
{
	dp[0][x]=dp[1][x]=0;//0取l,1取r
	for(auto v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		dp[0][x]+=max(abs(l[x]-l[v])+dp[0][v],abs(l[x]-r[v])+dp[1][v]);
		dp[1][x]+=max(abs(r[x]-l[v])+dp[0][v],abs(r[x]-r[v])+dp[1][v]);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			cin>>l[i]>>r[i];
		dfs(1,0);
		cout<<max(dp[0][1],dp[1][1])<<endl;
	}
	return 0;
}


