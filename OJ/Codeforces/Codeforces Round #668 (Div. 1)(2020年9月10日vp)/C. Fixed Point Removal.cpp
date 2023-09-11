//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
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
ll ans[maxn],a[maxn];
vector<pii>rec[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]-=i;
	bit.n=n;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;//前x个和后y个锁定,无法去除
		rec[n-y].push_back(pii(x+1,i));
	}
//	printf("???\n");
	for(int r=1;r<=n;r++)
	{//枚举可修改区间右端点r,r固定时区间越长答案越大
		if(a[r]<0)//有被去掉的可能
		{
			int ll=1,rr=r-1,now=0;
			while(ll<=rr)
			{
				int mid=(ll+rr)>>1;
				if((bit.query(mid)-bit.query(mid-1))+a[r]>=0)
					ll=mid+1,now=mid;//第右可使a[r]删掉的端点
				else
					rr=mid-1;
			}
			if(now)//可以,[1,now]的操作多了一个可删除元素,更新
				bit.radd(1,now,1);
//			printf("%d:now=%d\n",r,now);
		}
		else if(a[r]==0)//[1,r]全部更新
			bit.radd(1,r,1);
		for(pii &x:rec[r])
			ans[x.ss]=bit.query(x.ff)-bit.query(x.ff-1);//单点查询l
//		for(int i=1;i<=r;i++)
//			printf("del[%d,%d]=%d\n",i,r,bit.query(i)-bit.query(i-1));
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
//	system("pause");
	return 0;
}
/*
 *先考虑暴力的做法
 *对于当前可去除元素,去除最右面的,并且更新
 *若ai-i>0则无法去掉
 *ai-i=0,一定可直接被消除
 *若ai-i<0,但是左面可消除元素>=i-ai,则也可消除ai
 *所以直接保存ai-i,删掉0时右侧可移动元素全部+1
 *
 *bit维护对于当前固定的右端点r
 *每个点l到r-1,即代表区间[l,r-1]可删元素数目
 *很明显r固定,l->r,可删数目[l,r]是逐渐递减的,单点查询
 */
