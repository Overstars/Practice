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
struct edge
{
	int u,v,w,id,nex;
	edge(int u=0,int v=0,int w=0,int id=0,int nex=0):
		u(u),v(v),w(w),id(id),nex(nex){}
} e[maxn<<1];
int head[maxn],cnt=0;
void add(int u,int v,int w=0)
{
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int siz[maxn],dp[maxn],dep[maxn];
void dfs(int x,int fa)
{
	siz[x]=1;
	dep[x]=dep[fa]+1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		if(e[i].v==fa)
			continue;
		dfs(e[i].v,x);
		siz[x]+=siz[e[i].v];
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,u,v,w;
	cin>>t;
	while(t--)
	{
		memset(head,-1,sizeof(head));
		cnt=0;
		cin>>n;
		int ans=0;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}//n为偶数
		dfs(1,0);
		for(int i=1;i<=2*(n-1);i+=2)
		{
			int l=siz[e[i].u],r=n-siz[e[i].u];
			u=e[i].u,v=e[i].v;
			if(dep[v]>dep[u])
				l=siz[v],r=n-siz[v];
//			printf("l=%d,r=%d\n",l,r);
			if((l*r)&1)
				ans^=e[i].w;
		}
		cout<<ans<<endl;
	}
	return 0;
}


