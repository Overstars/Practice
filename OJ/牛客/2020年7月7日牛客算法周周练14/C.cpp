//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e6+10,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll dp[maxn],siz[maxn],dp2[maxn];
vector<int>G[maxn];
ll qmod(ll a,ll b,ll mod)  //快速幂
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
long long inv(long long a,long long p=mod)
{//求a在模p下的乘法逆元（p是素数）
    return qmod(a,p-2,p);//qmod在上面
}
void dfs1(int x,int fa)
{
	dp[x]=1;
//	siz[x]=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs1(v,x);
//		siz[x]+=siz[v];
		dp[x]=dp[x]*((dp[v]+1)%mod)%mod;
	}
}
void dfs2(int x,int fa)
{
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dp2[v]=(dp[v]*((dp2[x]*inv(dp[v]+1,mod)%mod+1)%mod))%mod;
		dfs2(v,x);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,1);
	dp2[1]=dp[1];
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		printf("dp[%d]=%lld\n",i,dp[i]);
	for(int i=1;i<=n;i++)
		cout<<dp2[i]<<endl;
	return 0;
}
/*
6
1 2
1 3
1 5
2 4
2 6

5
1 2
1 3
1 4
1 5
*/

