#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
struct edge
{
	int u,v;
	edge(int u,int v):
		u(u),v(v){}
};
ll siz[maxn];
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	vector<edge> es;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		es.push_back(edge(u,v));
	}
	dfs(1,0);
	vector<ll> vec;
	for(auto &e:es)
	{
		ll now=min(siz[e.u],siz[e.v]);
		vec.push_back(now*(n-now));
	}
	sort(vec.begin(),vec.end());
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{//n-1个,从小到大
		ans+=vec[i]*(n-i-1);
	}
	cout<<ans<<endl;
	return 0;
}


