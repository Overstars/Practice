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
{//权值,编号,经过次数
	int v,w,id;
	edge(int a,int b,int c):
		v(a),w(b),id(c){}
};
vector<edge>G[maxn];
ll siz[maxn],val[maxn],cnt[maxn],n;
double ans=0;
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto &e:G[x])
	{
		if(e.v==fa)
			continue;
		dfs(e.v,x);
		siz[x]+=siz[e.v];
		cnt[e.id]=siz[e.v]*(n-siz[e.v])*(n-2);//经过次数
		val[e.id]=e.w;//边权
		ans+=cnt[e.id]*val[e.id];
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int u,v,w,q,op,nw;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(edge(v,w,i));
		G[v].push_back(edge(u,w,i));
	}
	ll tot=n*(n-1)*(n-2)/6;//总取法
	dfs(1,1);
	cin>>q;
	while(q--)
	{
		cin>>op>>nw;
		ans-=(val[op]-nw)*cnt[op];
		val[op]=nw;
		cout<<setiosflags(ios::fixed)<<setprecision(10)<<ans/tot<<endl;
	}
	return 0;
}
/*
 *一棵无向带权树,q次修改,每次使一个边权减少
 *随机选取三个不同点
 *请对每次修改后输出d(a,b)+d(b,c)+d(c,a)的期望
 *和两点期望距离很像
 *求出每条边经过方法数C(v1,2)*v2+C(v2,2)*v1,和总选取方法数C(n,3)
 *化简得v1*v2*(n-2)/2,每边经过两次再*2
 */

