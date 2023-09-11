#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
struct edge
{
	int v,nex;
} e[maxn<<1];
int n,cnt=0,head[maxn];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int father[maxn],son[maxn],siz[maxn],depth[maxn];
void dfs1(int x,int fa)
{
	father[x]=fa;
	depth[x]=depth[fa]+1;
	siz[x]=1;
	int maxsiz=-1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxsiz)
		{
			son[x]=v;
			maxsiz=siz[v];
		}
	}
}
int tim=0,dfn[maxn],top[maxn];
void dfs2(int x,int t)
{
	dfn[x]=++tim;
	top[x]=t;
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=father[x]&&e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);//这次这里又出错了...
}
struct node
{//-1表示子区间混杂,0表示都空,1表示都满
	int full,lazy;
} tree[maxn<<2];
inline void pushup(int root)
{
	if(tree[root<<1].full==tree[root<<1|1].full)
		tree[root].full=tree[root<<1].full;
	else
		tree[root].full=-1;//子区间混杂
	tree[root].lazy=-1;
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		tree[root].full=0;
		tree[root].lazy=-1;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);//子区间影响不到上一级状态
	pushup(root);
}
inline void pushdown(int root)
{
	if(tree[root].lazy!=-1)//1表示区间灌满,0表示区间排空,-1表示没有更新
	{//区间推平
		tree[root<<1].full=tree[root<<1|1].full=tree[root<<1].lazy=tree[root<<1|1].lazy=tree[root].lazy;
		tree[root].lazy=-1;
	}
}
void modify(int root,int nst,int ned,int ust,int ued,int num)
{
	if(nst>ued||ust>ned)
		return;
	if(ust<=nst&&ned<=ued)
	{
		tree[root].full=tree[root].lazy=num;
		return;
	}
	pushdown(root);
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued,num);
	modify(root<<1|1,mid+1,ned,ust,ued,num);
	pushup(root);
}
bool query(int root,int nst,int ned,int q)
{
	if(nst<=q&&q<=ned&&tree[root].full!=-1)
		return tree[root].full;
	pushdown(root);
	int mid=(nst+ned)>>1;
	if(q<=mid)
		return query(root<<1,nst,mid,q);
	else
		return query(root<<1|1,mid+1,ned,q);
}
void mson(int x)//子树灌水
{
	modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,1);
}
void mchain(int x)//链排空
{
	int y=1;//根节点
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		modify(1,1,n,dfn[top[x]],dfn[x],0);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	modify(1,1,n,dfn[x],dfn[y],0);
}
int main()
{
	ios::sync_with_stdio(0);
	memset(head,-1,sizeof(head));
	int q,u,v,ope,x;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		cin>>ope>>x;
		if(ope==1)//将节点及子树注满水
		{
			mson(x);
		}
		else if(ope==2)//将节点到根的路径清空
		{
			mchain(x);
		}
		else{//输出节点状态
			cout<<query(1,1,n,dfn[x])<<endl;
		}
	}
	return 0;
}
