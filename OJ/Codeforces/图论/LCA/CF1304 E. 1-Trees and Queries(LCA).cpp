#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
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
int gene[maxn][maxl],depth[maxn],lg[maxn];
int nodes[maxn];//子树结点的数量
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	nodes[x]=1;
	for(int i=1;(1<<i)<=depth[x];i++)//倍增
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=fa)
		{
			dfs(G[x][i],x);//在dfs前后加语句可以求出许多有趣的东西
			nodes[x]+=nodes[G[x][i]];
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
	dfs(s,0);
}
bool jud(int d,int k)
{
	if(d<=k&&(d%2==k%2))
		return 1;
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,u,v,a,b,x,y,k;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(1,n);
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>a>>b>>k;
		bool flag=0;//节点可以重复走
		if(jud(dist(a,b),k)||jud(dist(a,x)+dist(y,b)+1,k)||jud(dist(a,y)+dist(x,b)+1,k))
			flag=1;
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}


