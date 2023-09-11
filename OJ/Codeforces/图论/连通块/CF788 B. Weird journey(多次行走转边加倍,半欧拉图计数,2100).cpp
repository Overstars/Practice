//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
vector<int>G[maxn];
int deg[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,cir=0;
	cin>>n>>m;
	int tot=n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	vector<pii>E;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		if(Merge(u,v))
			tot--;
		if(u==v)
			cir++;
		else//自环就不计入度数了,也不*2
			deg[u]++,deg[v]++;
		E.push_back(pii(u,v));
	}
	for(pii &e:E)
		if(findfa(e.ff)!=findfa(E[0].ff))
			return cout<<0<<endl,0;
	ll ans=0;
	ans+=(ll)cir*(cir-1)/2;//两个自环
	ans+=(ll)cir*(m-cir);//自环*任意其他边
	for(int i=1;i<=n;i++)//度数去掉了自环,且没有加倍
		ans+=(ll)deg[i]*(deg[i]-1)/2;//所以枚举节点即可
	cout<<ans<<endl;
	return 0;
}
/*
 *一条路线使m中的2条边走1遍,m-2走2遍
 *如果走1遍的两条边不同则视为不同走法
 *路径不连通则无解,记走1遍两边为a,b
 *画一下可以发现和dfs访问过程很类似,可惜不一定是树
 *树的话统计一下叶子节点数作阶乘就行了
 *ab都在环上则必相邻,以环上点为根的树不影响答案,选取方案为环的大小,每个环贡献累加
 *有环时,ab必有一边a在环上,另一边b为叶子数,总贡献:叶子数*环上边的数目
 *应该就这上述三种情况...看题解...
 *欧拉路...还有自环...绝了
 *无向图欧拉路径：两个点(或0个点)度数为奇数,其余点度数为偶数
 *将原图所给m条边建两次(所有点度数为偶数),求删掉两边后半欧拉图数目
 *只有三种合法方式
 *1.删掉两个自环,得到一个欧拉图
 *2.删掉环上相邻两边,得到一个半欧拉图
 *3.删掉一条边与一个自环,得到一个半欧拉图
 */

