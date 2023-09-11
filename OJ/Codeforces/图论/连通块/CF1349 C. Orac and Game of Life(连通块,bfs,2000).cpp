//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
#define ff first
#define ss second
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int n,m,nx[]={0,1,0,-1},ny[]={1,0,-1,0};
bool s[maxn][maxn],vis[maxn][maxn],ok=0;
ll tim[maxn][maxn];//记录开始变化时间点
void bfs()
{
	queue<pii>QAQ;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++)
			{
				int xx=i+nx[k],yy=j+ny[k];
				if(xx<1||xx>n||yy<1||yy>m)
					continue;
				if(s[xx][yy]==s[i][j])
				{
					vis[i][j]=ok=1;
					tim[i][j]=1;
					QAQ.push(pii(i,j));
					break;
				}
			}
		}
	while(!QAQ.empty())
	{
		pii now=QAQ.front();
		QAQ.pop();
		int x=now.ff,y=now.ss;
		for(int k=0;k<4;k++)
		{
			int xx=x+nx[k],yy=y+ny[k];
			if(vis[xx][yy]||xx<1||xx>n||yy<1||yy>m)
				continue;
			vis[xx][yy]=1;//在这里标记...
			if(s[xx][yy]!=s[x][y])
				tim[xx][yy]=tim[x][y]+1;
			else
				tim[xx][yy]=tim[x][y];
			QAQ.push(pii(xx,yy));
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
	int t,x,y;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		string ss;
		cin>>ss;
		for(int j=0;j<m;j++)
			s[i][j+1]=(ss[j]=='1')?true:false;
	}
	bfs();
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			printf("%5lld%c",tim[i][j],(j==m)?'\n':' ');
	while(t--)
	{
		ll p;
		cin>>x>>y>>p;
		if(ok&&p>=tim[x][y])
			cout<<((p-tim[x][y])%2?s[x][y]:!s[x][y])<<endl;
		else
			cout<<s[x][y]<<endl;
	}
	return 0;
}
/*
10 10 4
0101011101
1010101010
0101010101
1010101010
1111010101
1000101011
1111011000
1000101110
0001100011
1000100110
10 8 14
1 4 11
7 4 16
2 6 383713659368449448
ans=1,0,1,1
*/
/*
 *相邻相同颜色为一个连通块
 *若所有连通块大小为1则不变,只有这一种情况才永远不变
 *所有连通块大小大于1也反复横跳
 *有1且有一个大于1的则会不断合并,最终变为相同颜色且反复横跳
*/

