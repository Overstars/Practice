//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll ans[maxn],dep[maxn],w[maxn],f[maxn],dp[maxn],sum=0;
vector<int>G[maxn];
void dfs1(int x,int fa)
{
	dp[x]=0;
	f[x]=w[x];//树上后缀和
	dep[x]=dep[fa]+1;
//	printf("!!\n");
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs1(v,x);
		f[x]+=f[v];
		dp[x]+=dp[v];
	}
	dp[x]+=dep[x]*w[x];
}
void dfs2(int x,int fa)
{//fa是原来的根,ans[x]表示以x为根节点的答案
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		ans[v]=ans[x]+sum-2*f[v];
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
	int t,n,u,v;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			sum+=w[i];
			G[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,0);
		ans[1]=dp[1];
		dfs2(1,1);
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}


