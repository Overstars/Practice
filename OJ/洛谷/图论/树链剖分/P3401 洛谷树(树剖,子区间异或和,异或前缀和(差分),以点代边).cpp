#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30005;
int n,tot=0,head[maxn],val[maxn];
struct edge
{
	int v,w,nex;
} e[maxn<<1];
inline void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot;
}
int depth[maxn],siz[maxn],father[maxn],son[maxn],eval[maxn];
void dfs1(int x,int fa)
{//得到每个节点深度
	depth[x]=depth[fa]+1;
	father[x]=fa;
	siz[x]=1;
	int maxsiz=-1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		val[v]=val[x]^e[i].w;//以点代边,异或前缀和
		eval[v]=e[i].w;//记录该点的值,方便修改
		dfs1(v,x);
		siz[x]+=siz[v];
		if(maxsiz<siz[v])
		{
			son[x]=v;
			maxsiz=siz[v];
		}
	}
}
int tim,dfn[maxn],top[maxn],w[maxn];//以点代边
void dfs2(int x,int t)
{
	dfn[x]=++tim;
	top[x]=t;
	w[tim]=val[x];//对应dfn权值(前缀差分),由线段树维护
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];~i;i=e[i].nex)
		if(e[i].v!=father[x]&&e[i].v!=son[x])
			dfs2(e[i].v,e[i].v);
}
struct node
{
	int cnt0,cnt1,rev;
	node(){}
	node(int a,int b,int c):
		cnt0(a),cnt1(b),rev(c){}
	node operator +(const node &y)
	{
		node tem;
		tem.cnt0=cnt0+y.cnt0;
		tem.cnt1=cnt1+y.cnt1;
		tem.rev=0;
		return tem;
	}
} tree[12][maxn<<2];//开12棵线段树维护不同位
inline void pushup(int k,int root)
{
	tree[k][root]=tree[k][root<<1]+tree[k][root<<1|1];
}
void build(int k,int root,int l,int r)
{
	if(l==r)
	{
		if((w[l]>>k)&1)
			tree[k][root].cnt1=1;
		else
			tree[k][root].cnt0=1;
		return;
	}
	else{
		int mid=(l+r)>>1;
		build(k,root<<1,l,mid);
		build(k,root<<1|1,mid+1,r);
		pushup(k,root);
	}
}
inline void pushdown(int k,int root,int l,int r)
{
	if(tree[k][root].rev)//反转子区间第k位
	{
		swap(tree[k][root<<1].cnt0,tree[k][root<<1].cnt1);
		swap(tree[k][root<<1|1].cnt0,tree[k][root<<1|1].cnt1);
		tree[k][root<<1].rev^=1;
		tree[k][root<<1|1].rev^=1;
		tree[k][root].rev=0;
	}
}
void rev(int k,int root,int nst,int ned,int ust,int ued)
{
	if(ned<ust||ued<nst)
		return;
	if(ust<=nst&&ued>=ned)
	{
		swap(tree[k][root].cnt0,tree[k][root].cnt1);
		tree[k][root].rev^=1;
		return;
	}
	pushdown(k,root,nst,ned);
	int mid=(nst+ned)>>1;
	rev(k,root<<1,nst,mid,ust,ued);
	rev(k,root<<1|1,mid+1,ned,ust,ued);
	pushup(k,root);
}
void change(int x,int num)//检查一整棵子树上哪些位要翻转
{
	for(int i=0;i<11;i++)
		if(((num^eval[x])>>i)&1)//反转变动的那几位
			rev(i,1,1,n,dfn[x],dfn[x]+siz[x]-1);
	eval[x]=num;//记录权值
}
node query(int k,int root,int nst,int ned,int qst,int qed)
{
	if(nst>qed||qst>ned)
		return node(0,0,0);
	if(qst<=nst&&ned<=qed)
	{
		return tree[k][root];
	}
	pushdown(k,root,nst,ned);
	int mid=(nst+ned)>>1;
	return query(k,root<<1,nst,mid,qst,qed)+query(k,root<<1|1,mid+1,ned,qst,qed);
}
ll qchain(int x,int y)
{
	ll ans=0;
	for(int i=0;i<11;i++)//由低到高求出每一位
	{
		int u=x,v=y;
		node tem(0,0,0);//记录该链上i位出现0和1的次数
		while(top[u]!=top[v])
		{
			if(depth[top[u]]<depth[top[v]])
				swap(u,v);
			tem=tem+query(i,1,1,n,dfn[top[u]],dfn[u]);
			u=father[top[u]];
		}
		if(depth[u]>depth[v])
			swap(u,v);
		tem=tem+query(i,1,1,n,dfn[u],dfn[v]);
		ans+=(1ll<<i)*tem.cnt0*tem.cnt1;//一个区间所有子区间异或和可以看成该区间上每一位单独计算0个数*1个数
	}
	return ans;
}
int main()
{
	memset(head,-1,sizeof(head));
	int q,u,v,w;
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dfs1(1,1);
	dfs2(1,1);
	for(int i=0;i<11;i++)
		build(i,1,1,n);
	while(q--)
	{
		int ope;
		cin>>ope;
		if(ope==1)
		{
			cin>>u>>v;
			cout<<qchain(u,v)<<'\n';
		}
		else{
			cin>>u>>v>>w;
			if(father[u]!=v)
				swap(u,v);
			change(u,w);
		}
	}
	return 0;
}
/*
 *求路径上所有*子路径上所有边异或值*的和
 *要支持边权修改与路径值查询
 *以点代边
 *理论依据：
 *任何数与自身异或为0，与0异或为自身
 *DFS预处理出当前节点到根的前缀异或和pre[i]
 *所以，pre[i]^pre[j]即为i到j的异或
 *防止TLE
 *开10棵线段树维护每一位1和0的个数
 */
