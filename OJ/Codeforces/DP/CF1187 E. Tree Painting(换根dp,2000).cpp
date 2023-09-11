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
vector<int>G[maxn];
ll n,ans=0,siz[maxn],f[maxn],g[maxn];
void dfs1(int x,int fa)
{
	siz[x]=1;
//	printf("!!\n");
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		f[x]+=f[v];
	}
	f[x]+=siz[x];
}//u及子树贡献,递推方程f[u]=siz[u]+\sum{f[v]}
void dfs2(int x,int fa)
{//fa是原来的根,g[x]表示以x为根节点的答案
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
//		g[v]=(f[v]-siz[v])+(g[x]-n-f[v])+n+(n-siz[v]);//v的子树的贡献+父节点x作为子树的贡献+v节点作为根的贡献+新的连通块的贡献
		g[v]=g[x]+n-2*siz[v];
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
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);
	ans=g[1]=f[1];
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		ans=max(ans,g[i]);
	cout<<ans<<endl;
	return 0;
}


