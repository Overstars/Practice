//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define show(x) std:: cerr << #x << " = " << x << std::endl;
#define ff first
#define ss second
const int maxn=1e3+10,inf=0x3f3f3f3f,mod=1000000007;
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
int h[maxn][maxn],nx[]={0,1,0,-1},ny[]={1,0,-1,0};
bool bfs(int x,int y,ll val,int n)
{//到达(x,y)的路径上最大最小边权
	vector<vector<bool>>vis(n+1,vector<bool>(n+1,0));
	if(h[x][y]<val)
		return 0;
	queue<pii>QAQ;
	QAQ.push(pii(x,y));
	while(!QAQ.empty())
	{
		pii now=QAQ.front();
		QAQ.pop();
		if(vis[now.ff][now.ss])
			continue;
		vis[now.ff][now.ss]=1;
		if(now.ff==n&&now.ss==n)
			return 1;
		for(int i=0;i<4;i++)
		{
			int xx=now.ff+nx[i];
			int yy=now.ss+ny[i];
			if(xx<1||xx>n||yy<x||yy>n)
				continue;
			if(h[xx][yy]<val)
				continue;
			QAQ.push(pii(xx,yy));
		}
	}
	return 0;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,x;
	scanf("%d",&n);
//	cin>>n;
//	for(int i=1;i<=n*n;i++)
//		fa[i]=i;
//	auto id(int x,int y){return x*(n-1)+y};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&h[i][j]);
	ll ans=0,l=1,r=100000;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		show(mid);
		if(bfs(1,1,mid,n))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	show(ans);
//	dfs(1,1,inf);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		printf("%s\n",(x<=ans?"Wuhu":"Hmmm"));
	}
	return 0;
}


