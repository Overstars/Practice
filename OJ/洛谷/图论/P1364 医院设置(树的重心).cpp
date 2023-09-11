#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll val[maxn],dp[maxn],siz[maxn],depth[maxn],sum=0,ans=LLONG_MAX;
void dfs1(int x,int fa)
{
	siz[x]=val[x];
	depth[x]=depth[fa]+1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];
	}
	dp[1]+=(depth[x]-1)*val[x];
}
void dfs2(int x,int fa)
{//dp[x]表示其他节点到x的权值和
	for(auto &v:G[x])
	{
		if(v!=fa)
		{//以v作为中心时,下面的节点每个少走一步,上面节点每个多走一步
			dp[v]=dp[x]-siz[v]+(siz[1]-siz[v]);
			dfs2(v,x);
		}
	}
	ans=min(ans,dp[x]);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,w,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i]>>u>>v;
		if(u)
		{//这个是二叉树而不是多叉树
			G[i].push_back(u);
			G[u].push_back(i);
		}
		if(v)
		{
			G[i].push_back(v);
			G[v].push_back(i);
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
	return 0;
}


