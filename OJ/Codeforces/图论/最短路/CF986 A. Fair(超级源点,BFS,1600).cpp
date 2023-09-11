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
vector<int>e[maxn],st[maxn];
int dist[maxn][100],col[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,s,u,v;
	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
		st[col[i]].push_back(i);
	}
	memset(dist,inf,sizeof(dist));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	queue<int>q;
	for(int i=1;i<=k;i++)
	{//将所有颜色i作为起点BFS
		for(auto &x:st[i])
		{
			q.push(x);
			dist[x][i]=0;
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto &v:e[u])
			{
				if(dist[v][i]<=dist[u][i]+1)
					continue;
				dist[v][i]=dist[u][i]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(dist[i]+1,dist[i]+k+1);
		int ans=0;
		for(int j=1;j<=s;j++)
			ans+=dist[i][j];
		cout<<ans<<' ';
	}
	return 0;
}


