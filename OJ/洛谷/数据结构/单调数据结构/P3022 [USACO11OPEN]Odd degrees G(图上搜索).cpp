//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
//int a[maxn],b[maxn];
vector<pii>G[maxn];
vector<int>ans;
bool ok=1,vis[maxn];
bool dfs(int x,int edge)
{//每个点只会访问一次
	vis[x]=1;
	int deg=0;
	for(pii &i:G[x])
	{
		if(vis[i.ff])
			continue;
		if(dfs(i.ff,i.ss))
			deg++;
	}
	if(deg%2)
		return false;
	ans.push_back(edge);
	return true;//需要来的这条边
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(pii(v,i));
		G[v].push_back(pii(u,i));
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&dfs(i,i))
			return cout<<-1<<endl,0;
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int &i:ans)
		cout<<i<<endl;
	return 0;
}
/*
 *删掉一些边使得每个点度数都为奇数
 *n5e4,m1e5
 *枚举每个边,若l两个点都为偶数则删去
*/

