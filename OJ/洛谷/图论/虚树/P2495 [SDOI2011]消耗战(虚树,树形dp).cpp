//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
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
	int v,nex;
	ll w;
	edge(int v=0,ll w=0,int nex=0):
		v(v),w(w),nex(nex){}
} e[maxn<<1];
int head[maxn],cnt=0;
void add(int u,int v,int w=0)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
const int maxl=30;
//vector<int> G[maxn];//无权边,也可以选择链式前向星存图
int gene[maxn][maxl],depth[maxn],lg[maxn],dfn[maxn],tim=0;
ll dp[maxn];
void dfs(int x,int fa)
{
	if(!dfn[x])
		dfn[x]=++tim;
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)//倍增
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=fa)
		{
			dp[e[i].v]=min(dp[x],e[i].w);
			dfs(e[i].v,x);//在dfs前后加语句可以求出许多有趣的东西
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
void init(int s,int n)
{
//	memset(gene,0,sizeof(gene));
	depth[s]=1;
	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
	dfs(s,0);
}
//#define ff first
//#define ss second
int h[maxn],stk[maxn],top=0;
bool key[maxn];
struct edge2
{
	int v,nex;
	edge2(int v=0,int nex=-1):
		v(v),nex(nex){};
} G[maxn<<1];
int head2[maxn],cnt2=0;
void adde(int u,int v)
{
	G[++cnt2].v=v;
	G[cnt2].nex=head2[u];
	head2[u]=cnt2;
}
ll dfs2(int x)
{//和x子树上所有关键点断掉联系的代价
//	printf("!%d!",x);
	ll sum=0,ret=0;
	for(int i=head2[x];~i;i=G[i].nex)
	{//与字数上所有关键节点断掉联系的代价和
		int v=G[i].v;
		sum+=dfs2(v);
	}
	if(key[x])//dp[x]表示节点1与x断掉的最小代价
		ret=dp[x];
	else//可以选择直接和x断掉联系,或者x与子树关键点断掉联系
		ret=min(dp[x],sum);
//	printf("node[%d]=%lld\n",x,ret);
	key[x]=0;
	head2[x]=-1;
	return ret;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(head,-1,sizeof(head));
	memset(head2,-1,sizeof(head2));
	int n,u,v,w,m,k;
	read(n);
//	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		read(u,v,w);
//		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dp[1]=INF;
	init(1,n);
//	for(int i=1;i<=n;i++)
//		printf("dp[%d]=%lld\n",i,dp[i]);
//	scanf("%d",&m);
	read(m);
	while(m--)
	{//m轮,k个资源丰富的点
//		scanf("%d",&k);
		read(k);
		for(int i=1;i<=k;i++)
		{
//			scanf("%d",&h[i]);
			read(h[i]);
			key[h[i]]=1;
		}
		sort(h+1,h+k+1,[](const int &x,const int &y){
				return dfn[x]<dfn[y];//按dfs序排序
			});
		stk[top=1]=h[1];
		cnt2=0;
		for(int i=2;i<=k;i++)
		{
			int now=h[i];
			int lc=lca(now,stk[top]);
//			printf("lca(%d,%d)=%d\n",now,stk[top],lc);
			while(top>1&&dfn[lc]<=dfn[stk[top-1]])//情况4,=是情况3
			{//不断将top送入虚树
				adde(stk[top-1],stk[top]);
				top--;
			}
			if(dfn[lc]<dfn[stk[top]])//情况2
			{//加边,top出栈,lc和now入栈
				adde(lc,stk[top]);
				stk[top]=lc;
			}//否则为情况1
			stk[++top]=now;
		}
		while(--top)
			adde(stk[top],stk[top+1]);
		printf("%lld\n",dfs2(stk[1]));//最后还会剩一个虚根节点
	}
	return 0;
}


