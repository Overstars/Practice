#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
const int maxn=100005;
ll val[maxn],w[maxn];
int n,cnt=0,head[maxn];
struct edge
{
	int v,nex;
	ll w;
} e[maxn<<1];
inline void add(int u,int v,ll w)
{
	e[++cnt].v=v;
//	e[cnt].u=u;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int father[maxn],son[maxn],siz[maxn],depth[maxn];
void dfs1(int x,int fa)//根节点是没有值的
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
		val[v]=e[i].w;//将边的权值赋给边头节点
		dfs1(v,x);
		siz[x]+=siz[v];
		if(maxsiz<siz[v])
		{
			maxsiz=siz[v];
			son[x]=v;
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
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=father[x]&&e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);
}
struct node
{
//	ll val;
	ll lazy,Max,tag;
	node()
	{
		lazy=Max=0;
		tag=-1;
	}
} tree[maxn<<2];
inline void pushup(int root)
{
//	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
//	printf("%d由%lld变为",root,tree[root].Max);
	tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);
//	printf("%lld...\n",tree[root].Max);
}
void build(int root,int l,int r)
{
	tree[root].lazy=0;//加法标签
	tree[root].tag=-1;//修改标签
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
void pushdown(int root,int l,int r)
{
	if(tree[root].tag>=0)//该区间经历过更新
	{//优先修改,再增加
		tree[root<<1].lazy=tree[root<<1|1].lazy=0;//子节点之前的lazy标签不要
		tree[root<<1].Max=tree[root<<1|1].Max=tree[root].tag;
		tree[root<<1].tag=tree[root<<1|1].tag=tree[root].tag;
//		printf("是的,%d的tag为%lld...\n",root,tree[root].tag);
		tree[root].tag=-1;
	}
	if(tree[root].lazy)//假如与tag同时存在,说明root管辖区间被重新赋值后又被增加
	{
//		printf("是的,%d的lazy为%lld...\n",root,tree[root].lazy);
		tree[root<<1].Max+=tree[root].lazy;
		tree[root<<1|1].Max+=tree[root].lazy;
		tree[root<<1].lazy+=tree[root].lazy;
		tree[root<<1|1].lazy+=tree[root].lazy;
		tree[root].lazy=0;
	}
}
void modify(int root,int nst,int ned,int up,ll num)//单边修改
{
	if(up<nst||up>ned)
		return;
	if(nst==ned&&nst==up)
	{
		tree[root].Max=num;
		tree[root].lazy=0;
		tree[root].tag=-1;
		return;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	if(up<=mid)
		modify(root<<1,nst,mid,up,num);
	else
		modify(root<<1|1,mid+1,ned,up,num);
	pushup(root);
}
void modify(int root,int nst,int ned,int ust,int ued,ll num)
{//区间修改
	if(ned<ust||ued<nst)
		return;
	if(ust<=nst&&ned<=ued)
	{
		tree[root].Max=tree[root].tag=num;//区间最值变为num
//		printf("是不是搞错了?\n");
		tree[root].lazy=0;//去掉懒标记
		return;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued,num);
	modify(root<<1|1,mid+1,ned,ust,ued,num);
	pushup(root);
}
void chainadd(int root,int nst,int ned,int ust,int ued,ll num)
{
	if(ned<ust||ued<nst)
		return;
	if(ust<=nst&&ned<=ued)
	{
//		printf("%d节点原来是%lld\n",root,tree[root].Max);
		tree[root].Max+=num;//区间最值同时增加
//		printf(",变为%lld\n",tree[root].Max);
		tree[root].lazy+=num;
		return;
	}
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	chainadd(root<<1,nst,mid,ust,ued,num);
	chainadd(root<<1|1,mid+1,ned,ust,ued,num);
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
	pushdown(root,nst,ned);//这个又漏写了...
	int mid=(nst+ned)>>1;
	return max(query(root<<1,nst,mid,qst,qed),query(root<<1|1,mid+1,ned,qst,qed));
}
void MCHAIN(int x,int y,ll num)//链覆盖
{
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		modify(1,1,n,dfn[top[x]],dfn[x],num);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);//x改为深度较浅
	modify(1,1,n,dfn[x]+1,dfn[y],num);//链顶节点的边权不要修改
}
void CHAINADD(int x,int y,ll num)//链增加
{
	while(top[x]!=top[y])
	{
		if(depth[top[x]]<depth[top[y]])
			swap(x,y);
		chainadd(1,1,n,dfn[top[x]],dfn[x],num);
		x=father[top[x]];
	}
	if(depth[x]>depth[y])
		swap(x,y);
	chainadd(1,1,n,dfn[x]+1,dfn[y],num);
}
ll QMAX(int x,int y)
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
//	freopen("P4315(2).in","r",stdin);
	memset(head,-1,sizeof(head));
	int u,v;
	ll w;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	char str[10]="";
	int ca=0;
	while(cin>>str)
	{
//		printf("操作%d:%s\n",++ca,str);
		if(str[1]=='t')//停止
			break;
		if(str[1]=='h')//改变第u条边
		{
			cin>>u>>w;
			int x=depth[e[(u<<1)-1].v]>depth[e[u<<1].v]?e[(u<<1)-1].v:e[u<<1].v;//选择该边的深节点
			modify(1,1,n,dfn[x],w);
		}
		else if(str[1]=='o')//链修改
		{
			cin>>u>>v>>w;
			MCHAIN(u,v,w);
//			printf("链覆盖被使用了！！！\n");
//			system("pause");
		}
		else if(str[1]=='d')//链增加
		{
			cin>>u>>v>>w;
			CHAINADD(u,v,w);
//			printf("u=%d,v=%d,w=%lld\n",u,v,w);
//			printf("链增加被使用了！！！\n");
//			system("pause");
		}
		else if(str[1]=='a')
		{
			cin>>u>>v;
			cout<<QMAX(u,v)<<endl;
		}
//		for(int i=1;i<=2*n;i++)
//		{
//			printf("%d:max=%lld\n",i,tree[i].Max);
//		}
	}
	return 0;
}
