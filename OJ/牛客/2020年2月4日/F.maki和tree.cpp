#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
int col[maxn],fa[maxn],siz[maxn];
vector<int> G[maxn];
bool vis[maxn];
int findfa(int x)
{
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
	{
		fa[b]=a;
		siz[a]+=siz[b];
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
	}
	return 1;
}
int getsiz(int x,int fa,int top,int tim)
{
	if(vis[findfa(top)])
		return siz[findfa(top)];
	for(auto v:G[x])
	{
		if(col[v]||v==fa)
			continue;
		getsiz(v,x,top,tim+1);
		Merge(v,top);
	}
	if(tim==1)
		vis[findfa(top)]=1;
	return siz[findfa(top)];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B')
			col[i+1]=1;
		fa[i+1]=i+1;
		siz[i+1]=1;
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!col[i])
			continue;
		ll now=0;
		for(auto v:G[i])
		{
			if(col[v])
				continue;
			ll num=getsiz(v,i,v,1);
			ans+=now*num;
			now+=num;
		}
		ans+=now;
	}
	cout<<ans<<endl;
	return 0;
}

