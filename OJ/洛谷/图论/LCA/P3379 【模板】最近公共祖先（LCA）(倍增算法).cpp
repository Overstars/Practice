//#pragma GCC optimize("O2")
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=500005;
const int maxl=30;//之前开小了
int gene[maxn][maxl],depth[maxn];
int lg[maxn];//预处理出log2(i)+1的值
vector<int> G[maxn];//存无权边
void dfs(int x,int fa)//dfs预处理
{
	depth[x]=depth[fa]+1;//得到节点深度
	gene[x][0]=fa;//父亲节点
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=fa)
		{
//			dist[G[x][i]]=dist[x]+G[x].w;//树上到s距离可以这么处理
			dfs(G[x][i],x);
		}
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])//保证x深度≥y
		swap(x,y);
	while(depth[x]>depth[y])//将x提到同一高度
		x=gene[x][lg[depth[x]-depth[y]]-1];
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
void init(int s)
{
//	memset(gene,0,sizeof(gene));
	gene[s][0]=0;//
	depth[s]=0;//根节点深度
	dfs(s,0);
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("P3379.in","r",stdin);
		freopen("P3379.ans", "w", stdout);
	#endif
	int n,m,s,u,v;
//	cin>>n>>m>>s;//节点个数n,询问个数m,根节点s
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
	{
//		lg[i]=lg[i>>1]+1;
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(s);
	for(int i=0;i<m;i++)
	{
//		cin>>u>>v;
//		cout<<lca(u,v)<<'\n';
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
