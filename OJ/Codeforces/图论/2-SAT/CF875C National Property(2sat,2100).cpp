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
vector<int> R[maxn];
int tim=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
int val[maxn],rec[maxn];//每个强连通分量的值
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,l,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>x;
			R[i].push_back(x);
		}
	}
	bool ok=1;
	for(int i=2;i<=n;i++)
	{
		bool diff=0;
		for(int j=0;j<min(R[i-1].size(),R[i].size());j++)
		{
			int u=R[i-1][j],v=R[i][j];
			if(u>v)//逻辑a假b真,则连边a->~a,~b->b
			{
//				G[m+u].push_back(u);//必须大写
//				G[v].push_back(m+v);//必须小写
				G[u].push_back(m+u);//必须大写,u必须假
				G[m+v].push_back(v);//必须小写,v必须真,假->真
			}
			else if(u<v)
			{//逻辑a->b,只有a小写b大写不成立
				G[u].push_back(v);
				G[m+v].push_back(m+u);
			}
			if(u!=v)
			{
				diff=1;
				break;
			}
		}
		if(!diff&&R[i-1].size()>R[i].size())
			ok=0;
	}
	for(int i=1;i<=2*m;i++)
		if(!dfn[i])
			tarjan(i);
//	for(int i=1;i<=m;i++)
//		printf("c[%d]=%d,c[%d]=%d\n",i,belong[i],i+m,belong[i+m]);
	vector<int>ans;
	for(int i=1;i<=m;i++)
		if(belong[i]==belong[m+i])//
			ok=0;
		else if(belong[i]>belong[m+i])//变为大写
			ans.push_back(i);
	if(!ok)
		return cout<<"No"<<endl,0;
	cout<<"Yes"<<endl;
	cout<<ans.size()<<endl;
	for(int &i:ans)
		cout<<i<<' ';
	return 0;
}
/*
 *大写字母字典序<小写
 *给定n个字符串,要求全局更改一些字母->大写
 *使这n个字符串按字典序排列
 *每个字符有两种状态,小1/大0
 *若上方字符a>下方字符b,则上方字符必须大写,下方必须小写
 *逻辑a假b真,则连边a->~a,~b->b
 *否则只要不a小写,b大写就为真
 *逻辑a->b,
*/
/*
4 4
3 3 4 1
4 3 4 2 2
4 2 1 2 3
3 4 2 2
*/
