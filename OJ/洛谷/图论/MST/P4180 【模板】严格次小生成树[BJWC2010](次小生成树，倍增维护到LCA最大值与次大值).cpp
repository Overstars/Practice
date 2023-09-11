#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long INF=LLONG_MAX;
const int maxn=100005;
const int maxl=31;
struct edge
{
	int u,v;
	ll w;
	edge(int u=0,int v=0,ll w=0):
		u(u),v(v),w(w){}
} e[maxn<<2];
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
int father[maxn];
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
vector<edge> G[maxn];
bool intree[maxn<<2];
ll kruskal(int n,int m)
{
	memset(intree,0,sizeof(intree));
	for(int i=0;i<=n;i++)
		father[i]=i;
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
int gene[maxn][maxl],depth[maxn],lg[maxn];
ll MAX[maxn][maxl],sec[maxn][maxl];//最大值and严格次大值
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
	{
		gene[x][i]=gene[gene[x][i-1]][i-1];
		MAX[x][i]=max(MAX[x][i-1],MAX[gene[x][i-1]][i-1]);
		if(MAX[x][i-1]==MAX[gene[x][i-1]][i-1])
			sec[x][i]=max(sec[x][i-1],sec[gene[x][i-1]][i-1]);//严格次小
		else
			sec[x][i]=max(min(MAX[x][i-1],MAX[gene[x][i-1]][i-1]),max(sec[x][i-1],sec[gene[x][i-1]][i-1]));
	}
	for(int i=0;i<G[x].size();i++)
		if(G[x][i].v!=fa)
		{
			MAX[G[x][i].v][0]=G[x][i].w;
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
	for(int i=lg[depth[x]];i>=0;i--)//二分思想,跳到LCA的下面一层
		if(gene[x][i]!=gene[y][i])
		{
			x=gene[x][i];
			y=gene[y][i];
		}
	return gene[x][0];
}
void init(int s,int n)
{
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
//	memset(gene,0,sizeof(gene));
	memset(MAX,0,sizeof(MAX));
	memset(sec,0,sizeof(sec));
	gene[s][0]=0;//
	depth[s]=1;//根节点深度
	dfs(s,0);
}
ll solve(int no)//传入排序后的节点编号
{
	int u=e[no].u,v=e[no].v;
	int a=lca(u,v);
//	int diff1=depth[u]-depth[a];
	ll M1=0,m1=0;
	int tem=u;
	for(int i=lg[depth[u]]+1;i>=0;i--)
	{
		if(depth[gene[tem][i]]>=depth[a])
		{
			m1=max(m1,sec[tem][i]);
			if(M1<MAX[tem][i])
			{
				m1=max(m1,M1);
				M1=MAX[tem][i];
			}
			tem=gene[tem][i];
		}
	}
//	int diff2=depth[v]-depth[a];
	ll M2=0,m2=0;
	tem=v;
	for(int i=lg[depth[v]]+1;i>=0;i--)
	{
		if(depth[gene[tem][i]]>=depth[a])
		{
			m2=max(m2,sec[tem][i]);
			if(M2<MAX[tem][i])
			{
				m2=max(m2,M2);
				M2=MAX[tem][i];
			}
			tem=gene[tem][i];
		}
	}
	#ifdef DEBUG
	printf("lg[u]=%d,lg[v]=%d\n",lg[depth[u]]+1,lg[depth[v]]+1);
	printf("%d->%d,lca=%d,w=%lld\n",e[no].u,e[no].v,a,e[no].w);
	printf("M1=%lld,m1=%lld,M2=%lld,m2=%lld\n",M1,m1,M2,m2);
	#endif // DEBUG
	if(M1>M2)//返回w-M1
	{
		if(e[no].w==M1)
			return min(min(e[no].w-m1,e[no].w-m2),e[no].w-M2);//减去次大
		else
			return e[no].w-M1;//新加入边边权减去回路上最大的原边边权
	}
	else{
		if(e[no].w==M2)
			return min(min(e[no].w-m1,e[no].w-m2),e[no].w-M1);//严格次小
		else
			return e[no].w-M2;
	}
}
//#define DEBUG
int main()
{
	#ifdef DEBUG
		freopen("P4180.in","r",stdin);
	#endif // DEBUG
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	ll val=kruskal(n,m),inc=INF;//要用倍增求出最大值和次大值
	init(1,n);
	#ifdef DEBUG
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
		{
			cout<<"MAX["<<i<<"]["<<j<<"]="<<MAX[i][j]<<endl;
			cout<<"sec["<<i<<"]["<<j<<"]="<<sec[i][j]<<endl;
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			cout<<"gene["<<i<<"]["<<j<<"]="<<gene[i][j]<<endl;
	for(int i=1;i<=n;i++)
		for(int j=0;j<G[i].size();j++)
		{
			printf("%d->%d\n",i,G[i][j].v);
//			cout<<"G["<<i<<"]["<<j<<"]="<<G[i][j].v<<endl;
		}
	#endif // DEBUG
	for(int i=0;i<m;i++)
		if(!intree[i])
		{
			inc=min(inc,solve(i));
		}
	cout<<val+inc<<endl;
	return 0;
}
