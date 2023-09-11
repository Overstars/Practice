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
int gene[maxn][maxl],depth[maxn],lg[maxn];
ll nodes[maxn];//子树结点的数量
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
	fprintf(stderr,"siz[%d]=%lld\n",x,nodes[x]);
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
//bool dist(int x,int L,int R)
//{
//	int g=lca(L,R);
//	int ok=0;
//	if(x==g)//x是L与R祖先
//		ok=1;
//	else if(lca(g,x)!=g)//x不在g子树上
//		ok=0;
//	else{
//
//	}
//	return ret;
//}
void init(int s,int n)
{
//	memset(nodes,0,sizeof(nodes));
//	memset(gene,0,sizeof(gene));
	gene[0][0]=0;
	depth[s]=1;
	for(int i=1;i<=n;i++)//预处理出log2(i)+1的值
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);//不要写错
	dfs(s,s);
}
ll ans[maxn],l,r,n;
bool vis[maxn];
bool add(int x)
{
	if(vis[x])//已经在链上
		return 1;
	int tar=-1,p=x;//记录位置
//	fprintf(stderr,"g(%d,%d)=%d\n",x,l,lca(x,l));
//	fprintf(stderr,"g(%d,%d)=%d\n",x,r,lca(x,r));
//	if(lca(x,l)==l)
//		tar=l;
//	else if(lca(x,r)==r)
//		tar=r;
//	if(tar==-1)//不可能维护好这条链
//		return 0;
	ll sum=nodes[x];
	while(!vis[x])
	{//向上跳
		vis[x]=1;//父节点的该子树不再产生贡献,看样例1
		nodes[gene[x][0]]-=sum;
		sum+=nodes[gene[x][0]];
		x=gene[x][0];
	}
	if(x==l)//延长端点
		l=p;
	else if(x==r)
		r=p;
	else
		return 0;
	return 1;
}
signed main(signed argc, char const *argv[])
{
//	srand(time(0));
//	cout<<rand()%1500<<endl;
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	for(int i=1;i<=100;i++)
//		cout<<__gcd((int)pow(2,i),i)<<endl;
	int t,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			ans[i]=0;
			vis[i]=0;
			G[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		init(0,n);
		l=r=0;
		ans[0]=(ll)n*(n-1)/2;//
		vis[0]=1;//链从0开始扩展
		vis[n]=1;
		auto calc = []()
		{//计算当前链两边能组成多少
			if(l==r)//mex=1
			{
				ll sum=0,sum2=0;
				for(auto &v:G[l])
				{
					sum2+=nodes[v];
					sum+=nodes[v]*(n-1-nodes[v]);
				}
				return sum/2+sum2;
			}
			return nodes[l]*nodes[r];
		};
		for(int i=1;i<=n;i++)
		{//已经包含了[0,i-1]的所有点
			ans[i]=calc();//统计mex>=i的点对数量
			fprintf(stderr,"ans[%d]=%lld\n",i-1,ans[i-1]);
			ans[i-1]-=ans[i];
			if(!add(i))//如果不能加入i点
				break;
		}
		for(int i=0;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
5
1 0
2 1
3 1
4 3
这个是不能用lca的
*/
/*
 * 2021-05-21-20.12.19
 * C:\Users\dell\Desktop\C++\OJ\Codeforces\图论\树论\CF1527 D. MEX Tree(dfs乱搞,2400).cpp
 * 一条路径mex=i,那么就要包含i-1,i-2,...1所有点
 * 以0为根节点,从1->n统计答案
 * ans=0的点对数目很好计算
 * 总点对数-不经过0节点的点对数,如果经过了0的话,mex必定>0
 * mex=i的点对总会重合到一条链,我们就维护这条链
 * 如果mex=i-1,如果想要让mex增大至i,则必须在这条链基础上延伸两端
 * 直至集齐[0,i-1]所有元素,显然目前链上缺少i-1
 * 如果i-1可以直接通过当前维护的链端点延伸(枚举lca),那么直接加入并统计
 * 可能达到i-1点时,mex并不为i(i可能在之前的链上),维护一下此时的mex,并寻找mex
 * 否则,则i-1加入必定会产生不可避免的分裂点,不可能使一条链上同时集齐[1,i-1],此时i-1之后所有答案都为0
 * 可以发现答案并不好统计,因为加入了i-1时mex反而可能会>i
 * 那么我们可以通过后缀和解决这个问题
 * 对于每个答案ans[i],记录mex>=i的点对数
*/

