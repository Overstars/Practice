//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
#define lowbit(x) ((x) & -(x))
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
	for(int i=0;i<=n;i++)
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
			int v=e.v;
			ll cost;//根据到达的点权计算
			if(e.v<=32)//&&u!=start)//第v组最低位在v,代价就是2^v
				cost=(1ll<<v);//距离dist[k]的定义是转移到达末尾为k个0的同一组数据的最小的代价
			else
				cost=0;
//			int v=e.v,cost=e.cost;
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
ll a[maxn],mp[40];//花费2^i可达的位
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<=40;i++)
			E[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mp[(int)(log(lowbit(a[i]))/log(2))]|=a[i];//分成32个组,到达组内其他值的花费为lowbit
		}
		for(int i=0;i<32;i++)//
			for(int j=0;j<32;j++)//
				if(mp[i]&(1ll<<j))
				{//i,j位可达,消耗2^i相互转移
					adde(i,j,0);
				}
		int st=39,ed=40;
		for(int i=0;i<32;i++)
		{//虚点,单双向都行
			if(a[1]&(1ll<<i))//起点
				E[st].push_back(Edge(i));
			if(a[n]&(1ll<<i))//终点
				E[i].push_back(Edge(ed));
		}
		dijkstra(ed,st);
//		for(int i=0;i<=40;i++)
//			printf("dist[%d]=%lld\n",i,dist[i]);
		if(dist[ed]<INF)
			cout<<dist[ed]<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}
/*
9
4
5 21 18 10
*/

