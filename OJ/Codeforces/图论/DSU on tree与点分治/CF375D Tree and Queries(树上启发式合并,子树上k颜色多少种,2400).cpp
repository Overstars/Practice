//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
	void build(int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
//		for(int i=1;i<=n;i++)
//			add(i,a[i]-a[i-1]);//构建差分c数组
	}
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
int siz[maxn],son[maxn];
void dfs(int x,int fa)
{//求子树大小及重儿子
	siz[x]=1;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
			son[x]=v;
	}
}
map<int,int> mp;
int c[maxn],ans[maxn];
vector<pii>ques[maxn];//节点x,数值>=k
int flag,lim=1e5+5;
void calc(int x,int fa)
{//暴力更新x及其轻儿子子树贡献
//	printf("%d\n",x);
	int val=mp[c[x]];
	if(val>0)
		bit.radd(val,val,-1);//删掉原来的值
	val++;
	bit.radd(val,val,1);//增加新的值
	mp[c[x]]=val;
	for(int &v:G[x])
	{
		if(v==fa||v==flag)
			continue;
		calc(v,x);
	}
}
void dfs2(int x,int fa,bool keep)
{
//	cerr<<"x = "<<x<<endl;
	for(int &v:G[x])
	{//先处理轻儿子
		if(v==fa||v==son[x])
			continue;
		dfs2(v,x,0);
	}
	if(son[x])
	{//重儿子存在,处理重儿子
		dfs2(son[x],x,1);
		flag=son[x];//防止统计x的重儿子
	}
//	cerr<<"wtf"<<endl;
	calc(x,fa);//在重儿子基础上更新轻儿子
	flag=0;
	for(pii &i:ques[x])//离线统计答案
		ans[i.ss]=bit.query(lim)-bit.query(i.ff-1);
	if(!keep)
	{
		for(auto &i:mp)//第一关键字颜色,第二关键字数量
			bit.radd(i.ss,i.ss,-1);
//		bit.build(lim);
		mp.clear();
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,x,k,u,v;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>k;
		ques[x].push_back(pii(k,i));
	}
	bit.build(lim);
	dfs(1,1);
	dfs2(1,1,1);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}
/*
 *https://www.luogu.com.cn/problem/CF375D
 *n点的树,每个点有一个颜色
 *大致流程和树上启发式合并没什么区别
 *需要快速统计>=k的元素个数(带修),用什么支持?
 *用桶+线段树支持,注意清空优化
*/

