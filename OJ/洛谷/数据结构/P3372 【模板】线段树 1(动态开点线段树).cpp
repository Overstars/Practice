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
	 * 动态开点线段树,只能单点修改区间查询,能够处理零或负数位置
	 * 不需要build,用在没有提供初始数据的场合/强制在线无法离散化建树
	 * 默认初始值为0,有初始值可以单点修改
	*/
	using type = int;
	struct node
	{//
		int ls,rs;
		type val,mark;
		node(){}
		node(int l,int r,type v):
			ls(l),rs(r),val(v){mark=0;}
	} tree[maxn<<2];
	#define ls(x) tree[x].ls
	#define rs(x) tree[x].rs
	int cnt=1;
	const type NA = 0;
	static const int L=1,R=1e6;
	type pushup(type a,type b)
	{//修改之后的递归向上更新
		return a+b;
	}
	void update(int x,type d,int len)
	{//区间更新
		tree[x].val += d*len;
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
	}
	type query(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询[l,r]区间权值
		if(cl>=l&&cr<=r)
			return tree[x].val;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)//在[cl,cr]的左半区间询问
			return query(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return query(l,r,rs(x),mid+1,cr);
		return pushup(query(l,r,ls(x),cl,mid),query(l,r,rs(x),mid+1,cr));
	}
	#undef ls
	#undef rs
} t;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ope,x,y,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		t.modify(i,i,x);
	}
	while(m--)
	{
		cin>>ope;
		if(ope==1)
		{
			cin>>x>>y>>k;
			t.modify(x,y,k);
		}
		else{
			cin>>x>>y;
			cout<<t.query(x,y)<<endl;
		}
	}
	return 0;
}


