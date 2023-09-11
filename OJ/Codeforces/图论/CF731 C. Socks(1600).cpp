#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
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
int col[maxn],siz[maxn],maxc=0;
bool vis[maxn];
vector<int>e[maxn];
int dfs(int x,int fa)
{
	siz[col[x]]=0;
	vis[x]=0;
	int now=1;
	for(auto &v:e[x])
	{
		if(!vis[v])
			continue;
		now+=dfs(v,x);
	}
	siz[col[x]]++;
	if(siz[col[x]]>siz[maxc])
		maxc=col[x];
	return now;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,m,l,r;//n只,m天,k种
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		if(!Merge(l,r))//已在一棵树上
			continue;
		e[l].push_back(r);
		e[r].push_back(l);
		vis[l]=vis[r]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
		{
			maxc=0;
			ans+=dfs(i,0)-siz[maxc];
		}
	cout<<ans<<endl;
	return 0;
}
/*
6 4 5
1 2 2 3 4 5
1 2
2 6
3 4
2 1
ans=3;
10 7 2
1 2 1 1 2 2 2 1 2 1
1 2
2 1
2 3
3 2
4 5
5 4
1 3

*/

