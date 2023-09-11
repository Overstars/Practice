//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
vector<int> v;
struct node
{//左右子树节点编号,区间上数量为sum
	int l,r,sum;
} hjt[maxn<<5];
inline int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[maxn],cnt,root[maxn];//内存值计数器,root[i]为根节点编号(在之前基础上插入a[i]的树)
void Insert(int l,int r,int pre,int &now,int p)//p为新加入权值(也为位置)
{//对离散化后范围[l,r]建树,pre:上一个版本的编号,now:当前版本的编号
	//找到新加入权值对应节点,更新该节点信息
	hjt[++cnt]=hjt[pre];//动态开点:上一个版本对应位置节点复制一份,新树中添加lgn个节点
	now=cnt;//当前节点编号等于新分配
	hjt[now].sum++;//插入,数量++,维护离散化后值域[l,r]上的个数
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)//插入到左子树
		Insert(l,mid,hjt[pre].l,hjt[now].l,p);
	else//插入到右子树上
		Insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
}
int rnkk(int l,int r,int L,int R,int k)
{//[l,r]:离散化后查询范围,L/R:树的版本编号
	if(l==r)//叶子节点,rkk就是这个权值
		return l;
	int mid=(l+r)>>1;
	/*
	 前缀和思想,求出[1,r]的数量
	 用r版本减去l-1版本的同一区间信息,得到指定查询区域[l,r]的线段树
	 */
	//新减出来的差值树上,左子树数值
	int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;//
	if(k<=tmp)//第k大在左子树上
		rnkk(l,mid,hjt[L].l,hjt[R].l,k);
	else
		rnkk(mid+1,r,hjt[L].r,hjt[R].r,k-tmp);
}//v[rnkk(1,v.size(),root[l-1],root[r],k)-1]即为[l,r]第k大
int query(int l,int r,int now,int L,int R)
{//求出该版本树上[L,R]值域上元素数目,[l,r]为当前节点控制值域
	if(r<L||l>R)
		return 0;
	if(L<=l&&r<=R)
		return hjt[now].sum;
	int mid=(l+r)>>1;
	return query(l,mid,hjt[now].l,L,R)+query(mid+1,r,hjt[now].r,L,R);
}
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
		cin>>a[i];
		v.push_back(a[i]);
		v.push_back(i);//这题下标也加进去离散化
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
//	for(int i=1;i<=n;i++)//思想:保存插入时的历史版本,对每个前缀建树(n棵)
//		Insert(1,v.size(),root[i-1],root[i],getid(a[i]));
	ll ans=0;
//	Insert(1,v.size(),root[n+2],root[n+1],0);
	for(int i=n;i>=1;i--)
	{//倒序表示一维,i离散化后还是i
		int st=i,ed=min(n,getid(a[i]));
		Insert(1,v.size(),root[i+1],root[i],ed);
		if(ed>st)//a[i]<=i时无解
		{
			printf("x=%d,st=%d,ed=%d\n",i,st,ed);
			printf("now=%d-%d\n",query(1,v.size(),root[i],i+1,v.size()),query(1,v.size(),root[ed+1],i+1,v.size()));
			ans+=query(1,v.size(),root[i],i+1,v.size())-query(1,v.size(),root[ed+1],i+1,v.size());
		}
	}//[i+1,a[i]]值域上
	cout<<ans<<endl;
	return 0;
}
/*
 *求<i,j>,使a[i]>=j且a[j]<=i的对数
 *第一眼以为二维偏序
 *然后发现元素位置固定,不能cdq
 *对于每一个i,求在j∈[i+1,ai]上aj≥i的数目
 */

