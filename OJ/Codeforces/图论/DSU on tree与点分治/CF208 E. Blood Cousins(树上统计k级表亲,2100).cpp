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
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
//	void build(int *a,int n)//a是原数组,n是元素个数
//	{
//		this->n=n;
//		memset(c,0,sizeof(c));
//		memset(sum,0,sizeof(sum));
//		for(int i=1;i<=n;i++)
//			add(i,a[i]-a[i-1]);//构建差分c数组
//	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
vector<int>G[maxn];
int p[maxn],depth[maxn],gene[maxn][30];
int lg[maxn],ans[maxn];
int siz[maxn],son[maxn];
void get(int x,int fa)
{//倍增处理
	gene[x][0]=fa;
	siz[x]=1;
	depth[x]=depth[fa]+1;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		get(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
			son[x]=v;
	}
}
int findk(int x,int k)
{//k级祖先
	for(int i=lg[depth[x]];i>=0;i--)
		if(k&(1<<i))
			x=gene[x][i];
	return x;
}
vector<pii> query[maxn];//节点[x],ff=深度,ss=编号
int flag=0;
map<int,int>cnt,tmp;//深度,数量
map<int,int>::reverse_iterator rit;
void calc(int x,int fa,int top)
{
//	printf("dep[%d]=%d-%d\n",x,depth[x],depth[top]);
//	cnt[depth[x]-depth[top]]++;
	cnt[depth[x]]++;
	for(int &v:G[x])
		if(v!=fa&&v!=flag)
			calc(v,x,top);
}
void dfs(int x,int fa,bool keep)
{
	for(int &v:G[x])
	{
		if(v==fa||v==son[x])
			continue;
		dfs(v,x,0);
	}
	if(son[x])
		dfs(son[x],x,1);
//	for(auto &i:cnt)
//	{
////		cerr<<"cnt["<<i.ff<<"] = "<<i.ss<<endl;
//		tmp[i.ff+1]=i.ss;
//	}
//	cnt=tmp;
//	tmp.clear();
//	for(rit=cnt.rbegin();rit!=cnt.rend();)//保留的重儿子信息深度要全部+1
//	{
//		int val=rit->ss,num=rit->ss;
//		rit++;
//		cnt[val+1]=num;
//		cnt.erase(cnt.lower_bound(val));
//	}
	flag=son[x];
	calc(x,fa,x);//top=x
	for(pii &i:query[x])
	{
		ans[i.ss]=cnt[depth[x]+i.ff]-1;
//		ans[i.ss]=cnt[i.ff]-1;
//		printf("ans[%d]=%d\n",i.ss,cnt[i.ff]-1);
	}
	if(!keep)
	{
//		for(auto &i:cnt)
//			bit.radd(i.ff,i.ff,-i.ss);
		cnt.clear();
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,v,k;
	cin>>n;
	bit.n=n;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i])
			G[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(p[i]==0)
			get(i,0);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>v>>k;
		if(depth[v]>k)
		{
//			printf("%d 's %d-th gene = %d\n",v,k,findk(v,k));
			query[findk(v,k)].push_back(pii(k,i));
		}
		else
			ans[i]=0;
	}
	for(int i=1;i<=n;i++)
		if(p[i]==0)
			dfs(i,0,0);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
 *给定一片森林
 *统计某个节点与多少个节点有共同的k级祖先
 *可以反过来求某个节点k级子孙有多少个
 *求x的k级表亲 -> x的k级祖先的k级子孙
 *所以只要找到x的k级祖先,就变成了树上启发式合并模板题
 *求k级祖先可以考虑倍增优化
 *重儿子传递到父节点似乎要区间平移...
 *使用两个map暴力复制直接TLE59
 *那我们直接使用绝对深度,查询的时候dep[x]+k即为k级子孙深度
*/

