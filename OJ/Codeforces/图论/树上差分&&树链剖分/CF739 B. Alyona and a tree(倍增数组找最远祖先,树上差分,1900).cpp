//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct edge
{
	int v,w;
};
vector<edge>G[maxn];
int a[maxn],depth[maxn],gene[maxn][21];
ll dist[maxn],ans[maxn];
void dfs(int x,int fa)
{//nlogn求距离及处理祖先信息
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)//树上倍增
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(auto &e:G[x])
	{
		dist[e.v]=dist[x]+e.w;
		dfs(e.v,x);
	}
	int anc=x;//处理最远祖先,进行树上差分
	for(int i=20;i>=0;i--)//模仿求lca跳跃
		if(gene[anc][i]&&dist[x]-dist[gene[anc][i]]<=a[x])
			anc=gene[anc][i];
	ans[gene[x][0]]++;//树上差分
	ans[gene[anc][0]]--;
}
void dfs2(int x)
{
	for(auto &e:G[x])
	{
		dfs2(e.v);
		ans[x]+=ans[e.v];
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2,p,w;i<=n;i++)
	{
		cin>>p>>w;
		G[p].push_back({i,w});
	}
	dfs(1,0);
	dfs2(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}


