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
struct SegTreeForMax
{//用来进行区间推平,以及区间最值
	using type = int;
	struct SegTreeNode
	{
		type val,lazy;//延迟标记:储存节点的修改情况
		SegTreeNode(){
			val=lazy=0;
		}
	} Tree[maxn<<2];//完全二叉树(有没用到的节点),一倍可能炸
	type MIN=-1;
	int L=1,R=maxn-1,root=1;
	inline void pushup(int rt)
	{
		Tree[rt].val=max(Tree[rt<<1].val,Tree[rt<<1|1].val);
	}
	inline void pushdown(int rt,int l,int r)
	{
		if(Tree[rt].lazy!=MIN)
		{
			Tree[rt<<1].lazy=Tree[rt<<1|1].lazy=Tree[rt].lazy;
			Tree[rt<<1].val=Tree[rt<<1|1].val=Tree[rt].lazy;
			Tree[rt].lazy=MIN;
		}
	}
	void build(int rt,int l,int r)
	{
		Tree[rt].lazy=Tree[rt].val=0;
		if(l==r)
		{
			return;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	void init(int n)
	{
		this->L=1;
		this->R=n;
		this->root=1;
		build(1,1,n);
	}
	void modify(int l,int r,type val,int rt,int nl,int nr)
	{//更新区间[l,r]
		if(l>nr||r<nl)
			return;
		if(l<=nl&&nr<=r)
		{
			Tree[rt].val=val;
			Tree[rt].lazy=val;
			return;
		}
		pushdown(rt,nl,nr);
		int mid=(nl+nr)>>1;
		modify(l,r,val,rt<<1,nl,mid);
		modify(l,r,val,rt<<1|1,mid+1,nr);
		pushup(rt);
	}
	type query(int l,int r,int rt,int nl,int nr)
	{//查询区间[l,r]最大值
		if(l>nr||r<nl)
			return MIN;
		if(l<=nl&&nr<=r)
			return Tree[rt].val;
		pushdown(rt,nl,nr);
		int mid=(nl+nr)>>1;
		return max(query(l,r,rt<<1,nl,mid),query(l,r,rt<<1|1,mid+1,nr));
	}
} stm;
vector<int>G1[maxn],G2[maxn];
int dfn[maxn],mp[maxn],siz[maxn],tim=0;
int dfs(int x)
{
	dfn[x]=++tim;
	mp[tim]=x;
	siz[x]=1;
	for(auto &v:G2[x])
	{
		if(!dfn[x])
			siz[x]+=dfs(v);
	}
	return siz[x];
}
int ans=0,cnt=0,n;
void dfs(int x,int fa)
{
	int now=stm.query(dfn[x],dfn[x]+siz[x]-1,1,1,n);//子树上最小值
	if(now==0)
	{//不冲突,放心取,子树赋为dfn[x]
		stm.modify(dfn[x],dfn[x]+siz[x]-1,x,1,1,n);
		cnt++;
	}
	else{
		stm.modify(dfn[now],dfn[now]+siz[now]-1,0,1,1,n);//放弃祖先
		stm.modify(dfn[x],dfn[x]+siz[x]-1,x,1,1,n);//取这个
	}
	ans=max(ans,cnt);
	for(int &v:G1[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
	}
	if(now==0)//直接放弃取这个点
	{
		cnt--;
		stm.modify(dfn[x],dfn[x]+siz[x]-1,0,1,1,n);
	}
	else{//顶端的子树还原
		stm.modify(dfn[now],dfn[now]+siz[now]-1,now,1,1,n);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			G1[i].clear(),G2[i].clear(),dfn[i]=0;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G1[u].push_back(v);
			G1[v].push_back(u);
		}
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G2[u].push_back(v);
			G2[v].push_back(u);
		}
		stm.init(n);
		ans=cnt=tim=0;
		dfs(1);
		dfs(1,1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-08-07-15.14.22
 * C:\Users\dell\Desktop\C++\OJ\牛客\2021牛客暑期多校训练营\7-F.cpp
 * 选一个最大的集合,使得其中任意的两个点
 * 在第一棵树上是祖孙关系,在第二棵树上没有关系
 * 原题可以不连续
 * 1.答案集合必定为树1上一条链
*/

