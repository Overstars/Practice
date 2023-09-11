//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const{
		return c>r.c;//重载运算符<
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[maxn];//使用前必须清空0~n
int dist[maxn];//到这个点的最近队员的
void dijkstra(int n,int start)//传入总数及起点
{//点的编号从 1 开始
	vector<bool>visited(n+10,false);
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	priority_queue<qnode>que;
	while(!que.empty())
		que.pop();
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
//				printf("ch:dis[%d]=%d->%d\n",v,dist[v],dist[u]+cost);
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
char str[maxn];
int f[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n,m,s,t,x;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>s>>t>>x>>str+1;
		for(int i=1;i<=n;i++)
			if(str[i]=='M')
				f[i]=0;
			else if(str[i]=='L')
				f[i]=1;
			else
				f[i]=2;
		for(int i=0;i<=2*n+2;i++)
			E[i].clear();
		for(int i=1,u,v,w;i<=m;i++)
		{
			cin>>u>>v>>w;
			if(f[u]==f[v])
			{
				if(f[u]==0)
				{
					adde(u,v,w);//L->L
					adde(n+u,v,w+x);//R->L
					adde(u,n+v,w+x);//L->R
					adde(n+u,n+v,w);//R->R
				}
				else if(f[u]==1)
					adde(u,v,w);
				else
					adde(n+u,n+v,w);
			}
			else if(f[u]==0||f[v]==0)
			{
				if(f[u]==0)
				{
					if(f[v]==1)
					{
						adde(u,v,w);//L->L
						adde(n+u,v,w+x);//R->L
					}
					else{
						adde(n+u,n+v,w);//R->R
						adde(u,n+v,w+x);//L->R
					}
				}
				else{
					if(f[u]==1)
					{
						adde(u,v,w);//L->L
						adde(u,n+v,w+x);//L->R
					}
					else{
						adde(n+u,v,w+x);//R->L
						adde(n+u,n+v,w);//R->R
					}
				}
			}
			else if(f[u]==1)//L->R
				adde(u,n+v,w+x);
			else//R->L
				adde(n+u,v,w+x);
		}
//		for(auto &e:E[7])
//			printf("v->%d,w=%d\n",e.v,e.cost);
		int st=2*n+1,ed=2*n+2;
		adde(st,s,0);
		adde(st,n+s,0);
		adde(t,ed,0);
		adde(n+t,ed,0);
		dijkstra(ed,st);
//		for(int i=1;i<=ed;i++)
//			printf("dis[%d]=%d\n",i,dist[i]);
		cout<<dist[ed]<<endl;
	}
	return 0;
}


