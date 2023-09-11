#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long ll;
int n,cnt=0,head[maxn];
struct edge
{
	int v,nex;
} e[maxn<<1];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int father[maxn],siz[maxn],depth[maxn],son[maxn];
void dfs1(int x,int fa)
{
	father[x]=fa;
	depth[x]=depth[fa]+1;
	siz[x]=1;
	int maxs=-1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxs)
		{
			son[x]=v;
			maxs=siz[v];
		}
	}
}
int val[maxn],tim=0,dfn[maxn],top[maxn];
void dfs2(int x,int t)
{
	dfn[x]=++tim;
	top[x]=t;
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=father[x]&&e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);
}
struct node
{
	ll val,lazy;
} tree[maxn<<2];
inline void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
}
void build(int root,int l,int r)
{
	tree[root].val=tree[root].lazy=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);//不写pushup了
}
inline void pushdown(int root,int l,int r)
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
void modify(int root,int nst,int ned,int ust,int ued,ll num)
{
	if(ned<ust||ued<nst)
		return;
	if(ust<=nst&&ned<=ued)
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
ll query(int root,int nst,int ned,int qst,int qed)
{
	if(ned<qst||qed<nst)
		return 0;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].val;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	return query(root<<1,nst,mid,qst,qed)+query(root<<1|1,mid+1,ned,qst,qed);
}
void UCHAIN(int x,int y,ll num)
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
ll ask(int x)
{
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}
int main()
{
	memset(head,-1,sizeof(head));
	int a,b,q;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		a++,b++;
		add(a,b);
		add(b,a);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		char ope;
		int u,v;
		ll num;
		cin>>ope;
		if(ope=='A')//路径加
		{
			cin>>a>>b>>num;
			UCHAIN(a+1,b+1,num);
		}
		else{//子树和
			cin>>u;
			cout<<ask(u+1)<<endl;
		}
	}
	return 0;
}
