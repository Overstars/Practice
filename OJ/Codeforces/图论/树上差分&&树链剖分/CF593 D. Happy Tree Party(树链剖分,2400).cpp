//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int n,tot=0,head[maxn];
double val[maxn];//给定的每个节点的权值
struct edge
{//边权一般不必记录到这里
	int v,nex;
	ll w;
} e[maxn<<1];
inline void add(int u,int v,ll w=0)
{
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot;
}
//以点代边:以节点的权值代表该节点到父节点边的权值,修改与查询跳过链顶点即可(最终的参数改为dfn[x]+1)
//使用前先初始化,然后加边,dfs1(rt,rt),dfs2(rt,rt),build(1,1,n),使用封装好的函数修改+查询
namespace hld{//heavy-light decomposition
	int n,father[maxn],son[maxn],depth[maxn],siz[maxn];//父节点,重儿子节点,深度,子树大小
	int tim=0,dfn[maxn],rk[maxn],top[maxn];//计数器,时间戳(节点编号),访问顺序,节点所在重链的顶部节点
	using type=long long;//每个节点的类型
	type w[maxn];//节点dfs序对应权值
	void init(int N)
	{
		n=N;
		fill(w,w+maxn,1);
//		cerr<<"hld::n  = "<<hld::n<<endl;
		tim=tot=0;
		memset(head,-1,sizeof(head));
		memset(depth,0,sizeof(depth));
//		memset(father,0,sizeof(father));
		memset(son,0,sizeof(son));
//		memset(top,0,sizeof(top));
		memset(dfn,0,sizeof(dfn));
	}
	void dfs1(int x,int fa)
	{//预处理出深度,父节点,重儿子,子树大小
		depth[x]=depth[fa]+1;
		father[x]=fa;
		siz[x]=1;
		int maxsiz=-1;
		for(int i=head[x];~i;i=e[i].nex)
		{//遍历儿子节点
			int v=e[i].v;
			if(v==fa)
				continue;
			val[v]=e[i].w;//log((double)e[i].w);//以点代边:将边的权值赋给边头节点
//			fprintf(stderr,"val[%lld]=%lld\n",v,val[v]);
			dfs1(v,x);
			siz[x]+=siz[v];//加上儿子的子树大小
			if(maxsiz<siz[v])
			{
				son[x]=v;
				maxsiz=siz[v];//记录重儿子
			}
		}
	}
	void dfs2(int x,int t)
	{//按dfs序对各节点重新编号,并记录对应权值到w数组
		dfn[x]=++tim;//记录dfs序
		rk[tim]=x;//记录访问节点的顺序,即dfn的反函数
		top[x]=t;//注意这里,top是在树外的
		w[tim]=val[x];//将x结点权值存到对应的时间戳
		if(!son[x])//没有儿子
			return;
		dfs2(son[x],t);//继续处理重儿子
		for(int i=head[x];~i;i=e[i].nex)//处理其他儿子
			if(e[i].v!=father[x]&&e[i].v!=son[x])
				dfs2(e[i].v,e[i].v);//开始另一条重链
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(depth[top[x]]<depth[top[y]])
				swap(x,y);
			x=father[top[x]];
		}
		return (depth[x]>depth[y])?y:x;
	}
	struct node//线段树按dfs序维护树上路径权值部分
	{
		type val,Max,lazy;
	} tree[maxn<<2];
	ll update(ll x,ll y)
	{
		if((long double)x*(long double)y>1e18)
			return 1e18+10000;
		return x*y;
	}
	inline void pushup(int root)
	{
		tree[root].val=update(tree[root<<1].val,tree[root<<1|1].val);
//		tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
//		tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);
	}
	void build(int root=1,int l=1,int r=n)
	{
		tree[root].lazy=0;
		if(l==r)//注意这里是l
			tree[root].val=tree[root].Max=w[l];//按时间戳顺序的数组
		else{
			int mid=(l+r)>>1;
			build(root<<1,l,mid);
			build(root<<1|1,mid+1,r);
			pushup(root);
		}
	}
	inline void pushdown(int root,int l,int r)
	{
		if(tree[root].lazy)
		{
			int mid=(l+r)>>1;
			tree[root<<1].val=tree[root<<1].val+tree[root].lazy*(mid-l+1);
			tree[root<<1|1].val=tree[root<<1|1].val+tree[root].lazy*(r-mid);
//			tree[root<<1].Max+=tree[root].lazy;//子节点最大值也要+更新值
//			tree[root<<1|1].Max+=tree[root].lazy;
//			tree[root<<1].lazy+=tree[root].lazy;
//			tree[root<<1|1].lazy+=tree[root].lazy;
			tree[root].lazy=0;
		}
	}
	void modify(int root,int nst,int ned,int ust,int ued,type num)
	{//区间更新
		if(ned<ust||ued<nst)
			return;
		if(ust<=nst&&ued>=ned)
		{
			double tmp=pow((double)num,ned-nst+1);
//			double tmp=log10(num)*(ned-nst+1);//pow((double)num,ned-nst+1);
			if(tmp>1e18)
				tmp=1e18+10000;
			else
				tmp=num;//pow((double)num,ned-nst+1);
			tree[root].val=(ll)tmp;
//			tree[root].val=tree[root].val+(ned-nst+1)*num;
//			tree[root].Max+=num;
//			tree[root].lazy=num;
			return;
		}
		pushdown(root,nst,ned);
		int mid=(nst+ned)>>1;
		modify(root<<1,nst,mid,ust,ued,num);
		modify(root<<1|1,mid+1,ned,ust,ued,num);
		pushup(root);
	}
	type query(int root,int nst,int ned,int qst,int qed)
	{//查询区间和
		if(ned<qst||qed<nst)
			return 1;
		if(qst<=nst&&ned<=qed)
			return tree[root].val;
		pushdown(root,nst,ned);
		int mid=(nst+ned)>>1;
		return update(query(root<<1,nst,mid,qst,qed),query(root<<1|1,mid+1,ned,qst,qed));
	}
	type qmax(int root,int nst,int ned,int qst,int qed)
	{//查询区间和
		if(ned<qst||qed<nst)
			return LLONG_MIN;//这里也要改成对应的MIN
		if(qst<=nst&&ned<=qed)
			return tree[root].Max;
		pushdown(root,nst,ned);
		int mid=(nst+ned)>>1;
		return max(qmax(root<<1,nst,mid,qst,qed),qmax(root<<1|1,mid+1,ned,qst,qed));
	}
	//以下是开放的
	inline void mson(int x,type addnum,int n=n)
	{//将以x为根的子树全部加上一个数
		modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,addnum);//子树节点编号是连续的
	}
	inline type sonsum(int x,int n=n)
	{//查询以x为根子树权值和
		return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);//同上
	}
	type sonmax(int x,int n=n)
	{
		return qmax(1,1,n,dfn[x],dfn[x]+siz[x]-1);
	}
	void mchain(int x,int y,type addnum,int n=n)
	{
		while(top[x]!=top[y])//不在同一条链上时
		{
			if(depth[top[x]]<depth[top[y]])
				swap(x,y);//保证x所在链顶部更低
			modify(1,1,n,dfn[top[x]],dfn[x],addnum);//更新顶部节点较低的重链(顶部节点到当前点部分)
			x=father[top[x]];//跳到链顶节点的父节点
		}
		if(depth[x]>depth[y])//直到最后在同一条重链上
			swap(x,y);//此时保证x节点在y上面
		modify(1,1,n,dfn[x]+1,dfn[y],addnum);
	}
	type chainsum(int x,int y,int n=n)
	{//这里修改为求区间积
		type ret=1;
		while(top[x]!=top[y])
		{
			if(depth[top[x]]<depth[top[y]])
				swap(x,y);
			ll tmp=query(1,1,n,dfn[top[x]],dfn[x]);
			ret=update(ret,tmp);
//			assert(ret!=0);
			x=father[top[x]];
		}
		if(depth[x]>depth[y])
			swap(x,y);
		return update(ret,query(1,1,n,dfn[x]+1,dfn[y]));
//		return ret*query(1,1,n,dfn[x]+1,dfn[y]);
	}
	type chainmax(int x,int y,int n=n)
	{
		type ret=LLONG_MIN;//注意这里改成对应的MIN
		while(top[x]!=top[y])
		{
			if(depth[top[x]]<depth[top[y]])
				swap(x,y);
			ret=max(ret,qmax(1,1,n,dfn[top[x]],dfn[x]));
			x=father[top[x]];
		}
		if(depth[x]>depth[y])
			swap(x,y);
		return max(ret,qmax(1,1,n,dfn[x],dfn[y]));
	}
}
pii E[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	ll wer=(long double)1e23+10;
//	cerr<<LLONG_MAX+LLONG_MAX<<endl;
//	cerr<<"wtf = "<<wer<<endl;
//	cerr<<LLONG_MAX/wer<<endl;
	int m,u,v,w,a,b,c,p,op;
	cin>>n>>m;
	hld::init(n);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
//		assert(w<=1e18);
		E[i].ff=u,E[i].ss=v;//记录
	}
	hld::dfs1(1,1);
	hld::dfs2(1,1);
	hld::build(1,1,n);
	while(m--)
	{
		cin>>op;
		if(op==1)
		{//每走一个边,c/=w,维护区间积
			cin>>a>>b>>c;//a->b
//			assert(c<=1e18);
			ll val=hld::chainsum(a,b);
//			assert(val!=0);
//			fprintf(stderr,"val = %lld\n",val);
			cout<<c/val<<endl;
//			#define e 2.7182818284590452354
//			double now=log(c),f=hld::chainsum(a,b);
//			fprintf(stderr,"%.3f / %.3f\n",now,f);
//			if(now<f)
//				cout<<0<<endl;
//			else
//				cout<<floor(pow(e,now-f))<<endl;
		}
		else{
			cin>>p>>c;//修改权值为c
//			assert(c<=1e18);
			hld::mchain(E[p].ff,E[p].ss,c);//-hld::chainsum(E[p].ff,E[p].ss));
//			double pre=hld::chainsum(E[p].ff,E[p].ss);
////			fprintf(stderr,"%lld->%lld=%.3f\n",E[p].ff,E[p].ss,pre);
//			hld::mchain(E[p].ff,E[p].ss,log(c)-pre);
		}
	}
	return 0;
}
/*
 * 2021-04-13-19.21.27
 * 注意*每次*都是向下取整,而不单是结果向下取整
*/

