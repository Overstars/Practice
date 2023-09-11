//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
vector<int>G[maxn],g[maxn];
int d[maxn],ans[maxn],deg[maxn];
void dijk(int n,int s)
{
	vector<bool>vis(n+10,false);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push(pii(0,s));
	ans[s]=d[s]=0;
	while(!q.empty())
	{
		pii now=q.top();
		q.pop();
		if(vis[now.ss])
			continue;
		vis[now.ss]=1;
		for(int &v:G[now.ss])
			if(!vis[v]&&d[now.ss]+1<d[v])
			{
				ans[v]=d[v]=d[now.ss]+1;
				q.push(pii(d[v],v));
			}
	}
	for(int i=1;i<=n;i++)
		cerr<<"d["<<i<<"] = "<<d[i]<<endl;
	return;
}
void dfs(int x,int val)
{
	ans[x]=min(ans[x],val);
	for(int &v:g[x])
		dfs(v,min(ans[v],val));
}
int dp[maxn],low[maxn];//low[x]表示经过一次变换
bool vis[maxn];
int dfs(int x)
{
	if(vis[x])
		return low[x];
	vis[x]=1;
	low[x]=d[x];//low[x]表示x可访问的
	for(int &v:G[x])
	{
		if(d[x]>=d[v])//大->小,支付代价
		{
			low[x]=min(low[x],d[v]);
		}
		else{
			if(!vis[v])
				dfs(v);
			low[x]=min(low[x],low[v]);
		}
	}
	return low[x];
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<pii>rec;
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			g[i].clear();
			vis[i]=0;
			d[i]=ans[i]=inf;
			deg[i]=0;
		}
		int u,v;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			rec.push_back(pii(u,v));
			G[u].push_back(v);
		}
		dijk(n,1);
//		#define wtf
		#ifdef wtf
		for(pii &i:rec)
		{
			u=i.ff,v=i.ss;
			if(d[u]<d[v])
			{//从小到大
				g[v].push_back(u);//建反图,大到小
				deg[u]++;
			}
			else//只能走一次
				ans[u]=min(ans[u],d[v]);
//			ans[v]=min(ans[v],d[u]);
		}
		for(int i=1;i<=n;i++)
			if(deg[i]==0)
				dfs(i,ans[i]);
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		#else
		dfs(1);
		for(int i=1;i<=n;i++)
			cout<<low[i]<<' ';
		#endif
		cout<<endl;
	}
	return 0;
}
/*
999
6 10
1 5
1 6
6 4
5 2
5 3
3 2
4 6
2 6
6 3
5 6

*/
/*
 * n个城市,1号点为首都,每条有向边长度1
 * d_i为首都到达该点的最短距离
 * 从s开始行走,只有一次机会执行第二种操作(有向边从大到小or等于)
 * 求出他可以到达距离首都的最近距离即最小的d_i
 * 从u到v最多有一条有效路径
 * 类似tarjan的解法
 * 上次的思路也应该没假,实现有问题...
*/

