//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
vector<pii>rec;
struct edge
{
	int v,nex;
} e[maxn<<1];
int cnt=0,head[maxn],d[maxn];
bool vis[maxn];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
vector<int>ans;
bool dfs(int x)
{
	vis[x]=1;
	bool take=d[x];//
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(!vis[v]&&dfs(v))//子节点每添加一个边,奇偶性改变
		{
			printf("%d->%d,%d\n",x,v,(i+1)/2);
			ans.push_back((i+1)/2);
			take^=1;
		}
	}
	if(d[x]==-1)
		take=0;
	return take;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(head,-1,sizeof(head));
	int n,m,u,v,c1=0,root=0;//任选一个起点
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(d[i]==1)
			c1++;
		else if(d[i]==-1)
			root=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
		rec.push_back(pii(u,v));
	}
	if(!root&&c1&1)
		return cout<<-1<<endl,0;
	dfs(1);
//	dfs(max(root,1));
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int &x:ans)
		cout<<x<<endl;
	return 0;
}
/*
 *给定每个点的度数的奇偶性,和一个边集
 *选择一些边,确定一个可以有重边的图
 *图上奇数点的个数一定为偶数,除此之外是必定有解的
 *突破点是转化为树上问题...每个点只有一个父亲,根节点无父亲
 *那么我们可以选择x与父亲的边是否选取来达到控制0/1
 *若奇数点为奇数个,那我们使一个-1点作为根节点,其他-1都变为偶数点来简化代码
*/
/*
3 3
0 1 1
1 2
2 3
1 3
*/
