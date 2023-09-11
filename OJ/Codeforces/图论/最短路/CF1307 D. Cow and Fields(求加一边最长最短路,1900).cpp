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
int dis1[maxn],dis2[maxn];//到这个点的最近队员的
void dijk(int dist[],int n,int start)//传入总数及起点
{//点的编号从 1 开始
	vector<bool>visited(n+10,false);
	for(int i=1;i<=n;i++)
		dist[i]=inf;
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
//				pre[v]=u;//记录最短路径
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,tmp;
	cin>>n>>m>>k;
	vector<int>rec(k);
	for(int &x:rec)
		cin>>x;
	for(int i=1,u,v;i<=m;i++)
		cin>>u>>v,adde(u,v,1);
	dijk(dis1,n,1);//1->x距离
	dijk(dis2,n,n);//x->n距离
	#define ff first
	#define ss second
	vector<pii>dis(k);
	int ind=0;
	for(int &x:rec)//1到i的距离
	{
		dis[ind].ff=dis1[x]-dis2[x];//
		dis[ind++].ss=x;//标记节点
	}
	sort(dis.begin(),dis.end());
	int ans=0,pre=-inf;
	for(auto &p:dis)//按d1-d2对节点排序,使(1->b)+(a->n)大于(1->a)+(b->n)
	{//使d1-d2递增,xd1+yd2>yd1+xd2
		int x=p.ss;
		ans=max(ans,pre+dis2[x]);//枚举a->n,综合即(1->b)+(a->n)
		pre=max(pre,dis1[x]);//维护1->b的最大值
	}
	cout<<min(ans+1,dis1[n])<<endl;
	return 0;
}
/*
 *列表里平均要用一小时出头
 *如果任选点的话,最长最短路无疑是原本1->n最短路
 *正向考虑了20min,无果...考虑一开始把边加上去?但是好多边啊...
 *嘤嘤嘤,瞄了眼题解,要分别以1和n为起点跑最短路
*/

