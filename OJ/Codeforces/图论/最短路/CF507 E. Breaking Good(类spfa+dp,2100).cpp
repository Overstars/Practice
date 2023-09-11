//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
	int u,v,z;
};
struct e2
{
	int v,z,id;
};
vector<e2>G[maxn];
int dis[maxn],dp[maxn],pre[maxn],pree[maxn];//
void bfs(int st,int n)
{
	for(int i=1;i<=n;i++)
		dis[i]=dp[i]=inf;
	dis[st]=dp[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &e:G[x])
		{
			int cost=(e.z!=1?1:0);
			if(dis[e.v]>dis[x]+1||(dis[e.v]==dis[x]+1&&dp[e.v]>dp[x]+cost))
			{//距离相等说明边数目相等,路径上要求修复最少
				dis[e.v]=dis[x]+1;
				dp[e.v]=dp[x]+cost;//需要修复
				pre[e.v]=x,pree[e.v]=e.id;
				q.push(e.v);
			}
		}
	}
}
bool chose[maxn];
void dfs(int x)
{
	if(x==1)
		return;
//	printf("x=%d,pre=%d\n",x,pre[x]);
	chose[pree[x]]=1;
	dfs(pre[x]);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,z;
	cin>>n>>m;
	vector<edge>E;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>z;
		G[u].push_back({v,z,i});
		G[v].push_back({u,z,i});
		E.push_back({u,v,z});
	}
	bfs(1,n);
	dfs(n);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(chose[i]&&E[i-1].z==0)
			ans++;
		else if(!chose[i]&&E[i-1].z==1)
			ans++;
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		if(chose[i]&&E[i-1].z==0)
			cout<<E[i-1].u<<' '<<E[i-1].v<<' '<<1<<endl;
		else if(!chose[i]&&E[i-1].z==1)
			cout<<E[i-1].u<<' '<<E[i-1].v<<' '<<0<<endl;
	}
	return 0;
}
/*
 *给一个图,从1->n
 *有些边是坏的,需要修好
 *选择一个从1->n的最短路,不在这条路线上的边都要炸毁
 *求出炸毁和修复的最小数目
 *可以发现图是没有边权的,bfs就行了?
 *是这样的,用时48min
 */

