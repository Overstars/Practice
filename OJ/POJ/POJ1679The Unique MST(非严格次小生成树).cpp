//#pragma GCC optimize(2)
//#pragma G++ optimize("O2") //O2优化
//#pragma comment(linker, "/STACK:102400000,102400000") //手动扩栈
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=205;
const int maxl=30;
struct edge
{
	int u,v;
	ll w;
	edge(int u=0,int v=0,ll w=0):
		u(u),v(v),w(w){}
} e[maxn*maxn];
vector<edge> G[maxn];//MST
int gene[maxn][maxl],depth[maxn],lg[maxn],father[maxn];
int MAX[maxn][maxl],sec[maxn][maxl];//最大值and不严格次大值
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
	{
		gene[x][i]=gene[gene[x][i-1]][i-1];
		MAX[x][i]=max(MAX[x][i-1],MAX[gene[x][i-1]][i-1]);
//		if(MAX[x][i-1]==MAX[gene[x][i-1]][i-1])
//			sec[x][i]=MAX[gene[x][i-1]][i-1];//非严格次小
	}
	for(int i=0;i<G[x].size();i++)
		if(G[x][i].v!=fa)
		{
			MAX[G[x][i].v][0]=G[x][i].w;//到父结点的距离
			dfs(G[x][i].v,x);
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
	memset(MAX,0,sizeof(MAX));
//	memset(sec,0,sizeof(sec));
	gene[s][0]=0;
	depth[s]=1;
	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
	dfs(s,0);
}
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
int findfa(int x)
{
	if(father[x]!=x)
		father[x]=findfa(father[x]);
	return father[x];
}
inline bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a>b)
		father[a]=b;
	else
		father[b]=a;
	return 1;
}
bool intree[maxn*maxn];
ll kruskal(int n,int m)
{
	memset(intree,0,sizeof(intree));
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		G[i].clear();
	}
	sort(e,e+m,cmp);
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		if(Merge(e[i].u,e[i].v))
		{
			intree[i]=1;//标记选中
			G[e[i].u].push_back(edge(e[i].u,e[i].v,e[i].w));//建立新图
			G[e[i].v].push_back(edge(e[i].v,e[i].u,e[i].w));
			ans+=e[i].w;
			n--;
			if(n==1)
				return ans;
		}
	}
	return 0;
}
ll solve(int no)//将no加入到MST上,返回最小增量
{
	int u=e[no].u,v=e[no].v;
	int a=lca(u,v);
	int tmp=u,M1=0,M2=0;//返回形成回路上,MST的最大边权
	for(int i=lg[depth[u]]+1;i>=0;i--)
	{//u->lca
		if(depth[gene[tmp][i]]>=depth[a])
		{
			M1=max(M1,MAX[tmp][i]);
			tmp=gene[tmp][i];
		}
	}
	tmp=v;
	for(int i=lg[depth[v]]+1;i>=0;i--)
	{//v->lca
		if(depth[gene[tmp][i]]>=depth[a])
		{
			M2=max(M2,MAX[tmp][i]);
			tmp=gene[tmp][i];
		}
	}
//	printf("u=%d,v=%d,M1=%d,M2=%d\n",u,v,M1,M2);
	return e[no].w-max(M1,M2);
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			e[i].u=x,e[i].v=y,e[i].w=z;
		}
		ll val=kruskal(n,m),inc=LLONG_MAX;
		init(1,n);//在MST上操作
		for(int i=0;i<m;i++)
			if(!intree[i])
				inc=min(inc,solve(i));
		if(inc>0)
			printf("%lld\n",val);
		else
			printf("Not Unique!\n");
	}
	return 0;
}
