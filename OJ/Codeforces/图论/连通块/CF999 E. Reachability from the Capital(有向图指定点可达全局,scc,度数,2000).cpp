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
int tim=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
int val[maxn],rec[maxn];//每个强连通分量的值
bool vis[maxn];
vector<int> G[maxn],g[maxn],g2[maxn];//邻接表
void tarjan(int x)//标准的Tarjan缩点
{
//	printf("now=%d\n",x);
	dfn[x]=low[x]=++tim;//dfs序
	stk[++Index]=x;
	vis[x]=1;
	for(int &v:G[x])
	{
		if(!dfn[v])//v未被访问
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);//回溯时更新low
		}//low[x]为x所在强连通分量最早起始节点
		else if(vis[v])//v在栈中,说明有环
			low[x]=min(low[x],dfn[v]);//更新起点为最早的那个
	}
	if(low[x]==dfn[x])
	{//以x为起点的强连通分量
		cnt++;//新图节点++
		do{
			belong[stk[Index]]=cnt;
			rec[cnt]+=val[stk[Index]];//缩点后的权值
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
bool ok[maxn];
//map<int,int>mp;
void dfs(int x,int top)
{
//	mp[x]=top;
	ok[x]=top;
	for(int &v:g[x])
		if(!ok[v])
			dfs(v,top);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,s,id=0;
	cin>>n>>m>>s;
	vector<pii>E(m);
	#define ff first
	#define ss second
	for(pii &e:E)
	{
		cin>>e.ff>>e.ss;
		g[e.ff].push_back(e.ss);
	}
	dfs(s,s);//合并所有可达点
	for(pii &e:E)
	{//建立新图,缩点
		int u=e.ff,v=e.ss;
		if(ok[u]&&ok[v])
			continue;
		if(ok[u])
			u=s;
		if(ok[v])
			v=s;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]&&(!ok[i]||i==s))
			tarjan(i);
	vector<int>deg(cnt+1,0);
	for(pii &e:E)
	{
		int u=e.ff,v=e.ss;
		if(ok[u]&&ok[v])
			continue;
		if(belong[u]==belong[v])
			continue;
		deg[belong[v]]++;
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
		if(deg[i]==0)
			ans++;
//	printf("cnt=%d\n",cnt);
	ans-=(deg[belong[s]])?0:1;
	cout<<ans<<endl;
	return 0;
}
/*
 *好像并不是裸的缩点...
 *应该是先从1开始dfs,合并所有可达点
 *然后tarjan缩点,对于每个入度为0的点连一条边
*/

