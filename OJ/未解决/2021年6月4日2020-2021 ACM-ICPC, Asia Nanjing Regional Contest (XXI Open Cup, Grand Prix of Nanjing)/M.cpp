//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e3+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll dp[maxn][maxn][2],hp[maxn];
void dfs(int x,int fa)
{//dp[x][k][0]表示x怪兽死亡,且子树上有k个怪兽死亡的最小花费
	for(auto &v:G[x])
	{
		dfs(v,x);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=2;i<=n;i++)
		{
			cin>>u;
			G[u].push_back(i);
		}
		for(int i=1;i<=n;i++)
			cin>>hp[i];
		dfs(1,1);
		for(int i=n;i>=0;i--)//存活i个
			cout<<min(dp[1][i][0],dp[1][i][1])<<(i==0?'\n':' ');
	}
	return 0;
}
/*
 * 2021-06-04-16.37.42
 * C:\Users\dell\Desktop\2021年6月4日2020-2021 ACM-ICPC, Asia Nanjing Regional Contest (XXI Open Cup, Grand Prix of Nanjing)\M.cpp
 *
*/

