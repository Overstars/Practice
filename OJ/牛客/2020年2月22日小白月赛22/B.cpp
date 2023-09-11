#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
ll val[maxn],sum[maxn],dp[maxn],dp2[maxn],ans;
void dfs(int x,int fa)
{
	sum[x]=sum[fa]+val[x];
	dp[x]=val[x];
	dp2[x]=-inf;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		if(dp[v]+val[x]>dp[x])
		{
			dp2[x]=dp[x];
			dp[x]=dp[v]+val[x];
		}
		else
			dp2[x]=max(dp2[x],dp[v]+val[x]);
	}
	ans=max(ans,max(sum[fa]+dp[x],dp[x]+dp2[x]-val[x]));
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
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=val[1];
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}


