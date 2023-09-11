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
vector<int>G[maxn];
bool connected[maxn],vis[maxn];
int ans=0;
void dfs(int x,int fa,bool flag,int ret)
{
	int cnt=0;
	int sta=-1;//0没有儿子,1有>=2个儿子,2有1个儿子
	if(!flag&&ret<=1)
	{
		if(G[x].size()-1>=2)//多个儿子
			flag=1,sta=1;
		else if(G[x].size()==1)//没有儿子
			flag=1,sta==3;
		else if(G[x].size()==2)//1个儿子
			sta=2;
	}
	if(ret>0&&G[x].size()==1)
		flag=0;
	else if(ret==0)
		flag=1;
	if(flag)
		ans++;
//	printf("%d->%d\n",fa,x);
//	printf("%d=%d,dep=%d\n",x,flag,ret);
	for(int &v:G[x])
		if(v!=fa)
		{
			if(sta==1)//多个儿子,选中x点
				dfs(v,x,0,max(1,ret-1));
			else if(sta==2)//选中儿子不选该点
				dfs(v,x,1,ret-1);
			else
				dfs(v,x,0,ret-1);
		}
}
int depth[maxn],f[maxn];
void dfs(int x,int fa)
{
	f[x]=fa;
	depth[x]=depth[fa]+1;
	for(int &v:G[x])
		if(v!=fa)
			dfs(v,x);
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
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	priority_queue<pii> pq;
	for(int i=1;i<=n;i++)
		if(depth[i]>3)
			pq.push(pii(depth[i],i));
	while(!pq.empty())
	{
		pii now=pq.top();
		pq.pop();
		int x=now.ss;
		if(vis[x])//符合要求了
			continue;
		x=f[x];//标记最远节点的父亲
		vis[x]=1;
		for(int &v:G[x])
			vis[v]=1;
		ans++;
	}
//	dfs(1,1,0,3);
	cout<<ans<<endl;
	return 0;
}
/*
 *尝试将深度>=3的节点存下来
 *从根节点向下搜,贪心
 *如果从第三层开始,存在多个子节点不符合要求,则将该节点标记选中
 *否则将子节点标记选中
 *假了...看题解,是最深的优先开始贪心,神奇...
*/

