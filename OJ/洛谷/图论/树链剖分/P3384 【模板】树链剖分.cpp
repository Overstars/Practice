#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100005;
int mod=100000007;
int head[maxn],cnt=0;
struct edge
{
	int v,nex;
} e[maxn<<1];
int father[maxn],son[maxn];//父节点,重儿子节点
int depth[maxn],siz[maxn],top[maxn];//深度,子树大小,节点所在重链的顶部节点
int tim=0,dfn[maxn],rk[maxn],w[maxn];//计数器,时间戳(节点编号),访问顺序
int val[maxn];//给定的每个节点的权值
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs1(int x,int fa)
{
	father[x]=fa;
	depth[x]=depth[fa]+1;
	siz[x]=1;
	int maxsize=-1;
	for(int i=head[x];~i;i=e[i].nex)//遍历儿子节点
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];//加上儿子的子树大小
		if(siz[v]>maxsize)
		{
			maxsize=siz[v];
			son[x]=v;//记录重儿子
		}
	}
}
void dfs2(int x,int t)//当前节点与重链顶节点
{
	top[x]=t;//记录该节点所在重链的顶部节点
	dfn[x]=++tim;//记录该节点的访问时间(给节点编号,方便线段树操作)
	rk[tim]=x;//记录访问节点的顺序
	w[tim]=val[x];//将x结点权值存到对应的时间戳
	if(!son[x])
		return;//没有儿子
	dfs2(son[x],t);//继续处理重儿子
	for(int i=head[x];~i;i=e[i].nex)
	{//处理其他儿子
		if(e[i].v!=son[x]&&e[i].v!=father[x])
			dfs2(e[i].v,e[i].v);//开始另一条重链
	}
}
struct node
{
	int val,lazy;
} tree[maxn<<2];
inline void pushup(int root)
{
	tree[root].val=(tree[root<<1].val+tree[root<<1|1].val)%mod;
}
void build(int root,int l,int r)
{
	tree[root].val=tree[root].lazy=0;
	if(l==r)//注意这里是l
		tree[root].val=w[l]%mod;//按时间戳顺序的数组
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
		tree[root<<1].val=(tree[root<<1].val%mod+(tree[root].lazy%mod*(mid-l+1))%mod)%mod;
		tree[root<<1|1].val=(tree[root<<1|1].val%mod+(tree[root].lazy%mod*(r-mid)%mod))%mod;
		tree[root<<1].lazy=(tree[root<<1].lazy%mod+tree[root].lazy%mod)%mod;
		tree[root<<1|1].lazy=(tree[root<<1|1].lazy%mod+tree[root].lazy%mod)%mod;
		tree[root].lazy=0;
	}
}
void modify(int root,int nst,int ned,int ust,int ued,int num)
{
	if(ned<ust||ued<nst)
		return;
	if(ust<=nst&&ued>=ned)
	{
		tree[root].lazy=(tree[root].lazy%mod+num%mod)%mod;
		tree[root].val=(tree[root].val%mod+((ned-nst+1)%mod*(num%mod))%mod)%mod;
		return;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued,num);
	modify(root<<1|1,mid+1,ned,ust,ued,num);
	pushup(root);
}
int query(int root,int nst,int ned,int qst,int qed)
{
	if(ned<qst||qed<nst)
		return 0;
	if(qst<=nst&&qed>=ned)
	{
		return tree[root].val%mod;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	return (query(root<<1,nst,mid,qst,qed)+query(root<<1|1,mid+1,ned,qst,qed))%mod;
}
inline void mson(int x,int n,int addnum)
{//将以x为根的子树全部加上一个数
	modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,addnum);//子树节点编号是连续的
}
inline int qson(int x,int n)
{
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1)%mod;//同上
}
void mchain(int x,int y,int n,int addnum)
{
	addnum%=mod;
	while(top[x]!=top[y])//不在同一条链上时
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);//保证x所在链顶部更低
		modify(1,1,n,dfn[top[x]],dfn[x],addnum);//更新顶部节点较低的重链(顶部节点到当前点部分)
		x=father[top[x]];//跳到链顶节点的父节点
	}
	if(depth[x]>depth[y])//直到最后在同一条重链上
		swap(x,y);//此时保证x节点在y上面
	modify(1,1,n,dfn[x],dfn[y],addnum);
}
int qchain(int x,int y,int n)
{
	int ret=0;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		ret=(ret+query(1,1,n,dfn[top[x]],dfn[x]))%mod;
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	return (ret+query(1,1,n,dfn[x],dfn[y]))%mod;
}
int main()
{
//	freopen("P3384.in","r",stdin);
	int n,m,p,r;
	scanf("%d%d%d%d",&n,&m,&r,&mod);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(r,r);
	dfs2(r,r);
	build(1,1,n);
	while(m--)
	{
		int ope,x,y,z;
		scanf("%d",&ope);
		if(ope==1)
		{//链x->y修改
			scanf("%d%d%d",&x,&y,&z);
			mchain(x,y,n,z);
		}
		else if(ope==2)
		{//链x->y查询
			scanf("%d%d",&x,&y);
			printf("%d\n",qchain(x,y,n));
		}
		else if(ope==3)
		{//x子树修改
			scanf("%d%d",&x,&z);
			mson(x,n,z);
		}
		else{//x子树查询
			scanf("%d",&x);
			printf("%d\n",qson(x,n));
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%d:%d\n",i,tree[i].val);
	return 0;
}
/*
 *功能：
 *1.更新/查询某个节点子树的权值
 *2.更新/查询树上两个节点间所有点的权值
 *性质：
 *1.子树的时间戳一定全部小于父节点，并且连续
 *2.任何一条路径都是由重链的一部分与重链间的叶子节点构成
 *3.任何父节点都一定在一条重链上
*/
