//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
	ll v,c;
	qnode(ll _v=0,ll _c=0):v(_v),c(_c){}
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
void dijkstra(int n,int start)//传入总数及起点
{//点的编号从 1 开始
	vector<bool>visited(n+10,false);
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	priority_queue<qnode>que;
	dist[start]=0;
	que.push(qnode(start,0));
	while(!que.empty())
	{
		qnode now=que.top();
		que.pop();
		int u=now.v;
		if(visited[u])
			continue;
		visited[u]=true;
		for(auto &e:E[u])
		{
			int v=e.v,cost=e.cost;
			if(!visited[v]&&dist[v]>dist[u]+cost){
				dist[v]=dist[u]+cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void adde(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
	E[v].push_back(Edge(u,w));
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,s,t,l,r,c;
	char ch;
	scanf("%lld%lld",&n,&m);
//	cin>>n>>m;
	s=n*n+1,t=s+1;
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%lld %lld %c %lld",&l,&r,&ch,&c);
//		cin>>l>>r>>ch>>c;//总是设为右上节点
		if(ch=='L')//l->l+1
		{
			if(r==1)
				u=s;
			else
				u=(l-1)*(n-1)+r-1;
			if(r==n)
				v=t;
			else
				v=(l-1)*(n-1)+r;
		}
		else//r->r-1
		{
			if(l==1)
				u=s;
			else
				u=(l-2)*(n-1)+r-1;
			if(l==n)
				v=t;
			else
				v=(l-1)*(n-1)+r-1;
		}
		adde(u,v,c);
	}
	dijkstra(t,s);
	printf("%lld\n",dist[t]<INF?dist[t]:-1ll);
	return 0;
}
/*
 *平面图转对偶图,将s-t连接一条虚边
 */

