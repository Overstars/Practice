#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=300005;
int n,head[maxn],cnt=0;
ll val[maxn];
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
int father[maxn],son[maxn],depth[maxn],siz[maxn];
void dfs1(int x,int fa)
{
	depth[x]=depth[fa]+1;
	father[x]=fa;
	siz[x]=1;
	int maxsiz=-1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(maxsiz<siz[v])
		{
			son[x]=v;
			maxsiz=siz[v];
		}
	}
}
int tim=0,dfn[maxn],top[maxn],w[maxn];
void dfs2(int x,int t)
{
	dfn[x]=++tim;
	top[x]=t;//注意这里,top是在树外的
	w[tim]=val[x];
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=father[x]&&e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);
}
struct node
{
	ll val,Max;
//	int lazy;
} tree[maxn<<2];
inline void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
	tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);
}
void build(int root,int l,int r)
{
//	tree[root].lazy=0;
	if(l==r)
	{
		tree[root].val=tree[root].Max=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
//inline void pushdown(int root,int l,int r)
//{
//	if(tree[root].lazy)
//	{
//		int mid=(l+r)>>1;
//		tree[root<<1].val+=tree[root].lazy*(mid-l+1);
//		tree[root<<1|1].val+=tree[root].lazy*(r-mid);
//		tree[root<<1].lazy+=tree[root].lazy;
//		tree[root<<1|1].lazy+=tree[root].lazy;
//		tree[root].lazy=0;
//	}
//}
void modify(int root,int nst,int ned,int up,ll num)
{
	if(up<nst||up>ned)
		return;
	if(nst==ned&&nst==up)
	{
		tree[root].Max=tree[root].val=num;
		return;
	}
	int mid=(nst+ned)>>1;
	if(up<=mid)
		modify(root<<1,nst,mid,up,num);
	else
		modify(root<<1|1,mid+1,ned,up,num);
	pushup(root);
}
ll qmax(int root,int nst,int ned,int qst,int qed)
{
	if(ned<qst||qed<nst)
		return -inf;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].Max;
	}
	int mid=(nst+ned)>>1;
	return max(qmax(root<<1,nst,mid,qst,qed),qmax(root<<1|1,mid+1,ned,qst,qed));
}
ll qsum(int root,int nst,int ned,int qst,int qed)
{
	if(ned<qst||qed<nst)
		return 0;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].val;
	}
	int mid=(nst+ned)>>1;
	return qsum(root<<1,nst,mid,qst,qed)+qsum(root<<1|1,mid+1,ned,qst,qed);
}
ll QMAX(int x,int y)
{
	ll ret=-inf;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		ret=max(ret,qmax(1,1,n,dfn[top[x]],dfn[x]));
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	ret=max(ret,qmax(1,1,n,dfn[x],dfn[y]));
	return ret;
}
ll QSUM(int x,int y)
{
	ll ret=0;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		ret+=qsum(1,1,n,dfn[top[x]],dfn[x]);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	ret+=qsum(1,1,n,dfn[x],dfn[y]);
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(head,-1,sizeof(head));
	int u,v,q;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		cin>>val[i];
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		char str[10];
		cin>>str;
		if(str[1]=='H')//修改
		{
			ll t;
			cin>>u>>t;
			modify(1,1,n,dfn[u],t);//注意树上是dfs序
		}
		else if(str[1]=='M')//最值
		{
			cin>>u>>v;
			cout<<QMAX(u,v)<<'\n';
		}
		else{//求和
			cin>>u>>v;
			cout<<QSUM(u,v)<<'\n';
		}
	}
	return 0;
}
