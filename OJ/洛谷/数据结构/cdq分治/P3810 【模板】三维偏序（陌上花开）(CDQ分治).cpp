//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
//		for(int i=1;i<=n;i++)
//			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
struct node
{
	int a,b,c,cnt,w;//相同元素个数,当前节点答案
	node(int a=0,int b=0,int c=0):
		a(a),b(b),c(c){}
//	node(const node &y)//复制构造函数的锅,不应部分复制
//	{
//		a=y.a;
//		b=y.b;
//		c=y.c;
//	}
}s[maxn],s2[maxn];
bool cmp(const node&x,const node&y)
{
	if(x.a!=y.a)
		return x.a<y.a;
	if(x.b!=y.b)
		return x.b<y.b;
	return x.c<y.c;
}
bool cmp2(const node&x,const node&y)
{
	if(x.b!=y.b)
		return x.b<y.b;
	return x.c<y.c;
}
int ans[maxn];
void cdq(int l,int r)
{
	if(l==r)//单个元素
		return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(s+l,s+mid+1,cmp2);//左闭右开,按第二维排序
	sort(s+mid+1,s+r+1,cmp2);
	int i=mid+1,j=l;//第一维左半<右半,第二维用双指针维护
	for(;i<=r;i++)//双指针
	{//i在右半边,j在左半边,且b[j]<=b[i]
		for(;s[j].b<=s[i].b&&j<=mid;j++)
			bit.radd(s[j].c,s[j].c,s[j].cnt);//左半对右半造成的影响
		s[i].w+=bit.query(s[i].c);//节点i的权值增加
	}
	for(i=l;i<j;i++)//清空树状数组
		bit.radd(s[i].c,s[i].c,-s[i].cnt);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,tot=0;
	read(n,k);
	for(int i=1;i<=n;i++)
		read(s2[i].a,s2[i].b,s2[i].c);
	bit.build(k);
	sort(s2+1,s2+n+1,cmp);//按第一维排序
//	for(int i=1;i<=n;i++)
//		printf("a=%d,b=%d,c=%d\n",s2[i].a,s2[i].b,s2[i].c);
	for(int i=1,now=0;i<=n;i++)
	{//去重
		now++;//统计该种数量
		if(s2[i].a!=s2[i+1].a||s2[i].b!=s2[i+1].b||s2[i].c!=s2[i+1].c)
		{
			s[++tot]=s2[i];//去重
			s[tot].w=0;
			s[tot].cnt=now;
			now=0;
		}
	}
//	for(int i=1;i<=tot;i++)
//		printf("a=%d,b=%d,c=%d,w=%d,cnt=%d\n",s[i].a,s[i].b,s[i].c,s[i].w,s[i].cnt);
	cdq(1,tot);
//	printf("tot=%d\n",tot);
//	for(int i=1;i<=tot;i++)
//		printf("%d,%d,%d,%d,%d\n",s[i].a,s[i].b,s[i].c,s[i].w,s[i].cnt);
	for(int i=1;i<=tot;i++)//重复点是互相计贡献的,但不包括自己
		ans[s[i].w+s[i].cnt-1]+=s[i].cnt;
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
	return 0;
}


