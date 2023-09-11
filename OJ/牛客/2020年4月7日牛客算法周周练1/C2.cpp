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
int dis[maxn],dfn[maxn],siz[maxn],tim=0;
vector<int>G[maxn];
void dfs(int x,int fa)
{
	dfn[x]=++tim;
	siz[x]=1;
	for(auto &v:G[x])
	{
		if(fa==v)
			continue;
		dis[v]=dis[x]+1;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,u,v,q;
	read(t);
	while(t--)
	{
		read(n,q);
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			read(u,v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		tim=0;
		dfs(1,0);
		int a,b,c;
		while(q--)
		{
			read(a,b,c);
			bool ok=0;
			u=lca(a,1);
			v=lca(c,b);
			printf("%s\n",(ok?"YES":"NO"));
		}
	}
	return 0;
}


