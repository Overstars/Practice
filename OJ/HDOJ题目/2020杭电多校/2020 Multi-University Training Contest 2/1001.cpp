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
struct node
{
	int w,id;
	bool operator < (node b)const
	{return w>b.w;}
} p[maxn];
vector<int>G[maxn];
int vis[maxn],fa[maxn],mn[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n,m;
	cin>>T;
	while(T--)
	{
		ll ans=0;
		cin>>n>>m;
		for(int i=1,w;i<=n;i++)
		{
			cin>>w;
			p[i].w=w;
			p[i].id=i;
			G[i].clear();
		}
		sort(p+1,p+n+1);//按权值排序
		for(int i=1,u,v;i<=m;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			vis[i]=0,fa[i]=i,mn[p[i].id]=p[i].w;
		for(int i=1;i<=n;i++)
		{
			vis[p[i].id]=1;//已访问
			for(int j=0;j<G[p[i].id].size();j++)
			{
				int v=G[p[i].id][j];
				if(vis[v])//之前访问过v
				{
					int tx=findfa(p[i].id),ty=findfa(v);
					if(tx==ty)//在同一个连通块内
						continue;
					fa[tx]=ty;
					ans+=mn[ty]-mn[tx];
					mn[ty]=min(mn[ty],mn[tx]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(fa[i]==i)
				ans+=mn[i];
		printf("%lld\n",ans);
	}
	return 0;
}


