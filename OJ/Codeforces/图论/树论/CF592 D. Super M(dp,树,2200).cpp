//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
vector<int>gg[maxn];
vector<pii>G[maxn];
int is[maxn],dis[maxn];
void get(int x,int fa,int top)
{
	if(is[x]&&top)
	{
		G[x].push_back(pii(top,));
		G[top].push_back(x);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		gg[u].push_back(v);
		gg[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
		cin>>u,is[u]=1;
	get(1,1,0);
	return 0;
}
/*
 *一棵n个节点的树,有m个必须访问的节点
 *m<=n<1.3e5
 *选择初始节点,使访问总距离最小
 *肯定是在m个节点构成的树上的叶子出发
 *构建新图+换根dp?
 *dp[x]表示处理完x子树的总贡献
 *dp[x]=sum(dp[v])+sum(dis(x,v))-max(dis(x,v))
 *好像不大行,要保留关键节点的,虚树?
 *2020年11月11日接着写...
 *单次询问...
*/

