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
const int maxl=30;
vector<int> G[maxn];//无权边,也可以选择链式前向星存图
int gene[maxn][maxl],depth[maxn],lg[maxn],dfn[maxn],tim=0;
//int nodes[maxn];//子树结点的数量
void dfs(int x,int fa)
{
	if(!dfn[x])
		dfn[x]=++tim;
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
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
//	memset(gene,0,sizeof(gene));
	depth[s]=1;
	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
	dfs(s,s);
}
int stk[maxn],top;
vector<int>g[maxn];
//vector<bool> vis;
map<int,bool>vis;
void build(vector<int> &rec,int n)
{
//	rec.push_back(1);
	sort(rec.begin(),rec.end(),[](const int &x,const int &y){
				return dfn[x]<dfn[y];
			});
//	rec.erase(unique(rec.begin(),rec.end()),rec.end());
//	for(int i=1;i<=n;i++)
//		g[i].clear();
	stk[top=1]=rec[0];
	g[1].clear();
	auto adde = [](int u,int v)
	{
		g[u].push_back(v);
	};
	for(int i=1;i<rec.size();i++)
	{
		int now=rec[i];
		int lc=lca(now,stk[top]);//最近公共祖先
		//printf("lca(%d,%d)=%d\n",now,stk[top],lc);
		while(top>1&&dfn[lc]<=dfn[stk[top-1]])//情况4,=是情况3
		{//不断将top送入虚树
			adde(stk[top-1],stk[top]);//前向星加边,构建新树
			top--;
		}
		if(dfn[lc]<dfn[stk[top]])//情况2
		{//加边,top出栈,lc和now入栈
			g[lc].clear();//奇怪的优化2
			adde(lc,stk[top]);
			stk[top]=lc;
		}//否则为情况1
		g[now].clear();//奇怪的优化
		stk[++top]=now;
	}
	while(--top)
		adde(stk[top],stk[top+1]);
}
int dp[maxn],f[maxn];
void dfs2(int x)
{
	dp[x]=f[x]=0;
	for(int &v:g[x])
	{
		dfs2(v);
		dp[x]+=dp[v];
		f[x]+=f[v];//统计节点与多少重要城市直接相连
	}
	if(vis[x])
	{//重要节点
		dp[x]+=f[x];
		f[x]=1;//本身是重要节点
	}
	else if(f[x]>1)
	{
		dp[x]++;//占领该节点
		f[x]=0;//被阻塞
	}//否则留到以后处理
//	printf("dp[%d]=%d\n",x,dp[x]);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v,q,k;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(1,n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		vector<int>rec;
		vis.clear();
		bool ok=1,ok1=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&u);
			if(u==1)
				ok1=1;
			vis[u]=true;
			rec.push_back(u);
		}
//		for(int &x:rec)
//			cerr<<"fa["<<x<<"] = "<<gene[x][0]<<endl;
		for(int &x:rec)
			if(x!=1&&vis[gene[x][0]])
			{//父节点也被标记
//				printf("%d - > %d\n",x,gene[x][0]);
				ok=0;
				break;
			}
		if(!ok)
		{
			printf("-1\n");
			continue;
		}
		if(!ok1)
			rec.push_back(1);
		build(rec,n);//构建虚树
		dfs2(1);
		printf("%d\n",dp[1]);
	}
	return 0;
}
/*
7
1 2
2 3
3 4
4 5
5 6
6 7
999
3 2 4 6
*/
/*
 *查询重要城市是否紧挨着
 *两个相邻则一定无解
 *否则构建虚树跑dp
 *看题解补题用时1时19分
 *2021年3月24日
*/

