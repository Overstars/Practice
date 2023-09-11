//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
struct edge
{
	int v,w;
	edge(){}
	edge(int v,int w):
		v(v),w(w){}
	bool operator < (const edge &y)const
	{
		return w>y.w;
	}
};
vector<edge>G[maxn];
inline void adde(int u,int v,int w)
{
	G[u].push_back(edge(v,w));
}
//一棵树占4n的空间
int n,shift;
void build(int x,int l,int r)
{
	if(l==r)
	{//是叶子,向真正节点连边,双向0权
		adde(x,l+2*shift,0);//合并出树叶子与原点
		adde(l+2*shift,x,0);
		adde(x+shift,l+2*shift,0);//合并点与入树叶子
		adde(l+2*shift,x+shift,0);
		return;
	}
	adde(x<<1,x,0);//出树,儿子向父亲建0权边,[l,r]->u
	adde(x<<1|1,x,0);//右儿子->父
	adde(x+shift,x*2+shift,0);//入树,父亲向儿子建0权边,u->[l,r]
	adde(x+shift,x*2+1+shift,0);//父->右儿子
	int mid=(l+r)>>1;
	build(x<<1,l,mid);//左子树
	build(x<<1|1,mid+1,r);//右子树
}
void add(int p,int l,int r,int nl,int nr,int x,int w,bool in)
{
	if(nl>r||nr<l)
		return;
	if(l<=nl&&nr<=r)
	{
		if(in)
			return adde(x+2*shift,p+shift,w);//入树,x->[l,r]
		else
			return adde(p,x+2*shift,w);//[l,r]->x;
	}
	int mid=(nl+nr)/2;
	add(p<<1,l,r,nl,mid,x,w,in);
	add(p<<1|1,l,r,mid+1,nr,x,w,in);
}
int dist[maxn];
void dijkstra(int s)
{
	for(int i=1;i<=n+2*shift;i++)
		dist[i]=INF;
	vector<bool> vis(n+2*shift+1,false);
	priority_queue<edge>q;
	q.push(edge(s,0));
//	dist[s]=0;
	while(!q.empty())
	{
		edge now=q.top();
		int x=now.v;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
//		printf("%lld has been visited.\n",x);
		dist[x]=now.w;
		for(edge &i:G[x])
		{
			if(!vis[i.v]&&dist[i.v]>dist[x]+i.w)
			{
				dist[i.v]=dist[x]+i.w;
				q.push(edge(i.v,dist[i.v]));
			}
		}
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int q,s,ope,u,v,w,l,r;
	cin>>n>>q>>s;
	shift=4*n;
	build(1,1,n);//先对于in树和out树建边
//	assert(n>=1);
	for(int i=1;i<=q;i++)
	{
		cin>>ope;
		if(ope==1)
		{
			cin>>u>>v>>w;
			adde(u+2*shift,v+2*shift,w);
		}
		else if(ope==2)
		{
			cin>>u>>l>>r>>w;//x->[l,r]
			add(1,l,r,1,n,u,w,1);
		}
		else{
			cin>>u>>l>>r>>w;
			add(1,l,r,1,n,u,w,0);
		}
	}
	dijkstra(s+2*shift);
	for(int i=1;i<=n;i++)
		cout<<(dist[i+2*shift]==INF?-1:dist[i+2*shift])<<' ';
	return 0;
}
/*
 * https://www.luogu.com.cn/problem/CF786B
 * n个点的有向带权图,有三种连有向边
 * 1.u到v
 * 2.u到点[l,r]都有一条边
 * 3.[l,r]到v都有一条边
 * 问从s出发的全局最短路
 * 建图肯定不能暴力建图...
 * https://www.luogu.com.cn/blog/_post/262486
*/

