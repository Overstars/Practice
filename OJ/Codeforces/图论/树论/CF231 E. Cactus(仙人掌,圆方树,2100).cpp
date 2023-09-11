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
int qmod(int a,int b)  //快速幂
{//qmod(a,p-2,p)
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
namespace rst{
	int siz[maxn<<1],dfn[maxn],low[maxn],dfc=0,stk[maxn],top=0;
	int belong[maxn<<1],cnt=0,n;//方点的个数
	vector<int>pg[maxn],G[maxn<<1];
	void tarjan(int x)
	{//点双缩点并建立圆方树
		dfn[x]=low[x]=++dfc;//初次访问x
		fprintf(stderr,"Enter: #%d,dfn=%d\n",x,dfn[x]);
		stk[++top]=x;//入栈
		for(auto &v:pg[x])
		{
			if(!dfn[v])
			{
				tarjan(v);
				low[x]=std::min(low[x],low[v]);//未访问的和low
				if(low[v]==dfn[x])
				{
					cnt++;//增加方点个数/BCC个数
					fprintf(stderr,"\nFind a new bcc #%d.\n",cnt-n);
					do{//点双中所有点向方点连边,除了x都退栈
						G[cnt].push_back(stk[top]);//
						G[stk[top]].push_back(cnt);
						siz[cnt]++;
						fprintf(stderr,"Bcc #%d has vertex #%d.\n",cnt-n,stk[top]);
						top--;
					}while(stk[top+1]!=v);
					siz[cnt]++;
					G[cnt].push_back(x);//x自己连边,但不退栈
					G[x].push_back(cnt);//因为一个点可能在多个bcc中
					fprintf(stderr,"Bcc #%d has top vertex #%d\nsize = %d.\n",cnt-n,x,siz[cnt]);
				}
			}
			else
				low[x]=std::min(low[x],dfn[v]);//已访问的和dfn
		}
		fprintf(stderr,"");
	}
	void build(int n)
	{
		rst::n=cnt=n;//初始有n个点
		top=dfc=0;
		for(int i=1;i<=n;i++)
			if(!dfn[i])//tarjan退出时根仍在栈内
				tarjan(i),top--;
	}
}// namespace rst
//using namespace rst;
//const int maxl=30;
////vector<int> G[maxn];//无权边,也可以选择链式前向星存图
//int gene[maxn][maxl],depth[maxn],lg[maxn],sum[maxn];
////int nodes[maxn];//子树结点的数量
//void dfs(int x,int fa)
//{
//	depth[x]=depth[fa]+1;
//	sum[x]=sum[fa]+(x>n&&siz[x]>2?1:0);//树上前缀和
//	gene[x][0]=fa;
////	nodes[x]=1;
//	for(int i=1;(1<<i)<=depth[x];i++)//倍增
//		gene[x][i]=gene[gene[x][i-1]][i-1];
//	for(auto &v:G[x])
//		if(v!=fa)
//		{
//			dfs(v,x);//在dfs前后加语句可以求出许多有趣的东西
////			nodes[x]+=nodes[G[x][i]];
//		}
//}
//int lca(int x,int y)
//{
//	if(depth[x]<depth[y])//保证x深度≥y
//		swap(x,y);
//	while(depth[x]>depth[y])//将x提到同一高度
//		x=gene[x][lg[depth[x]-depth[y]-1]];
//	if(x==y)//是同一个节点
//		return x;
//	for(int i=lg[depth[x]];i>=0;i--)
//		if(gene[x][i]!=gene[y][i])
//		{//二分思想,直到跳到LCA的下面一层
//			x=gene[x][i];
//			y=gene[y][i];
//		}
//	return gene[x][0];
//}
//int dist(int x,int y)//x节点到y结点的距离
//{
//	int tem=lca(x,y);
//	return (int)(abs(depth[x]-depth[tem])+abs(depth[y]-depth[tem]));
//}
//void init(int s,int n)
//{
////	memset(nodes,0,sizeof(nodes));
//	memset(gene,0,sizeof(gene));
//	depth[s]=1;
//	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
//		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
//	dfs(s,0);
//}
//int query(int x,int y)
//{
//	int g=lca(x,y);
//	int ans=sum[x]+sum[y]-sum[g]-sum[gene[g][0]];
//	fprintf(stderr,"(%d,%d)=%d,g=%d\n",x,y,ans,g);
//	return qmod(2,ans);
//}
int dfn[maxn],low[maxn],stk[maxn],belong[maxn],siz[maxn],index=0,cnt=0,tim=0;
vector<int>G[maxn],g[maxn];
bool vis[maxn];
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++tim;
	vis[x]=1;//标记在栈中
	stk[++index]=x;
	for(int &v:g[x])
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
			belong[stk[index]]=cnt;
			fprintf(stderr,"c=%d,now=%d\n",cnt,stk[index]);
			vis[stk[index]]=0;
			index--;
			siz[cnt]++;
		}while(stk[index+1]!=x);
	}
}
const int maxl=30;
//vector<int> G[maxn];//无权边,也可以选择链式前向星存图
int gene[maxn][maxl],depth[maxn],lg[maxn],sum[maxn];
//int nodes[maxn];//子树结点的数量
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	sum[x]=sum[fa]+(siz[x]>1?1:0);
	fprintf(stderr,"sum[%d]=%d\n",x,sum[x]);
//	nodes[x]=1;
	for(int i=1;(1<<i)<=depth[x];i++)//倍增
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=fa)
		{
			dfs(G[x][i],x);//在dfs前后加语句可以求出许多有趣的东西
//			nodes[x]+=nodes[G[x][i]];
		}
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])//保证x深度≥y
		swap(x,y);
	while(depth[x]>depth[y])//将x提到同一高度
		x=gene[x][lg[depth[x]-depth[y]-1]];
	if(x==y)//是同一个节点
		return x;
	for(int i=lg[depth[x]];i>=0;i--)
		if(gene[x][i]!=gene[y][i])
		{//二分思想,直到跳到LCA的下面一层
			x=gene[x][i];
			y=gene[y][i];
		}
	return gene[x][0];
}
int dist(int x,int y)//x节点到y结点的距离
{
	int tem=lca(x,y);
	return (int)(abs(depth[x]-depth[tem])+abs(depth[y]-depth[tem]));
}
void init(int s,int n)
{
//	memset(nodes,0,sizeof(nodes));
	memset(gene,0,sizeof(gene));
	depth[s]=1;
	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
	dfs(s,0);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,q;
	cin>>n>>m;
	vector<pii>rec;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		rec.push_back(pii(u,v));
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tarjan(1,0);
	for(auto &i:rec)
		if(belong[i.ff]!=belong[i.ss])
		{
			G[belong[i.ff]].push_back(belong[i.ss]);
			G[belong[i.ss]].push_back(belong[i.ff]);
		}
//	build(n);
//	init(1,cnt);
	init(belong[1],n);
	cin>>q;
	while(q--)
	{
		cin>>u>>v;//有多少简单路径
//		if(depth[u]>depth[v])
//			swap(u,v);
//		int ans=query(belong[u],belong[v]);
//		int g=lca(u,v);
//		if(g==u&&gene[u][0]>n)
//		{
//			u=gene[u][0];
//			ans=max(ans,query(u,belong[v]));
//		}
		int x=belong[u],y=belong[v],g=lca(x,y);
		int ans=sum[x]+sum[y]-sum[g]-sum[gene[g][0]];
		cout<<qmod(2,ans)<<endl;
	}
	return 0;
}
/*
 * 2021-05-17-16.05.50
 * 保证联通的顶点仙人掌
 * 求u->v有经过多少环,包括自身
 * 用圆方树反而不太好统计
 * 因为这个是顶点仙人掌,大发慈悲放过了圆方树,每个方点大小>2则计数
 * 划掉,什么强迫症用什么圆方树,难写的一匹
 * 链上问题,可以通过树上差分做
*/

