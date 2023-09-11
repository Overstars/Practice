//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
struct qnode{
	int v;
	ll c;
	qnode(int _v=0,ll _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];//使用前必须清空0~n
ll dist[maxn];//到这个点的最近队员的
bool have[maxn],del[maxn],visited[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,u,v;
	ll w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		E[u].push_back(Edge(v,w));
		E[v].push_back(Edge(u,w));
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		cin>>v>>w;
		have[v]=1;//标记有这条边
		if(dist[v]<INF)
			ans++;
		if(w<dist[v])
			dist[v]=w;
	}
//	vector<bool>visited(n+10,false);
	priority_queue<qnode>que;
	for(int i=1;i<=n;i++)
		if(dist[i]<INF)
			que.push(qnode(i,dist[i]));
	dist[1]=0;
	que.push(qnode(1,0));
	while(!que.empty())
	{
		qnode now=que.top();
		que.pop();
		int u=now.v;
//		printf("now=%lld\n",u);
		if(visited[u])//把这个去掉就好了...
			continue;
		visited[u]=true;
		for(auto &e:E[u])
		{
			int v=e.v,cost=e.cost;
			if(dist[v]>=dist[u]+cost)
				del[v]=1;//能被更新,直接到达并不最优
			if(!visited[v]&&dist[v]>dist[u]+cost)
			{
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(del[i]&&have[i])//统计可删点
			ans++;
//		if(del[i])
//			printf("%lld has been del.\n",i);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 4 3
1 2 999999999
2 3 1000000000
3 4 529529529
5 1 524524524
5 524444444
5 529999999
2 1000000000
ans=2
5 5 2
1 2 100
2 3 100
3 4 100
4 5 20
2 5 5
5 50
4 1
ans=1,加入的1->4(1->4->5)更新了1->5路径
*/

