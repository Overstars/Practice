#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e4+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int c[maxn],d[maxn];//代价与收益
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
		fa[b]=a,c[a]+=c[b],d[a]+=d[b];
	else
		fa[a]=b,c[b]+=c[a],d[b]+=d[a];
	return 1;
}
bool vis[maxn];
int dp[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,w;
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i],fa[i]=i;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		Merge(u,v);
	}
	vector<pair<int,int> >vec;
	for(int i=1;i<=n;i++)
	{
		int now=findfa(i);
		if(vis[now])
			continue;
		vis[now]=1;
		vec.push_back(make_pair(c[now],d[now]));
	}
	int ans=0;
	for(auto &x:vec)
	{
		for(int j=w;j>=0;j--)
		{
			if(j-x.first>=0)
				dp[j]=max(dp[j],dp[j-x.first]+x.second);
		}
	}
	cout<<dp[w]<<endl;
	return 0;
}


