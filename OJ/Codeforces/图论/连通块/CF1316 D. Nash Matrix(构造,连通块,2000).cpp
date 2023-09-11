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
struct node
{
	int x,y;
	bool operator == (const node &b)const {
		return (x==b.x&&y==b.y);
	}
} g[maxn][maxn];
char ans[maxn][maxn];
bool vis[maxn][maxn],ok=1;
int nx[]={0,1,0,-1},ny[]={1,0,-1,0},n;
void bfs(int a,int b)
{
	queue<pii>QAQ;
	if(g[a][b].x>0)
	{
		QAQ.push(pii(a,b));
		ans[a][b]='X';
		vis[a][b]=1;
	}
	else{
		int flag=-1;
		for(int i=0;i<4;i++)
		{//R,D,U,L
			int xx=a+nx[i],yy=b+ny[i];
			if(xx<1||xx>n||yy<1||yy>n)
				continue;
			if(g[xx][yy].x==-1)
			{
				flag=i;
				if(i==0)
					ans[a][b]='R',ans[xx][yy]='L';
				else if(i==1)
					ans[a][b]='D',ans[xx][yy]='U';
				else if(i==2)
					ans[a][b]='L',ans[xx][yy]='R';
				else
					ans[a][b]='U',ans[xx][yy]='D';
				vis[a][b]=vis[xx][yy]=1;
				QAQ.push(pii(a,b));
				QAQ.push(pii(xx,yy));
				break;
			}
		}
		if(flag==-1)
			ok=0;
	}
	while(!QAQ.empty())
	{
		pii now=QAQ.front();
		QAQ.pop();
		for(int i=0;i<4;i++)
		{
			int xx=now.ff+nx[i],yy=now.ss+ny[i];
			if(xx<1||xx>n||yy<1||yy>n||vis[xx][yy])
				continue;
			if(g[xx][yy]==g[now.ff][now.ss])
			{
				if(i==0)
					ans[xx][yy]='L';
				else if(i==1)
					ans[xx][yy]='U';
				else if(i==2)
					ans[xx][yy]='R';
				else
					ans[xx][yy]='D';
				vis[xx][yy]=1;
				QAQ.push(pii(xx,yy));
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
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>g[i][j].x>>g[i][j].y;
	set<pii> rec;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vis[i][j]&&(g[i][j].x==-1||(g[i][j].x==i&&g[i][j].y==j)))
				bfs(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vis[i][j])
				ok=0;
	cout<<(ok?"VALID":"INVALID")<<endl;
	if(!ok)
		return 0;
	for(int i=1;i<=n;i++)
		cout<<ans[i]+1<<endl;
	return 0;
}
/*
 *当一个格子为-1时,必然处于一个循环中
 *最简情况:LR,使其他-1指向这里即可
 *当目标t存在时时,必然和t有一条路径连接,且路径上全为t(包含t的全为t的连通块)
 *t一定为X
*/

