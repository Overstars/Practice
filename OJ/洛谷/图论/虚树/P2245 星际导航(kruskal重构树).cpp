#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
struct edge
{
	int u,v,w;
};
vector<edge>E;
const int maxl=20;
vector<int> G[maxn];//无权边,也可以选择链式前向星存图
int gene[maxn][maxl],depth[maxn],lg[maxn];
//int nodes[maxn];//子树结点的数量
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
//	nodes[x]=1;
	for(int i=1;(1<<i)<=depth[x];i++)//倍增
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int &v:G[x])
		if(v!=fa)
		{
			dfs(v,x);//在dfs前后加语句可以求出许多有趣的东西
//			nodes[x]+=nodes[v];
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
	dfs(s,s);
}
int val[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w,q;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	sort(E.begin(),E.end(),[](const edge &a,const edge &b){
			return a.w<b.w;
		});
	int tot=n;
//	printf("!!!\n");
	for(auto &e:E)
	{
		int a=findfa(e.u),b=findfa(e.v);
		if(a==b)
			continue;
//		printf("a=%d,b=%d,val=%d\n",a,b,e.w);
		fa[a]=fa[b]=++tot;//合并并查集
		val[tot]=e.w;//新lca的权值
		G[tot].push_back(a);//新节点指向原来并查集的根
		G[tot].push_back(b);
	}
//	printf("???\n");
	init(tot,tot);//处理重构树lca
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		if(findfa(u)!=findfa(v))
		{
			cout<<"impossible\n";
			continue;
		}
		cout<<val[lca(u,v)]<<'\n';
	}
	return 0;
}
/*
 *n点m边无向图
 *u到v选择一条路线,使最大边最小化
*/

