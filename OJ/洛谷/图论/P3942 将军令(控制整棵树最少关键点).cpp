//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
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
vector<int>G[maxn];
int dep[maxn],f[maxn];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=fa;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
	}
}
int get(int x,int k)
{
	int stp=1;
	while(stp++<=k)
		x=f[x];
	return (x==0)?1:x;
}
int k;
void dfs2(vector<bool> &vis,int x,int fa,int dep)
{
	vis[x]=1;
	if(dep==k)
		return;
	for(int &v:G[x])
		if(v!=fa)
			dfs2(vis,v,x,dep+1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,t,u,v;//t无用
	cin>>n>>k>>t;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,1);
	int ans=0;
	vector<bool>vis(n+1,false);
//	std::function<void(int)>dfs2 = [&](int x,int fa,int dep){
//		if(dep==k)
//			return;
//		vis[x]=1;
//		for(int &v:G[x])
//			if(v!=fa)
//				dfs2(v,x,dep+1);
//		return;
//	}
	vector<int> vec(n);
	iota(vec.begin(),vec.end(),1);
	sort(vec.begin(),vec.end(),[](const int &x,const int &y){
			return dep[x]>dep[y];
		});//优先取深度大的
	for(int &x:vec)
	{
		if(vis[x])
			continue;
//		cerr<<"x = "<<x<<endl;
		ans++;
		int g=get(x,k);
//		cerr<<"g = "<<g<<endl;
		dfs2(vis,g,g,0);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *n个节点的树,选出最少的关键节点,控制整棵树
 *每个关键节点控制范围为k
*/

