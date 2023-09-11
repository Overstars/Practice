#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
const ll inf=0x3f3f3f3f;
int head[maxn],head2[maxn],cnt,cnt2;
struct edge
{
	int id,u,v,w,nex;
} e[maxn],G[maxn<<1];
inline void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].id=cnt;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
inline void add2(int u,int v,int w)
{
	G[++cnt2].u=u;
	G[cnt2].id=cnt2;
	G[cnt2].v=v;
	G[cnt2].w=w;
	G[cnt2].nex=head2[u];
	head2[u]=cnt2;
}
int father[maxn];
int findfa(int x)
{
	if(father[x]!=x)
		father[x]=findfa(father[x]);
	return father[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		father[b]=a;
	else
		father[a]=b;
	return 1;
}
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
bool cmp2(const edge &a,const edge &b)
{
	return a.id<b.id;
}
bool intree[maxn];
ll kruskal(int n,int m)
{
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		father[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		if(Merge(e[i].u,e[i].v))
		{
			intree[e[i].id]=1;
			add2(e[i].u,e[i].v,e[i].w);
			add2(e[i].v,e[i].u,e[i].w);
			ans+=e[i].w;
			if(--n==1)
				break;
		}
	}
	sort(e+1,e+m+1,cmp2);//按编号还原
	return ans;
}
//下面是树剖找G树链上最大边部分
int son[maxn],depth[maxn],siz[maxn];
ll val[maxn],w[maxn];
void dfs1(int x,int fa)
{
	father[x]=fa;
	siz[x]=1;
	depth[x]=depth[fa]+1;
	int maxs=-1;
	for(int i=head2[x];~i;i=G[i].nex)
	{
		int v=G[i].v;
		if(v==fa)
			continue;
		val[v]=G[i].w;//将边的权值赋给边头节点
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxs)
		{
			son[x]=v;
			maxs=siz[v];
		}
	}
}
int tim=0,dfn[maxn],top[maxn];
void dfs2(int x,int t)
{
	dfn[x]=++tim;
	w[tim]=val[x];
	top[x]=t;
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head2[x];~i;i=G[i].nex)
		if(G[i].v!=father[x]&&G[i].v!=son[x])
			dfs2(G[i].v,G[i].v);
}
struct node
{
	ll Max;
} tree[maxn<<2];
void pushup(int root)
{
	tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		tree[root].Max=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
ll query(int root,int nst,int ned,int qst,int qed)//区间查询
{
	if(ned<qst||qed<nst)
		return -inf;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].Max;
	}
	int mid=(nst+ned)>>1;
	return max(query(root<<1,nst,mid,qst,qed),query(root<<1|1,mid+1,ned,qst,qed));
}
ll QMAX(int x,int y,int n)
{
	ll ans=-inf;
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		ans=max(ans,query(1,1,n,dfn[top[x]],dfn[x]));
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	return max(ans,query(1,1,n,dfn[x]+1,dfn[y]));
}
int main()
{
	memset(head,-1,sizeof(head));
	memset(head2,-1,sizeof(head2));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	ll ans=kruskal(n,m);
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		if(intree[i])
			cout<<ans<<endl;
		else//减去环上的最大边
			cout<<ans+e[i].w-QMAX(e[i].u,e[i].v,n)<<endl;
	}
	return 0;
}
