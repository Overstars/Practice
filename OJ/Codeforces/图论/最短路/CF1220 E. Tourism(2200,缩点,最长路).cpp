//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int tim=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
int w[maxn],rec[maxn],siz[maxn];//每个强连通分量的值
bool vis[maxn];
vector<int>G[maxn],gg[maxn];
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++tim;
	vis[x]=1;//标记在栈中
	stk[++Index]=x;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		if(!vis[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
		}
		else
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]&&vis[x])
	{
		cnt++;//双连通分量个数
		do{
			belong[stk[Index]]=cnt;
			vis[stk[Index]]=0;
			rec[cnt]+=w[stk[Index]];
			siz[cnt]++;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
//ll d[maxn];
//ll dijk(int st,int n)
//{
//	for(int i=1;i<=n;i++)
//		d[i]=0;
//	d[st]=rec[st];
//	vector<bool>vis(n+1,0);
//	priority_queue<pii>q;
//	int root=st,MAX=d[st];
//	q.push(pii(rec[st],st));
//	while(!q.empty())
//	{
//		pii now=q.top();
//		q.pop();
//		if(vis[now.ss])
//			continue;
//		vis[now.ss]=1;
//		if(MAX<d[now.ss])
//		{
//			MAX=d[now.ss];
//			root=now.ss;
//		}
//		for(int &v:gg[now.ss])
//		{
//			if(d[v]<d[now.ss]+rec[v])
//			{
//				d[v]=d[now.ss]+rec[v];
//				q.push(pii(d[v],v));
//			}
//		}
//	}
//	return root;
//}
//dp[x]表示以x节点为根的子树上,可以返回的权值
ll dp[maxn],dp2[maxn],ans=0,can[maxn];//dp2[x]表示一去不回
void dfs(int x,int fa)//假了,应该dp
{
	dp[x]=rec[x];
	int ret=0;
	if(siz[x]>1)
		can[x]=1;
	for(int &v:gg[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		if(can[v])//v节点可以返回
		{
			dp[x]+=dp[v];
			can[x]=1;
		}
		else//选一个最大的
			ret=max(ret,dp2[v]);
	}
	dp2[x]=dp[x]+ret;//一去不回
	for(int &v:gg[x])
	{//有的时候在某个可返回点一去不回反而最优
		if(v!=fa&&can[v])
			dp2[x]=max(dp2[x],dp[x]-dp[v]+dp2[v]);
	}
//	printf("dp[%lld]=%lld,%lld\n",x,dp[x],dp2[x]);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,st;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	vector<pii>R;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		R.push_back(pii(u,v));
	}
	cin>>st;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,i);
	for(auto &e:R)
	{
		int u=belong[e.ff],v=belong[e.ss];
		if(u==v)
			continue;
		gg[u].push_back(v);
		gg[v].push_back(u);
	}
	dfs(belong[st],0);
//	for(int i=1;i<=n;i++)
//		cerr<<"c["<<i<<"] = "<<belong[i]<<endl;
	cout<<dp2[belong[st]]<<endl;
//	cout<<topo(belong[st])<<endl;
//	cout<<dfs(belong[st],0)<<endl;
//	ll root=dijk(belong[st],cnt);
//	ll ans=d[root];
//	printf("ans = %lld\n",ans);
//	root=dijk(root,cnt);
//	ans=max(ans,d[belong[st]]);
//	root=dijk(root,cnt);
//	ans=max(ans,d[belong[st]]);
//	cout<<ans<<endl;
	return 0;
}
/*
 * n点m边的简单无向图
 * 从s出发经过一条不回头的路径
 * 每个点只计入一次
 * 初始点有一个给定集合s
 * tarjan缩点后找最长路
 * 四个月之后接着写...2021年3月18日
 * 我为什么把上面都注释掉了,好像也没假...
 * 那缩点以后以s为根dfs,第二个样例一样不对
 * 哦,问题在于经过一个环之后可以返祖
 * 注意无向图缩点,用边双连通分量
*/

