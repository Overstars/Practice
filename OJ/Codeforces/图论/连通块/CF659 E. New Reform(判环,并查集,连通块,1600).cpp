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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
vector<int>G[maxn];
bool vis[maxn];
int dfs(int x,int fa)
{
	vis[x]=1;
	bool cir=0;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		Merge(v,x);
		if(vis[v]||dfs(v,x))
		{
			cir=1;
			continue;
		}
		dfs(v,x);
	}
	return cir;
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
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		ans+=dfs(i,0)?0:1;
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *n个点,m个无向边,图不一定联通
 *要求为边定向,使入度为0的节点尽量少,并输出该值
 *并查集求连通块,若该连通块有环,贡献为0
 *若该连通块无环,贡献为1(根节点)
 */


