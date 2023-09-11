//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
int p[maxn],q[maxn],deg[maxn];
vector<int>G[maxn],g[maxn];
char ans[maxn];
int tim=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
int val[maxn],rec[maxn];//每个强连通分量的值
bool vis[maxn];
//vector<int> G[maxn];//邻接表
void tarjan(int x)//标准的Tarjan缩点
{
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
//void dfs(int x,char ch)
//{
//	ans[x]=ch;
//	for(int &v:g[x])
//	{
//
//	}
//}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,u,v;
	cin>>n>>k;
	vector<pii>E;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i>=2)
		{
			int u=p[i-1],v=p[i];
			G[u].push_back(v);
			E.push_back(pii(u,v));
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
		if(i>=2)
		{
			int u=q[i-1],v=q[i];
			G[u].push_back(v);
			E.push_back(pii(u,v));
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	if(cnt<k)
		return cout<<"NO"<<endl,0;
	cout<<"YES"<<endl;
	for(pii &e:E)
	{
		if(belong[e.ff]==belong[e.ss])
			continue;
		g[belong[e.ff]].push_back(belong[e.ss]);
		deg[belong[e.ss]]++;
	}
	queue<int>q;
	for(int i=1;i<=cnt;i++)
	{
		ans[i]='a';
		if(deg[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int &v:g[x])
		{
			if(ans[x]=='z')
				ans[v]='z';
			else
				ans[v]=max((int)ans[v],ans[x]+1);
			if(--deg[v]==0)
				q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[belong[i]];
	return 0;
}
/*
 *构造一个n长字符串s
 *满足s[p_i]<=s[pi+1]且s[q_i]<=s[q_i+1]
 *s中至少有k个不同字符
 *感觉好像差分约束...
 *出现环则环上所有字符都相同,不在环上的字符可以自由选择
 *缩点后的点数<k则无解
 *到达同一个点显然走最长路径最优
*/

