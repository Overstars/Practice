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
struct edge
{
	int u,v;
};
int cir[maxn];
inline bool behind(int st,int ed,int x)
{
	return min(cir[st],cir[ed])<cir[x]&&cir[x]<max(cir[st],cir[ed]);
}
inline bool outside(int st,int ed,int x)
{
	return cir[x]<min(cir[st],cir[ed])||cir[x]>max(cir[st],cir[ed]);
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		bool ok=1;
		vector<edge>E;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			E.push_back({u,v});
		}
		for(int i=1;i<=n;i++)
		{
			cin>>u;
			cir[u]=i;//记录u点的顺时针编号
		}
		if(m>3*n-6)
		{
			ok=0;
			goto label;
		}
		tim=Index=cnt=0;
		for(int i=0;i<=2*m;i++)
			G[i].clear(),dfn[i]=low[i]=0,vis[i]=0;
		for(int i=0;i<m;i++)
		{//m<=3n-6,枚举冲突的两条边
			for(int j=i+1;j<m;j++)
			{
				const edge &a=E[i],&b=E[j];
				if(behind(a.u,a.v,b.u)&&outside(a.u,a.v,b.v)||behind(a.u,a.v,b.v)&&outside(a.u,a.v,b.u))
				{
					G[i+1].push_back(j+1+n);
					G[j+1].push_back(i+1+n);
					G[i+1+n].push_back(j+1);
					G[j+1+n].push_back(i+1);
				}
			}
		}
		for(int i=1;i<=2*m;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i=1;i<=m;i++)
			if(belong[i]==belong[i+n])
				ok=0;
		label:
		cout<<(ok?"YES":"NO")<<'\n';
	}
	return 0;
}


