//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int dp[maxn];
ll a[maxn],sum[maxn],ans=0;
vector<int>G[maxn];
int dfs(int x)
{
	if(G[x].empty())
	{
		ans=max(ans,a[x]);
		sum[x]=a[x];
		return 1;
	}
	int cnt=0;
	sum[x]=a[x];
	for(int &v:G[x])
	{
		cnt+=dfs(v);
		sum[x]+=sum[v];
	}
	ans=max(ans,sum[x]/cnt+(sum[x]%cnt?1:0));
	return cnt;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>u;
		G[u].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
 *将一个树节点权值分配给子节点
 *使叶子节点最大值最小
 *求这个值
*/

