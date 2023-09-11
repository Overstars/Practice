#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int head[maxn],cnt,n,val[maxn];
struct edge
{
	int v,nex;
} e[maxn<<1];
int depth[maxn],father[maxn],son[maxn],siz[maxn];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs1(int x,int fa)//求出父节点,重儿子,深度,子树大小
{
	father[x]=fa;
	depth[x]=depth[fa]+1;
	siz[x]=1;
	int maxsize=-1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		if(e[i].v==fa)
			continue;
		dfs1(e[i].v,x);
		siz[x]+=siz[e[i].v];
		if(siz[e[i].v]>maxsize)
		{
			son[x]=e[i].v;
			maxsize=siz[e[i].v];
		}
	}
}
int tim,dfn[maxn],top[maxn],w[maxn];
void dfs2(int x,int t)//求出,DFS序,top数组
{
	top[x]=t;
	dfn[x]=++tim;
	w[tim]=val[x];
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v!=son[x]&&v!=father[x])
			dfs2(v,v);
	}
}
struct node
{
	int val,lazy;
} tree[maxn<<2];
inline void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
}
void build(int root,int l,int r)
{
	tree[root].lazy=0;
	if(l==r)
	{
		tree[root].val=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
void pushdown(int root,int l,int r)
{
	if(tree[root].lazy)
	{
		int mid=(l+r)>>1;
		tree[root<<1].val+=tree[root].lazy*(mid-l+1);
		tree[root<<1|1].val+=tree[root].lazy*(r-mid);
		tree[root<<1].lazy+=tree[root].lazy;
		tree[root<<1|1].lazy+=tree[root].lazy;
		tree[root].lazy=0;
	}
}
void modify(int root,int nst,int ned,int ust,int ued,int num)
{
	if(nst>ued||ust>ned)
		return;
	if(ust<=nst&&ued>=ned)
	{
		tree[root].val+=num*(ned-nst+1);
		tree[root].lazy+=num;
		return;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued,num);
	modify(root<<1|1,mid+1,ned,ust,ued,num);
	pushup(root);
}
int query(int root,int nst,int ned,int ust,int ued)
{
	if(nst>ued||ust>ned)
		return 0;
	if(ust<=nst&&ned<=ued)
	{
		return tree[root].val;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	return query(root<<1,nst,mid,ust,ued)+query(root<<1|1,mid+1,ned,ust,ued);
}
void mson(int x,int num)
{
	modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,num);
}
void mchain(int x,int y,int num)
{
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		modify(1,1,n,dfn[top[x]],dfn[x],num);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	modify(1,1,n,dfn[x],dfn[y],num);
}
int qson(int x)
{
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}
int qchain(int x,int y)
{
	int ret=0;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		ret+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	return ret+query(1,1,n,dfn[x],dfn[y]);
}
signed main()
{
	int m;
	scanf("%lld%lld",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	while(m--)
	{
		int ope,x,a;
		scanf("%lld",&ope);
		if(ope==1)
		{
			scanf("%lld%lld",&x,&a);
			modify(1,1,n,dfn[x],dfn[x],a);
		}
		else if(ope==2)
		{
			scanf("%lld%lld",&x,&a);
			mson(x,a);
		}
		else{
			scanf("%lld",&x);
			printf("%lld\n",qchain(1,x));
		}
	}
	return 0;
}
