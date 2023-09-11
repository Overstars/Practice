//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
//int val[maxn],rec[maxn];//每个强连通分量的值
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
//			rec[cnt]+=val[stk[Index]];//缩点后的权值
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{//若一个假另一个必须为真
		cin>>u>>a>>v>>b;
		if(a==1&&b==1)//都为真
		{//则a=0时b必须为1
			G[u].push_back(v+n);
			G[v].push_back(u+n);
		}
		else if(a==0&&b==0)
		{//
			G[u+n].push_back(v);
			G[v+n].push_back(u);
		}
		else if(a==0&&b==1)
		{
			G[u+n].push_back(v+n);
			G[v].push_back(u);
		}
		else{//a=1,b=0
			G[u].push_back(v);
			G[v+n].push_back(u+n);
		}
	}
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(belong[i]==belong[i+n])
			return cout<<"IMPOSSIBLE"<<endl,0;
	cout<<"POSSIBLE"<<endl;
	for(int i=1;i<=n;i++)//tarjan编号小的为解
		cout<<(belong[i]<belong[i+n]?"0 ":"1 ");
	return 0;
}


