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
bool vis[maxn];
int val[maxn];
vector<edge>E;
ll kruskal(int n)
{
	sort(E.begin(),E.end(),[](const edge &a,const edge &b){
			return a.w>b.w;
		});
	ll ret=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(edge &e:E)
	{
		if(Merge(e.u,e.v))
		{
			ret+=e.w;
			n--;
			if(n==1)
				return ret;
		}
	}
	return 0;
}
vector<int>G[maxn];
ll bfs(int x)
{
	queue<int>q;
	vector<int>rec;
	q.push(x);
	vis[x]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		rec.push_back(x);
		for(int &v:G[x])
		{
			if(!vis[v])
			{
				q.push(v);
				vis[v]=1;
			}
		}
	}
	E.clear();
	for(int &u:rec)
		for(int &v:G[u])
			E.push_back({u,v,min(val[u],val[v])});
	return kruskal(rec.size());
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll tot=0;
		for(int i=1;i<=n;i++)
		{
			cin>>val[i];
			tot+=val[i];
			vis[i]=0;
			G[i].clear();
		}
		for(int i=1,u,v;i<=m;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
				tot-=bfs(i);
		cout<<tot<<endl;
	}
	return 0;
}


