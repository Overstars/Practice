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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
struct edge
{
	int u,v,w;
	edge(){}
	edge(int u,int v,int w):
		u(u),v(v),w(w){}
};
vector<edge> E;
ll boruvka(int n)
{
	for(int i=1;i<=n;i++)//n个连通块
		fa[i]=i;
	ll ans=0;
	vector<int> cost(n+1),rec(n+1);
	vector<bool> vis(E.size(),false);
	while(1)
	{
		for(int i=1;i<=n;i++)
			cost[i]=INF;//初始化为inf
		int cur=0;//统计不同连通块
		for(int i=0;i<E.size();i++)
		{
			int a=findfa(E[i].u),b=findfa(E[i].v),w=E[i].w;
			if(a==b)
				continue;
			cur++;//记录a,b两个连通块连接的最小代价
			if(w<cost[a])
				cost[a]=w,rec[a]=i;//记录最小联通代价与相应边
			if(w<cost[b])
				cost[b]=w,rec[b]=i;
		}
		if(cur==0)
			break;
		for(int i=1;i<=n;i++)
		{//最坏情况是连接的连通块数目/2
			if(cost[i]<INF&&!vis[rec[i]])//与i相接的权值最小的边未加入
			{
				Merge(E[rec[i]].u,E[rec[i]].v);//连接两个连通块
				ans+=E[rec[i]].w;
				vis[rec[i]]=true;
			}
		}
	}
	return ans;
}
int a[maxn];
bool del[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w,miv=INF,rec=0;
	cin>>n>>m;
	vector<pii>node;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],fa[i]=i;
		if(a[i]<miv)
			miv=a[i],rec=i;
//		node.push_back(pii(a[i],i));//权值,编号
	}
	for(int i=1;i<=n;i++)
		if(i!=rec)
			E.push_back(edge(rec,i,miv+a[i]));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		E.push_back(edge(u,v,w));
	}
	cout<<boruvka(n)<<endl;
//	sort(E.begin(),E.end(),[](const edge &x,const edge &y){
//			return x.w<y.w;
//		});//边按边权排序
//	sort(node.begin(),node.end());//点按点权排序
	ll ans=0;
	return 0;
}
/*
 *n个点,每个点有点权
*/

