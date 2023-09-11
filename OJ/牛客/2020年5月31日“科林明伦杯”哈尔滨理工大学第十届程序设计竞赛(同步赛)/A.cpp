#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int c[maxn];//点权
ll dp[maxn][2],siz[maxn],from[maxn];//dp[i][0]表示子树上到i的最大,1次大
struct edge
{
	int v,w;
	edge(int v,int w)://列表初始化
		v(v),w(w){}
};
vector<edge>G[maxn];
void dfs(int x,int fa)
{//0表示最大,1表示次大
	if(G[x].size()==1&&x!=1)//除了根节点的叶子
		dp[x][0]=c[x],dp[x][1]=-inf;//*端点*的自身贡献,dp只计算其中子树上的端点贡献,另一个端点贡献在枚举时计算
	else
		dp[x][0]=dp[x][1]=-inf;//等待递归时更新
	siz[x]=1;
	for(auto &e:G[x])
	{
		if(e.v==fa)
			continue;
		dfs(e.v,x);
		siz[x]+=siz[e.v];//子树大小,用于判断是否为端点
		if(c[e.v]+e.w>dp[x][0])
		{//将v作为链的一端尝试更新
			dp[x][1]=dp[x][0];
			dp[x][0]=c[e.v]+e.w;
			from[x]=e.v;//最大来源标记为e.v
		}
		else if(c[e.v]+e.w>dp[x][1]&&from[x]!=e.v)
		{//保证最大和次大来源不是一个亲儿子
			dp[x][1]=(ll)c[e.v]+e.w;
		}//相当于找以x为中转点的最大的两条链
		if(dp[e.v][0]+e.w>dp[x][0])
		{//以亲儿子v的最大值+到x的边权,尝试更新最大和次大
			dp[x][1]=dp[x][0];
			dp[x][0]=dp[e.v][0]+e.w;
			from[x]=e.v;//最大来源标记为e.v
		}
		else if(dp[e.v][0]+e.w>dp[x][1]&&from[x]!=e.v)
		{//同上
			dp[x][1]=dp[e.v][0]+e.w;
		}
	}
//	printf("c[%d]=%d,siz=%lld,%lld,%lld\n",x,c[x],siz[x],dp[x][0],dp[x][1]);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,u,v,tmp1,tmp2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{//初始化
			G[i].clear();
			siz[i]=from[i]=0;
		}
		for(int i=2;i<=n;i++)
		{//i与tmp1链接
			cin>>tmp1>>tmp2;
			G[tmp1].push_back(edge(i,tmp2));//邻接表加边
			G[i].push_back(edge(tmp1,tmp2));
		}
		for(int i=1;i<=n;i++)
			cin>>c[i];//节点贡献
		dfs(1,0);//树形dp
		ll ans=LLONG_MIN;
		for(int i=1;i<=n;i++)
		{//枚举节点i
			if(siz[i]>1)//i非端点
			{
				ans=max(ans,dp[i][0]+dp[i][1]);//以i为中转点
				ans=max(ans,dp[i][0]+c[i]);//以i为端点
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
2
2
1 100
-1 -1
3
1 -10
1 -20
100 3 -4
*/

