//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
	using type = long long;
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
	static const int L=1,R=2e5+10;
	type pushup(type a,type b)
	{//修改之后的递归向上更新
		return a+b;
	}
	void update(int x,type d,int len)
	{//区间更新
		tree[x].val += d*len;
		tree[x].MAX += d*len;
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
		return pushup(querysum(l,r,ls(x),cl,mid),querysum(l,r,rs(x),mid+1,cr));
	}
	type querymax(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询区间[l,r]最大值
		if(cl>=l&&cr<=r)
			return tree[x].MAX;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)
			return querymax(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return querymax(l,r,rs(x),mid+1,cr);
		return max(querymax(l,r,ls(x),cl,mid),querymax(l,r,rs(x),mid+1,cr));
	}
	type ask4firstgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询第一个>val的值的下标,当前区间[cl,cr]
		if(cl==cr)
			return (tree[x].MAX>val?cl:-1);
		if(cl<=l&&r<=cr)//该区间最值<=val,不存在
			if(tree[x].MAX<=val)
				return -1;
		int mid=(cl+cr-1)>>1;
		if(mid>=r)//在左子树
			return ask4firstgreat(l,r,val,ls(x),cl,mid);
		else if(mid<l)
			return ask4firstgreat(l,r,val,rs(x),mid+1,cr);
		int p=ask4firstgreat(l,r,val,ls(x),cl,mid);//优先左子树
		if(p!=-1)
			return p;
		return ask4firstgreat(l,r,val,rs(x),mid+1,cr);//没有则在右子树
	}
	type ask4lastgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询最后一个>val的值的下标,当前区间[cl,cr]
		if(cl==cr)
			return (tree[x].MAX>val?cl:-1);
		if(cl<=l&&r<=cr)//该区间最值<=val,不存在
			if(tree[x].MAX<=val)
				return -1;
		int mid=(cl+cr-1)>>1;
		if(mid>=r)//在左子树
			return ask4lastgreat(l,r,val,ls(x),cl,mid);
		else if(mid<l)//右子树
			return ask4lastgreat(l,r,val,rs(x),mid+1,cr);
		int p=ask4lastgreat(l,r,val,rs(x),mid+1,cr);//优先右子树
		if(p!=-1)
			return p;
		return ask4lastgreat(l,r,val,ls(x),cl,mid);//没有则在左子树
	}
	#undef ls
	#undef rs
} t;
int c[maxn];
vector<int>rec[4],sum[4];
int get(int x,int y)
{

}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	t.modify(0,0,2);
	t.modify(1,1,1);
	cerr<<"wtf = "<<t.ask4firstgreat(0,0,1)<<endl;
	int n,m,k,x,y,tmp;
	map<int,int>a,b;
//	vector<int>a,b;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cin>>x;
	for(int i=1;i<=x;i++)
	{//a喜欢的
		cin>>tmp;
		a[tmp]=1;
//		a.push_back(tmp);
	}
	cin>>y;
	for(int i=1;i<=y;i++)
	{//b喜欢的
		cin>>tmp;
		b[tmp]=1;
//		b.push_back(tmp);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]&&b[i])
			rec[0].push_back(i);
		else if(a[i])
			rec[1].push_back(i);
		else if(b[i])
			rec[2].push_back(i);
		else
			rec[3].push_back(i);
	}
	for(int i=0;i<4;i++)
	sort(rec[i].begin(),rec[i].end(),[](const int &x,const int &y){
			return c[x]<c[y];
		});
	#
	int ans=inf;
	for(int i=0,val=0;i<=k;i++)
	{

	}
	cout<<ans<<endl;
	return 0;
}
/*
 *选择m个材料,每个人至少有k个喜欢的
 *求出最小花费
 *分成四部分,在第0部分选择d个,就要在第1部分和第2部分选择至少k-d个
 *剩下的再按花费考虑
*/

