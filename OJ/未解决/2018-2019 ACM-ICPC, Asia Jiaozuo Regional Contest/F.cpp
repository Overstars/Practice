//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=7030,inf=0x3f3f3f3f,mod=1000000007;
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
int n,m;
char s[maxn][maxn];
vector<int>G[maxn*maxn];
int dist[maxn*maxn];
bool vis[maxn*maxn];
int bfs(int S,int T)
{
	int ans=inf;
	queue<int>q;
	q.push(S);
	for(int i=1;i<=n*m;++i)
		vis[i]=0,dist[i]=inf;
	vis[S]=1;
	dist[S]=1;
	while(!q.empty())
	{
		int x=q.front();
//		printf("d->%d\n",x);
		q.pop();
		for(int &v:G[x])
		{
			if(vis[v])
				continue;
			vis[v]=1;
			dist[v]=dist[x]+1;
			q.push(v);
		}
	}
	return dist[T];
}
bool ld(int x,int y)
{
	return s[x+3][y-1]==' ';
}
bool down(int x,int y)
{
	return s[x+4][y+2]==' ';
}
bool rd(int x,int y)
{
	return s[x+3][y+5]==' ';
}
int id(int x,int y)
{//第x行y列
	return (x-1)*m+y;
}
int build(int n,int m)
{
	int st=0,ed=0;
	for(int i=1;i<=n;i++)
	{
		int px=1+(i-1)*4,py=3;//now的坐标
		for(int j=1;j<=m;j++)
		{
//			fprintf(stderr,"[%d,%d]=%d\n",px,py,id(i,j));
//			fprintf(stderr,"s[%d,%d]=%c\n",px,py,s[px][py]);
			int now=id(i,j);
			if(j>1&&ld(px,py))
			{//
				int nex;
				if(j&1)
				{
					G[now].push_back(id(i,j-1));
					G[id(i,j-1)].push_back(now);
					nex=id(i,j-1);
				}
				else{//下一行
					G[now].push_back(id(i+1,j-1));
					G[id(i+1,j-1)].push_back(now);
					nex=id(i+1,j-1);
				}
//				printf("ld:%d->%d\n",now,nex);
			}
			if(j<m&&rd(px,py))
			{//
				int nex;
				if(j&1)
				{
					G[now].push_back(id(i,j+1));
					G[id(i,j+1)].push_back(now);
					nex=id(i,j+1);
				}
				else{//下一行
					G[now].push_back(id(i+1,j+1));
					G[id(i+1,j+1)].push_back(now);
					nex=id(i+1,j+1);
				}
//				printf("ld:%d->%d\n",now,nex);
			}
			if(i<n&&down(px,py))
			{//↓
//				printf("down:%d->%d\n",now,id(i+1,j));
				G[now].push_back(id(i+1,j));
				G[id(i+1,j)].push_back(now);
			}
			if(s[px+2][py+2]=='S')
				st=now;
			if(s[px+2][py+2]=='T')
				ed=now;
			if(j&1)//下一个
				px+=2;
			else
				px-=2;
			py+=6;
		}
	}
//	fprintf(stderr,"st=%d -> ed=%d\n",st,ed);
	return bfs(st,ed);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,S,T;
//	scanf("%[^B]",s[1]+1);
//	char op;
//	scanf("%c",&op);
//	printf("\n%c\n",op);
	scanf("%d",&t);
//	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
//		cin>>n>>m;
		int lim=3+4*n;
//		getchar();
		for(int i=1;i<=lim;i++)
		{
			getchar();
			scanf("%[^\n]",s[i]+1);
		}
//		cin.getline(s[i]+1,maxn);
		for(int i=1;i<=n*m;i++)
			G[i].clear();
		int ans=build(n,m);
		printf("%d\n",(ans==inf?-1:ans));
//		cout<<(ans==inf?-1:ans)<<endl;
	}
//	system("pause");
	return 0;
}
/*
 * 2021-04-17-15.48.54
*/

