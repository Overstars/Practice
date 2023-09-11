//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
//		for(int i=1;i<=n;i++)
//			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
int mindiv[maxn]={0,1},depth[maxn],lcadep[maxn];
int w[maxn],m,n,stk[maxn],top=0;
vector<int> G[maxn];
inline void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void build()
{
	n=m;
	stk[top=1]=1;
	for(int i=2;i<=m;i++)
	{
		while(top>1&&lcadep[i]<=depth[stk[top-1]])
		{
//			printf("%d->%d\n",stk[top-1],stk[top]);
			add(stk[top-1],stk[top]),top--;
		}
		if(lcadep[i]<depth[stk[top]])
		{//lca在top和top-1之间
			depth[++n]=lcadep[i];//加入了非关键节点
			add(n,stk[top]);
			stk[top]=n;//lca入栈,now入栈
		}
		stk[++top]=i;
	}
	while(--top)
		add(stk[top],stk[top+1]);
}
ll ans=0,dp[maxn],sum[maxn];
void dfs(int x,int fa)
{
	dp[x]=0;
	sum[x]=w[x];
	ans+=w[x]*depth[x];//距离
	for(auto &v:G[x])
		if(v!=fa)
		{
			dfs(v,x);
			sum[x]+=sum[v];
		}
//	printf("sum[%d]=%lld,fa[%d]=%d,\n",x,sum[x],x,fa);
}
void dfs2(int x,int fa)
{
	ans=min(ans,dp[x]);
//	printf("dp[%d]=%lld\n",x,dp[x]);
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dp[v]=dp[x]+(sum[1]-2*sum[v])*(depth[v]-depth[x]);
//		printf("depth[%d]=%d,depth[%d]=%d\n",x,depth[x],v,depth[v]);
		dfs2(v,x);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	const int lim=1e5+10005;
	for(int i=2;i<=lim;i++)
		if(!mindiv[i])//筛法记录最小因子
			for(int j=i;j<=lim;j+=i)
				if(!mindiv[j])
					mindiv[j]=i;
	//预处理完毕
	while(cin>>m)
	{
		for(int i=1;i<=n;i++)
			G[i].clear(),w[i]=bit.c[i]=bit.sum[i]=0;
		for(int i=1;i<=m;i++)
			cin>>w[i];
		bit.n=m;
//		bit.build(m);
		for(int i=2;i<=m;i++)
		{//i!在原本树上的的深度
			depth[i]=depth[i-1]+1;//(i-1)!基础上+多出来的质因子个数即为深度
			int j=i;
			for(;j!=mindiv[j];j/=mindiv[j])//直到j不为质数
				depth[i]++;//处理i对于深度的贡献
			//i!到1的深度处理好了
			//处理完后j=maxdiv(i)
	//		printf("query=%d\n",bit.query(m)-bit.query(j-1));
			lcadep[i]=bit.query(m)-bit.query(j-1);//查询到j有多少个元素,因为这个树
			for(j=i;j!=1;j/=mindiv[j])
				bit.radd(mindiv[j],mindiv[j],1);
		}
		build();
		ans=0;
		dfs(1,1);
		dp[1]=ans;
		dfs2(1,1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
9
0 4 4 4 8 9 1 2 1
*/

