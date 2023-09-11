//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
const int maxn=25,inf=0x3f3f3f3f,mod=1000000007;
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
map<ll,ll>mp[maxn][maxn];
int n,m,k;
ll ans=0,lim,a[maxn][maxn];
void dfs(int x,int y,ll val)
{
	if(x<1||x>n||y<1||y>m)
		return;
	val^=a[x][y];
	if(x+y==lim)
	{
		mp[x][y][val]++;
		return;
	}
	dfs(x+1,y,val);
	dfs(x,y+1,val);
}
void dfs2(int x,int y,ll val)
{
	if(x<1||x>n||y<1||y>m)
		return;
	if(x+y==lim)
	{
		ans+=mp[x][y][k^val];
		return;
	}
	val^=a[x][y];
	dfs2(x-1,y,val);
	dfs2(x,y-1,val);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m>>k;//(1,1)->(n,m)异或值=k的数量
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	lim=(n+m)/2+1;
	dfs(1,1,0);
	dfs2(n,m,0);
	cout<<ans<<endl;
	return 0;
}
/*
1 1 1
1
*/

