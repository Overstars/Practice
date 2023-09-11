//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=3010,inf=0x3f3f3f3f,mod=1000000007;
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
void bfs(int d[],int st,int n)
{
	vector<bool>vis(n+1,0);
	queue<int>q;
	for(int i=1;i<=n;i++)
		d[i]=inf;
	d[st]=0;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(int &v:G[x])
			if(!vis[v]&&d[v]>d[x]+1)
			{
				d[v]=d[x]+1;
				q.push(v);
			}
	}
}
int dis[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,s1,t1,l1,s2,t2,l2;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	for(int i=1;i<=n;i++)
		bfs(dis[i],i,n);
	int ans=inf;
	if(dis[s1][t1]<=l1&&dis[s2][t2]<=l2)
		ans=dis[s1][t1]+dis[s2][t2];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
//			printf("%d->%d=%d\n",i,j,dis[i][j]);
			int len=dis[i][j];
			int d1=min(dis[s1][i]+dis[j][t1],dis[s1][j]+dis[i][t1]);
			int d2=min(dis[s2][i]+dis[j][t2],dis[s2][j]+dis[i][t2]);
			if(d1+len<=l1&&d2+len<=l2)
				ans=min(ans,len+d1+d2);
//			printf("%d->%d,d=%d,%d\n",i,j,len+d1,len+d2);
		}
	if(ans>=inf)
		cout<<-1<<endl;
	else
		cout<<m-ans<<endl;
	return 0;
}
/*
 *因为边权都为1
 *n次bfs即可得到每两点之间最短路
 *两条路线最多只会有一段相同
 *枚举相交起点和终点即可
*/

