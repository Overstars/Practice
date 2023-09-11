//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
vector<int>G[maxn];
int dist[maxn],root=0;
int bfs(int st,int n)
{
	vector<bool>vis(n+1,false);
	dist[st]=root=0;
	queue<int>q;
	q.push(st);
	int rec=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
//		printf("dist[%d]=%d\n",x,dist[x]);
		for(int &v:G[x])
		{
			if(vis[v])
				continue;
			dist[v]=dist[x]+1;
			if(dist[v]>dist[root])
				root=v,rec=dist[v];
			q.push(v);
		}
	}
	return rec;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,a,b,da,db,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>da>>db;
		bool ok=1;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(a,n);
		if(dist[b]<=da)//一步抓到
			ok=0;
		int r=bfs(root,n);
		if(r<2*da+1||db<2*da+1)
			ok=0;
		cout<<(ok?"Bob":"Alice")<<endl;
	}
	return 0;
}


