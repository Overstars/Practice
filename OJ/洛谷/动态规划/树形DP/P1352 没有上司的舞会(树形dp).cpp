//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int dp[maxn][2],r[maxn];//快乐指数
vector<int>G[maxn];
void dfs(int x)
{
	dp[x][0]=0;//不来
	dp[x][1]=r[x];//x来
	for(int &v:G[x])
	{
		dfs(v);
		dp[x][0]+=max(dp[v][0],dp[v][1]);
		dp[x][1]=max(dp[x][1],dp[x][1]+dp[v][0]);
	}
}
bool vis[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1,l,k;i<n;i++)
	{
		cin>>l>>k;
		G[k].push_back(l);
		vis[l]=1;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			root=i;
			break;
		}
	dfs(root);
	cout<<max(dp[root][0],dp[root][1])<<endl;
	return 0;
}


