//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
struct edge
{
	int v,w;
	edge(int v=0,int w=0):
		v(v),w(w){}
};
vector<edge>G[maxn];
int val[maxn];
void get(int x,int fa)
{
	for(auto &e:G[x])
	{
		if(e.v==fa)
			continue;
		val[e.v]=val[x]^e.w;
		get(e.v,x);
	}
}
const int M = 2;
int trie[maxn<<5][M],siz[maxn<<5],tot;
void Insert(const int key)//rt传入0
{//trie插入模式串
	int rt=0;
	for(int i=30;i>=0;i--)
	{
		int id = (key>>i)&1;
		if(!trie[rt][id])
		{
//			memset(trie[tot],0,sizeof(trie[tot]));
			trie[rt][id]=tot++;
		}
		rt = trie[rt][id];
	}
}
ll check(int x,int y,int w)//启发式,最多向下w次
{//在x子树和y子树上求得一个最小异或值
	ll ret=LLONG_MAX;
	if(trie[x][0]&&trie[y][0])//尽量先使高位相同
		ret=min(ret,check(trie[x][0],trie[y][0],w-1));
	if(trie[x][1]&&trie[y][1])
		ret=min(ret,check(trie[x][1],trie[y][1],w-1));
	if(ret==LLONG_MAX)
	{
		if(trie[x][0]&&trie[y][1])
			ret=min(ret,check(trie[x][0],trie[y][1],w-1))+(1<<w);
		if(trie[x][1]&&trie[y][0])
			ret=min(ret,check(trie[x][1],trie[y][0],w-1))+(1<<w);
		if(ret==LLONG_MAX)//说明两边没有节点
			ret=0;
	}
	return ret;
}
ll dfs(int x,int w)//节点x开始搜索
{//只有根节点x=0,从高位向下dfs
	if(w<0)
		return 0;
	if(trie[x][0]&&trie[x][1])//都存在,找最小边连接两个连通块
		return (1<<w)+check(trie[x][0],trie[x][1],w-1)+dfs(trie[x][0],w-1)+dfs(trie[x][1],w-1);
	else if(trie[x][0])//左面存在
		return dfs(trie[x][0],w-1);
	else//右面存在
		return dfs(trie[x][1],w-1);
}
ll solve(int n)
{
	get(0,0);
	sort(val+1,val+n+1);
	n=unique(val+1,val+n+1)-val-1;//去重是因为相同值异或为0,没必要再计算
	tot=1;
	for(int i=1;i<=n;i++)
		Insert(val[i]);
	return dfs(0,30);
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1,u,v,w;i<n;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	cout<<solve(n)<<endl;
	return 0;
}


