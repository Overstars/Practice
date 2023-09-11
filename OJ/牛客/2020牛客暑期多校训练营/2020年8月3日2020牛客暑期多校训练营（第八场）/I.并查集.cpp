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
//void print(__int128 x){
//    if(x < 0){putchar('-');x=-x;}
//    if(x > 9)print(x/10);
//    putchar(x%10+'0');
//}
int fa[maxn],siz[maxn];
bool vis[maxn],cir[maxn];
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
	{
		fa[b]=a;
		siz[a]+=siz[b];
		cir[a]|=cir[b];
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
		cir[b]|=cir[a];
	}
	return 1;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n;
	scanf("%lld",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%lld",&n);
		for(int i=1;i<=2*n;i++)
		{
			fa[i]=i,siz[i]=1;
			cir[i]=vis[i]=0;
		}
		map<int,int>mp;
		int cnt=0;
		for(int i=1,u,v;i<=n;i++)
		{
			scanf("%lld%lld",&u,&v);
			if(mp[u]==0)
				mp[u]=++cnt;
			if(mp[v]==0)
				mp[v]=++cnt;
			u=mp[u],v=mp[v];
			if(!Merge(u,v))
				cir[findfa(u)]=1;
		}
		ll ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int u=findfa(i);
			if(vis[u])
				continue;
			ans+=siz[u];
			if(!cir[u]&&siz[u]>1)
				ans--;
			vis[u]=1;
		}
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}


