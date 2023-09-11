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
int tim=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
//int val[maxn],rec[maxn];//每个强连通分量的值
bool vis[maxn];
vector<int> G[maxn];//邻接表
void tarjan(int x)//标准的Tarjan缩点
{
	dfn[x]=low[x]=++tim;//dfs序
	stk[++Index]=x;
	vis[x]=1;
	for(int &v:G[x])
	{
		if(!dfn[v])//v未被访问
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);//回溯时更新low
		}//low[x]为x所在强连通分量最早起始节点
		else if(vis[v])//v在栈中,说明有环
			low[x]=min(low[x],dfn[v]);//更新起点为最早的那个
	}
	if(low[x]==dfn[x])
	{//以x为起点的强连通分量
		cnt++;//新图节点++
		do{
			belong[stk[Index]]=cnt;
//			rec[cnt]+=val[stk[Index]];//缩点后的权值
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
int col[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t=1,n,m;
//	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		tim=Index=cnt=0;
		memset(dfn,0,sizeof(dfn));
		vector<int>st[maxn];
		for(int i=1;i<=m;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
			cin>>col[i];
		for(int i=1,x,door;i<=m;i++)
		{//m个开关
			cin>>x;//x个门
			for(int j=1;j<=x;j++)
			{
				cin>>door;
				st[door].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{//a表示0,a+m表示1
			int a=st[i][0],b=st[i][1];
			if(col[i])//a xor b =0
			{
				G[a].push_back(b);
				G[b].push_back(a);
				G[m+a].push_back(m+b);
				G[m+b].push_back(m+a);
			}
			else{
				G[a].push_back(m+b);
				G[m+b].push_back(a);
				G[b].push_back(m+a);
				G[m+a].push_back(b);
			}
		}
		for(int i=1;i<=m;i++)
			if(!dfn[i])
				tarjan(i);
		bool ok=1;
		for(int i=1;i<=m;i++)
			if(belong[i]==belong[i+m])
				ok=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
//	system("pause");
	return 0;
}
/*
 * n个门0或1,m把钥匙,每个控制x个门
 * 你要将所有数都变为1
 * 保证每个门都被两把钥匙控制
 * 可以看出每个开关状态只有2种
 * 门相当于钥匙间的边
 * 大概半小时?本地竟然运行不了
*/

