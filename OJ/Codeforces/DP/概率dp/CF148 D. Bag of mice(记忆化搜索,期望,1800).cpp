//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
double dp[maxn][maxn];
bool vis[maxn][maxn];
double dfs(int x,int y)
{
	if(x>0&&y==0)//A赢
		return 1;
	else if(x<=0)//B赢
		return 0;
	if(vis[x][y])
		return dp[x][y];
	vis[x][y]=1;
	dp[x][y]+=(double)x/(x+y);//A赢
	if(y>=3)
	{
		dp[x][y]+=(double)y*(y-1)/(x+y)/(x+y-1)*(x)/(x+y-2)*dfs(x-1,y-2);//A抓了黑的,B抓了黑的,丢了白的
		dp[x][y]+=(double)y*(y-1)/(x+y)/(x+y-1)*(y-2)/(x+y-2)*dfs(x,y-3);//丢了黑的
	}
	else if(y==2)
	{
		dp[x][y]+=(double)y*(y-1)/(x+y)/(x+y-1)*dfs(x-1,y-2);//丢白的
	}
//	printf("dp[%d,%d] = %.3f\n",x,y,dp[x][y]);
	return dp[x][y];
	/*
	 * A摸到了白的,直接赢,x/(x+y)
	 * A摸到了黑的,B摸到白的,直接输,y*x/(x+y)/(x+y-1)
	 * A摸到黑的,B摸到黑的,丢了白的,y*(y-1)/(x+y)/(x+y-1)* x/(x+y-2)
	 * A摸到黑的,B摸到黑的,丢了黑的,y*(y-1)/(x+y)/(x+y-1)* (y-2)/(x+y-2)
	 * 哦注意每只耗子跑掉的概率均等
	*/
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int w,b;
	cin>>w>>b;
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<dfs(w,b)<<endl;
	return 0;
}
/*
 * 2021-05-05-17.27.17
*/

