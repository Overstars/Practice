//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
int n,depth[maxn],f[maxn],son[maxn],siz[maxn];
vector<int>G[maxn];
void dfs(int x,int fa)
{
//	f[x]=fa;
	depth[x]=depth[fa]+1;
	siz[x]=1;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
			son[x]=v;
	}
}
int maxd=0,mink=0,flag,rec[maxn],ans[maxn];//rec[x]=y,深度为x的数目为y
void calc(int x,int fa)
{
	rec[depth[x]]++;
	maxd=max(maxd,depth[x]);
	if(rec[depth[x]]>rec[mink])
		mink=depth[x];
	else if(rec[depth[x]]==rec[mink])
		mink=min(mink,depth[x]);
	for(int &v:G[x])
	{
		if(v==fa||v==flag)
			continue;
		calc(v,x);
	}
}
void dfs(int x,int fa,bool keep)
{
	for(int &v:G[x])
	{
		if(v==fa||v==son[x])
			continue;
		dfs(v,x,0);
	}
	if(son[x])
		dfs(son[x],x,1);
	flag=son[x];
	calc(x,fa);
	flag=0;
//	fprintf(stderr,"now = %d\n",x);
//	for(int i=0;i<=maxd;i++)
//		fprintf(stderr,"rec[%d]=%d\n",i,rec[i]);
	ans[x]=mink-depth[x];//数量最大的最小深度
	if(!keep)
	{
		for(int i=0;i<=maxd;i++)
			rec[i]=0;
		maxd=mink=0;
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
/*
 * 2021-04-14-19.18.59
*/

