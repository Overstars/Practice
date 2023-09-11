#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn];
struct node
{
	double ssum,csum;
	int lazy;
} tree[maxn<<2];
inline void pushup(int rt)
{
	tree[rt].ssum=tree[rt<<1].ssum+tree[rt<<1|1].ssum;
	tree[rt].csum=tree[rt<<1].csum+tree[rt<<1|1].csum;
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tree[rt].lazy=0;
		tree[rt].ssum=sin(a[l]);
		tree[rt].csum=cos(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
inline void update(int rt,double sinv,double cosv)
{//核心操作
	double ss=tree[rt].ssum,cc=tree[rt].csum;
	tree[rt].ssum=ss*cosv+cc*sinv;
	tree[rt].csum=cc*cosv-ss*sinv;
}
inline void pushdown(int rt)
{
	if(!tree[rt].lazy)
		return;
	double sinv=sin(tree[rt].lazy),cosv=cos(tree[rt].lazy);
	update(rt<<1,sinv,cosv);
	update(rt<<1|1,sinv,cosv);
	tree[rt<<1].lazy+=tree[rt].lazy;
	tree[rt<<1|1].lazy+=tree[rt].lazy;
	tree[rt].lazy=0;
}
void modify(int rt,int l,int r,int ml,int mr,int v)
{
	if(r<ml||l>mr)
		return;
	if(ml<=l&&r<=mr)
	{
		update(rt,sin(v),cos(v));
		tree[rt].lazy+=v;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	modify(rt<<1,l,mid,ml,mr,v);
	modify(rt<<1|1,mid+1,r,ml,mr,v);
	pushup(rt);
}
double query(int rt,int l,int r,int ql,int qr)
{
	if(r<ql||l>qr)
		return 0;
	if(ql<=l&&r<=qr)
		return tree[rt].ssum;
	pushdown(rt);
	int mid=(l+r)>>1;
	return query(rt<<1,l,mid,ql,qr)+query(rt<<1|1,mid+1,r,ql,qr);
}
signed main()
{
//	std::ios::sync_with_stdio(false),cin.Ctie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ope,l,r,v;
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	build(1,1,n);
	read(m);
	while(m--)
	{
		read(ope);
		if(ope==1)
		{
			read(l,r,v);
			modify(1,1,n,l,r,v);
		}
		else{
			read(l,r);
			printf("%.1f\n",query(1,1,n,l,r));
		}
	}
	return 0;
}


