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
vector<int> G[maxn];//邻接表
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(!w)//u xor v = 1
		{
			G[u].push_back(n+v);
			G[n+v].push_back(u);
			G[v].push_back(n+u);
			G[n+u].push_back(v);
		}
		else{//u xor v = 0
			G[u].push_back(v);
			G[v].push_back(u);
			G[n+u].push_back(n+v);
			G[n+v].push_back(n+u);
		}
	}
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			tarjan(i);
	bool ok=1;
	for(int i=1;i<=n;i++)
		if(belong[i]==belong[n+i])
			ok=0;
		else if(belong[i]>belong[n+i])//不选>选
			ans++;
	if(!ok)
		cout<<"Impossible"<<endl;
	else{
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			if(belong[i]>belong[n+i])//不选
				cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}
/*
 *翻译:https://www.luogu.com.cn/problem/CF228E
 *每个点操作0或1次
 *每个点拆成"选"与"不选"两个点
 *对每条边,若边为1,连接的两点状态相同,否则不同
*/

