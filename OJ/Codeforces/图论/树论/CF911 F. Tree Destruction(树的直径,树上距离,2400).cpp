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
vector<int> G[maxn];
int rt1,rt2;
int d1[maxn],d2[maxn];
int stk[maxn],top=0;
void dfs(int x,int fa,int d[],int &rt)
{
	if(d[x]>d[rt])
		rt=x;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		d[v]=d[x]+1;
		dfs(v,x,d,rt);
	}
}
bool ok=0;
int son[maxn];
void dfs(int x,int fa)
{
	if(!ok)
		stk[++top]=x;
	if(x==rt1)
		ok=1;
	for(auto &v:G[x])
		if(v!=fa)
		{
//			if(!ok)//这有什么问题吗
//				son[x]=v;
			d2[v]=d2[x]+1;
			dfs(v,x);
		}
	if(!ok)
		top--;
}
bool vis[maxn];
void print(int x,bool flag)
{
	if(vis[x])
		return;
	vis[x]=1;
	for(auto &v:G[x])
	{
		if(v==son[x]||vis[v])
			continue;
		print(v,0);
	}
	if(son[x])
		print(son[x],1);
	if(flag)
	{
		if(x!=rt2)
			cout<<x<<' '<<rt2<<' '<<x<<endl;
	}
	else{
		if(d1[x]>=d2[x])
			cout<<x<<' '<<rt1<<' '<<x<<endl;
		else
			cout<<x<<' '<<rt2<<' '<<x<<endl;
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
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	memset(d1,inf,sizeof(d1));
	d1[1]=0;
	dfs(1,0,d1,rt1);
//	memset(d1,inf,sizeof(d1));//x到rt1的距离
	d1[rt1]=0;
	dfs(rt1,0,d1,rt2);
	memset(d2,inf,sizeof(d2));//x到rt2的距离
	d2[rt2]=0;
	top=0;
	dfs(rt2,0);
	fprintf(stderr,"rt1=%d,rt2=%d\n",rt1,rt2);
	set<int>st;
	for(int i=1;i<=top;i++)
	{
		st.insert(stk[i]);
		if(i<top)//离谱,加在这里就过了
			son[stk[i]]=stk[i+1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(st.count(i))
			ans+=d1[i];//到rt1
		else
			ans+=max(d1[i],d2[i]);
	}
	cout<<ans<<endl;
	print(rt2,1);
	return 0;
}
/*
 * 2021-05-24-14.29.29
 * C:\Users\dell\Desktop\C++\OJ\Codeforces\图论\树论\CF911 F. Tree Destruction(树的直径,树上距离,2400).cpp
 * 一棵树,每次挑选这棵树的两个叶子,加上他们之间的距离
 * 然后将其中一个点去掉,问你边数(距离)之和最大可以是多少
 * 首先每个节点到树的直径端点距离最长
 * 那么每个节点的贡献就是这个
 * 三次dfs求出来距离,删掉每个不在直径上的点
*/

