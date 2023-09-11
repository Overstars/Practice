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
vector<int>G[maxn];
int a[maxn],ans[maxn];
map<int,bool>vis[maxn][2];//vis[x][1][now]表示x点被删除=now的值已经被访问过
//void dfs(int x,int fa,int g,int gg)
//{//g未删过节点的,gg已删过节点的最大值
//	ans[x]=max(g,__gcd(gg,a[x]));
//	int ng=__gcd(g,a[x]);
//	for(int &v:G[x])
//	{
//		if(v==fa)
//			continue;
//		dfs(v,x,ng,max({g,ans[x]}));
//	}
//}
void dfs(int x,int fa,bool op,int pre)//1表示之前进行过删除操作
{
	if(vis[x][op][pre])
		return;
	vis[x][op][pre]=1;
	int now=__gcd(a[x],pre);
	ans[x]=max(ans[x],now);
	if(!op)//
		ans[x]=max(ans[x],pre);
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x,op,now);
		if(!op)//现在开始删掉x
			dfs(v,x,1,pre);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans[1]=a[1];
	for(int &v:G[1])
	{
		dfs(v,1,0,a[1]);
		dfs(v,1,1,a[v]);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
5
1 2 6 3 4
1 2
2 3
1 4
4 5
ans=1,2,2,3,1
3
2 3 4
1 2
2 3
ans=2,3,2
*/
