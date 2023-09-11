//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
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
char s[maxn][maxn];
int dis[4][maxn][maxn],n,m;
int nx[]={0,1,0,-1},ny[]={1,0,-1,0};
bool vis[4][maxn][maxn];
void bfs(queue<pii>&q,int d[][maxn],bool v[][maxn])
{
	while(!q.empty())
	{
		int x=q.front().ff,y=q.front().ss,xx,yy;
//		printf("[%d,%d]=%d\n",x,y,d[x][y]);
		q.pop();
		for(int k=0;k<4;k++)
		{
			xx=x+nx[k],yy=y+ny[k];
			if(v[xx][yy]||s[xx][yy]=='#'||xx<1||xx>n||yy<1||yy>m)
				continue;
			int dd=(s[x][y]==s[xx][yy]&&isdigit(s[xx][yy]))?0:1;
			if(d[x][y]+dd<d[xx][yy])//增长并不等量
			{
				d[xx][yy]=d[x][y]+dd;
				q.push(pii(xx,yy));
			}
		}
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(dis,inf,sizeof(dis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	for(int a=1;a<=3;a++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='0'+a)
				{
					dis[a][i][j]=0;
					vis[a][i][j]=1;
				}
	}
	queue<pii>q[4];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]-'0'>=1&&s[i][j]-'0'<=3)
			{
				int xx,yy,ok=0;
				for(int k=0;k<4;k++)
				{
					xx=i+nx[k],yy=j+ny[k];
					if(xx<1||xx>n||yy<1||yy>m)
						continue;
					if(s[xx][yy]!=s[i][j])
						ok=s[i][j]-'0';
				}
				if(ok)
					q[ok].push(pii(i,j));
			}
	bfs(q[1],dis[1],vis[1]);
	bfs(q[2],dis[2],vis[2]);
	bfs(q[3],dis[3],vis[3]);
	ll ans=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ans=min(ans,1ll*dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-2);
//			ans=min({ans,1ll*dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-(s[i][j]=='.'?2:0)});
//			printf("[%d,%d]:%lld\n",i,j,1ll*dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-(s[i][j]=='.'?2:0));
//			printf("%d+%d+%d\n",dis[1][i][j],dis[2][i][j],dis[3][i][j]);
		}
	cout<<(ans<inf-2?ans:-1ll)<<endl;
	return 0;
}
/*
5 5
.2...
#2.3.
.#..#
.#.11
#..#.
ans=2

6 5
.333.
#3.2#
#3..#
..#.#
#.#..
.1..#
ans=2
*/
/*
 *应该是将所有边缘节点加进队列里
 *记录三次bfs搜索到的最小的两个值,不存在就为-1
 *好吧我没考虑完整...
 *两个国家相邻时距离不增加
 *枚举的时候有可能一个国家通过另一个国家,此时被经过的国家无贡献
 *这个情况会在枚举被通过国家为中间点时包含
*/

