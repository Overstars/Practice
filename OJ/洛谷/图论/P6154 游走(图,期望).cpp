#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=998244353;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
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
vector<int>G[maxn];
ll cnt[maxn],sum[maxn];
bool vis[maxn];
void dfs(int x)
{
	vis[x]=1;
	cnt[x]=1;
	for(auto &v:G[x])
	{
		if(!vis[v])
			dfs(v);
		sum[x]=((sum[x]+sum[v])%mod+cnt[v])%mod;
		cnt[x]=(cnt[x]+cnt[v])%mod;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
//		G[v].push_back(u);
	}
	ll ts=0,tc=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
		ts=(ts+sum[i])%mod;
		tc=(tc+cnt[i])%mod;
	}
	cout<<ts*qmod(tc,mod-2,mod)%mod<<endl;
	return 0;
}
/*
无向图期望=所有点对的距离/点对数

*/
