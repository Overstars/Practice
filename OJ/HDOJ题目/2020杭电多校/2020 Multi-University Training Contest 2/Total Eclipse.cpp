//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll val[maxn]={inf},dp[maxn],ans=0;
bool vis[maxn],flag[maxn];
//void dfs(int x)
//{
//	if(vis[x])
//		return;
//	vis[x]=1;
//	dp[x]=val[x];//处理x子树的代价
//	ll MIN=LLONG_MAX,MAX=LLONG_MIN;
//	for(auto &v:G[x])
//	{
//		if(vis[v])
//			continue;
//		dfs(v);
//		if(val[x]>val[v])
//			dp[x]+=dp[v]-val[v];
//		else if(dp[v]>val[x])
//			dp[x]+=dp[v]-val[x];
////		if(dp[v]>val[x])
////			dp[x]+=dp[v]-val[x];
////		if(val[x]>val[v])
//		MAX=max(MAX,val[v]);
////		else if(val[v]==val[x])
////			dp[x]=max(dp[x],dp[v]);
////		else
////			dp[x]+=
////		if(!flag[v]&&val[v]>val[x])
////			dp[x]+=val[v]-val[x];
////		else if(flag[v])
////			dp[v]+=
////		MAX=max(MAX,val[v]);
//	}
////	printf("dp[%d]=%lld\n",x,dp[x]);
////	if(MAX<=val[x]&&MAX>LLONG_MIN)//子节点都比x权值小
////		dp[x]+=val[x]-MAX;
////	else{//存在比它大的子节点
////		flag[x]=1;
////	}
//}
struct node
{
	int x;
	ll vall;
	node(){}
	node(int x,ll v):
		x(x),vall(v){}
	bool operator<(const node&b)const
	{return val[x]<val[b.x];}
};
struct cmp{
    bool operator() (int a,int b){
    	if(val[a]>val[b])
			return true;
		else
			return false;
//        return val[a]>val[b];
    }
};
struct edge
{
	int v;
	edge(){}
	edge(int v):
		v(v){}
	bool operator<(const edge&b)const
	{
		if(val[v]==val[b.v])
			return v<b.v;
		return val[v]>val[b.v];
	}
};
set<edge> G[maxn];//邻接表
void bfs(int x,int n)
{
//	printf("%d has been visited,val=%lld.\n",x,val[x]);
	vector<bool> vis(n+1,false);
	priority_queue<node>pq;
	pq.push(node(x,val[x]));
	while(!pq.empty())
	{
		int x=pq.top().x;
		ll c=pq.top().vall;
		pq.pop();
		vis[x]=0;
//		printf("%d:%lld-%d\n",x,val[x],c);
		for(set<edge>::iterator it=G[x].begin();it!=G[x].end();it++)
		{
			int v=it->v;
//			printf("%d->%d\n",x,v);
			if(val[v]>0&&!vis[v])
			{
				vis[v]=1;
				pq.push(node(v,min(c,val[v])));
			}
		}
		val[x]-=c;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,u,n,m,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
//		tot=cnt=Index=0;
		for(int i=1;i<=n;i++)
		{
			cin>>val[i];
			G[i].clear();
//			G[i].insert(0);
			vis[i]=flag[i]=0;
//			dp[i]=0;
//			rec[i]=dfn[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			G[u].insert(edge(v));
			G[v].insert(edge(u));
		}
		ans=0;
		priority_queue<node>now;
		for(int i=1;i<=n;i++)
			now.push(node(i,val[i]));
		while(!now.empty())
		{
			int x=now.top().x;
			now.pop();
			if(val[x]==0)
				break;
//			printf("x=%d,val=%lld\n",x,val[x]);
			ans+=val[x];
			bfs(x,n);
//			dfs(x,val[x]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4
6 5
6 1 1 6 5 6
1 2
2 3
3 4
3 5
5 6
3 2
3 2 3
1 2
2 3
1 0
8
3 3
2 3 4
1 2
2 3
3 4
ans=16,4,8,4//棒槌,样例,点,环
1
7 6
1 6 1 6 4 1 6
1 2
2 3
3 4
3 5
2 6
6 7
ans=19//二叉树
1
6 5
2 3 4 5 6 7
1 2
1 3
1 4
1 5
1 6
ans=17//菊花
1
4 6
6 5 3 4
1 2
1 3
1 4
2 3
2 4
3 4
ans=6//完全图
1
5 6
3 1 1 1 3
1 2
1 3
1 4
2 5
3 5
4 5
ans=3//骚气的构造
*/

