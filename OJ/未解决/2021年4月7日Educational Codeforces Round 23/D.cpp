//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
struct SegTree
{
	/*
	 * 动态开点线段树,可区间修改区间查询,能够处理零或负数位置
	 * 不需要build,用在没有提供初始数据的场合/强制在线无法离散化建树
	 * 默认初始值为0,有初始值可以单点修改
	*/
	using type = int;
	struct node
	{//
		int ls,rs;
		type val,mark,MAX;
		node(){}
		node(int l,int r,type v):
			ls(l),rs(r),val(v),MAX(v){mark=0;}
	} tree[maxn<<2];
	#define ls(x) tree[x].ls
	#define rs(x) tree[x].rs
	int cnt=1;
	const type NA = 0;
	static const int L=1,R=4e6+10;
	type pushup(type a,type b)
	{//修改之后的递归向上更新
		return a+b;
	}
	void update(int x,type d,int len)
	{//区间更新
		tree[x].val += d*len;
		tree[x].MAX += d;
		tree[x].mark += d;
	}
	void pushdown(int x,int len)
	{
		if(!ls(x))//左儿子不存在,创建新节点
			ls(x)=++cnt;
		if(!rs(x))//右儿子不存在
			rs(x)=++cnt;
		if(tree[x].mark!=NA)
		{
			update(ls(x),tree[x].mark,len/2);
			update(rs(x),tree[x].mark,len-len/2);
			tree[x].mark=NA;
		}
	}
	void assign(int l,int r,type d,int x=1,int cl=L,int cr=R)
	{//区间[l,r]推平,整体赋值为val
		if(cl>=l&&cr<=r)
		{
			tree[x].val=(cr-cl+1)*d;
			tree[x].mark=d;
			tree[x].MAX=d;
			return;
		}
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=l)
			assign(l,r,d,ls(x),cl,mid);
		if(mid<r)
			assign(l,r,d,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
	}
	void modify(int l,int r,type d,int x=1,int cl=L,int cr=R)
	{//目标区间[l,r],整体增加d,当前节点x,当前区间[cl,cr]
		if(cl>=l&&cr<=r)
			return update(x,d,cr-cl+1);//注意这个return
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=l)
			modify(l,r,d,ls(x),cl,mid);
		if(mid<r)
			modify(l,r,d,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
	}
	type querysum(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询[l,r]区间权值和,当前节点x,当前区间[cl,cr]
		if(cl>=l&&cr<=r)//询问区间被当前区间包含
			return tree[x].val;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)//在[cl,cr]的左半区间询问
			return querysum(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return querysum(l,r,rs(x),mid+1,cr);
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return pushup(querysum(l,r,ls(x),cl,mid),querysum(l,r,rs(x),mid+1,cr));
	}
	type querymax(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询区间[l,r]最大值
		if(cl>=l&&cr<=r)//[cl,cr]在询问区间内
			return tree[x].MAX;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)
			return querymax(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return querymax(l,r,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);
		return max(querymax(l,r,ls(x),cl,mid),querymax(l,r,rs(x),mid+1,cr));
	}
	type ask4firstgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询第一个>val的值的下标,当前区间[cl,cr]
		if(cl>cr||l>r)//越界
			return -1;
		if(cl==cr)//叶子
			return (tree[x].MAX>val?cl:-1);
		if(l<=cl&&cr<=r&&tree[x].MAX<=val)//该区间最值<=val,不存在
			return -1;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2,p=-1;
		if(l<=mid)//[cl,mid]与[l,r]有交集
			p=ask4firstgreat(l,r,val,ls(x),cl,mid);
		if(p==-1&&mid+1<=r)//左子树未找到,且[mid+1,cr]
			p=ask4firstgreat(l,r,val,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return p;
	}
	type ask4lastgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询最后一个>val的值的下标,当前区间[cl,cr]
		if(cl>cr||l>r)
			return -1;
		if(cl==cr)
			return (tree[x].MAX>val?cl:-1);
		if(l<=cl&&cr<=r&&tree[x].MAX<=val)//该区间最值<=val,不存在
			return -1;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2,p=-1;
		if(mid+1<=r)
			p=ask4lastgreat(l,r,val,rs(x),mid+1,cr);
		if(p==-1&&l<=mid)
			p=ask4lastgreat(l,r,val,ls(x),cl,mid);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return p;
	}
	#undef ls
	#undef rs
} T,T2;
int a[maxn],stk[maxn],l[maxn],r[maxn],top=0;
int f[maxn],ml[maxn],mr[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+i;
		cin>>a[i];
		mr[i]=r[i]=n;
		ml[i]=l[i]=1;
	}
	for(int i=1;i<=n;i++)
		T.modify(i,i,a[i]);
	int ans=0;
	map<int,int>vis;
	for(int i=1;i<=n;i++)
	{//求作为最大值控制范围
		if(vis[a[i]]>=i)
			continue;
		int nl=T.ask4lastgreat(1,i-1,a[i]);
		int nr=T.ask4firstgreat(i+1,n,a[i]);
		if(nl==-1)//比这一个区间都大
			nl=1;
		else
			nl++;
		if(nr==-1)
			nr=n;
		else
			nr--;
		vis[a[i]]=nr;
		ans+=a[i]*f[nr-nl];
//		printf("[%d,%d] ans = %d\n",nl,nr,ans);
	}
	vis.clear();
//	T.assign(1,n,0);
	for(int i=1;i<=n;i++)
		T2.modify(i,i,-a[i]);
//	for(int i=1;i<=n;i++)
//	{
//		printf("T2[%d] = %d\n",i,T2.querysum(i,i));
//		printf("%d\n",T2.querymax(i,i));
//	}
//	cerr<<"wtf"<<endl;
	for(int i=1;i<=n;i++)
	{//作为最小值控制范围
		if(vis[-a[i]]>=i)
			continue;
		int nl=T2.ask4lastgreat(1,i-1,-a[i]);
		int nr=T2.ask4firstgreat(i+1,n,-a[i]);
//		printf("l=%d,R=%d\n",nl,nr);
		if(nl==-1)//
			nl=1;
		else
			nl++;
		if(nr==-1)
			nr=n;
		else
			nr--;
		vis[-a[i]]=nr;
//		printf("%d:[%d,%d] ans = %d\n",i,nl,nr,ans);
		ans-=a[i]*f[nr-nl];
	}
//	for(int i=1;i<=n;i++)
//	{//求最大值,单调栈单调递增
//		while(top&&a[stk[top]]<=a[i])
//		{
//			mr[stk[top]]=i-1;
//			top--;
//		}
//		if(top)
//			ml[i]=stk[top]+1;
//		stk[++top]=i;
//	}
//	top=0;
//	for(int i=1;i<=n;i++)
//	{//作为最小值,单调递减的单调栈
//		while(top&&a[stk[top]]>=a[i])
//		{
//			r[stk[top]]=i-1;
//			top--;
//		}
//		if(top)
//			l[i]=stk[top]+1;
//		stk[++top]=i;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("l=%d,r=%d\n",l[i],r[i]);
//		printf("ml=%d,mr=%d\n",ml[i],mr[i]);
//		ans+=a[i]*(f[mr[i]-ml[i]]-f[r[i]-l[i]]);
//		cerr<<"ans = "<<ans<<endl;
//	}
	cout<<ans<<endl;
	return 0;
}
/*
 *2021-04-07-16.47.05
 *单调栈求a[i]作为最值的范围
*/

