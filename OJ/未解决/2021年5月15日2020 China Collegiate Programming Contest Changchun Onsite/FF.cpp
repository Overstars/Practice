//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn],siz[maxn],son[maxn],flag;
vector<int>G[maxn];
ll ans=0;
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
			son[x]=v;
	}
}
int st[20][2][1<<20],tmp[2][1<<20];
//set<int> vis0,vis1;//st[x]表示此时权值为x该位为的数量
//set<int> rec0,rec1;
vector<int> vis0,vis1,vis;
//vector<int> rec0,rec1;
void update(int x,int val)
{
	for(int k=0;k<20;k++)
		st[k][1&(x>>k)][a[x]]+=val;
}
void cal(int x,int fa,int top)
{
	vis.push_back(x);
	for(int k=0;k<20;k++)
	{
		if(x&(1ll<<k))
		{
			ans+=(1ll<<k)*(st[k][0][a[x]^a[top]]);
//			rec1.push_back(a[x]);
		}
		else{
			ans+=(1ll<<k)*(st[k][1][a[x]^a[top]]);
//			rec0.push_back(a[x]);
		}
	}
	for(auto &v:G[x])
		if(v!=fa)
			cal(v,x,top);
}
void del(int x,int fa)
{
	update(x,-1);
	for(auto &v:G[x])
		if(v!=fa)
			del(v,x);
}
void dfs(int x,int fa,bool keep)
{
	for(auto &v:G[x])
	{
		if(v==fa||v==son[x])
			continue;
		dfs(v,x,0);
	}
	if(son[x])
	{
		dfs(son[x],x,1);
		flag=son[x];
	}
	update(x,1);
	for(auto &v:G[x])
	{
		if(v==fa||v==son[x])
			continue;
		cal(v,x,x);
		for(auto &i:vis)
			update(i,1);
		vis.clear();
	}
//	printf("node[%d] = %lld\n",x,ans);
	if(!keep)
	{
		del(x,fa);
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
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	for(int i=1;i<n;i++)
	{
		read(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
//	for(int i=0;i<20;i++)
	{
		dfs(1,0,0);
	}
	printf("%lld\n",ans);
//	cout<<ans<<endl;
	return 0;
}
/*
9
0 1 1 1 1 1 1 1 1
1 2
2 3
2 4
2 5
1 6
6 7
6 8
6 9
ans=120

10
6 9 2 5 7 5 7 7 6 2
2 8
7 9
7 2
8 4
6 8
5 3
9 10
8 1
8 3

*/
/*
 * 2021-05-15-15.33.49
*/


