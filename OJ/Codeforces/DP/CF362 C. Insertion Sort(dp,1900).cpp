//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5050,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn]={0,1,5,4,2,3};
void bsort(int a[],int n)
{
	for(int i=1;i<=n;i++)
		for(int j=i;j>=2;j--)
			if(a[j-1]>a[j])
				swap(a[j-1],a[j]);
}
int tmp[maxn],sum=0;
void msort(int a[],int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1,p1=l,p2=mid+1;
	msort(a,l,mid);
	msort(a,mid+1,r);
	for(int i=l;i<=r;i++)
	{
		if((p1<=mid&&a[p1]<=a[p2])||p2>r)
			tmp[i]=a[p1++];
		else{//a[p1]比后面这部分元素大
			tmp[i]=a[p2++];
			sum+=mid-p1+1;//a[p2]比[p1,mid]这一段都小
		}
	}
	for(int i=l;i<=r;i++)
		a[i]=tmp[i];
}
vector<int> vv;
inline int getid(int x)
{
	return lower_bound(vv.begin(),vv.end(),x)-vv.begin()+1;
}
struct node
{//左右子树节点编号,区间上数量为sum
	int l,r,sum;
} hjt[maxn<<5];
int cnt,root[maxn];//内存值计数器,root[i]为根节点编号(在之前基础上插入a[i]的树)
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
int query(int l,int r,int L,int R,int k)
{//[l,r]:离散化后查询范围,L/R:树的版本编号
	if(l==r)//叶子节点
		return l;
	int mid=(l+r)>>1;
	/*
	 前缀和思想,求出[1,r]的数量
	 用r版本减去l-1版本的同一区间信息,得到指定查询区域[l,r]的线段树
	 */
	//新减出来的差值树上,左子树数值
	int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;//
	if(k<=tmp)//第k大在左子树上
		query(l,mid,hjt[L].l,hjt[R].l,k);
	else
		query(mid+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
int getrk(int L,int R,int x,int n)
{//比x小的数目
	int ans=0,l=1,r=R-L+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(vv[query(1,n,root[L-1],root[R],mid)-1]<x)
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,p1=0,p2=0,inc=inf,cnt=0;
	read(n);
//	cin>>n;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		a[i]++;
//		cin>>a[i];
		vv.push_back(a[i]);
	}
	#ifndef wtf
	for(int i=1;i<n;i++)
	{
		bit.build(n);
//		memset(c,0,sizeof(c));//存着<a[i]的数
		int now2=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])//i,j本身减少一个逆序对
			{
				sum++;//查询[i+1,j-1]上有多少个小于a[j]的,交换后会增加
//				int sub=1+query(a[j],n)-(r-l+1-query(a[j],n))-query(n,n)+(r-l+1-query(n,n));//逆序对增加
//				int now=2*query(a[j],n)-2*now2-1;//增加的值
//				int now=-1+query(a[j],n)-(j-i-1-query(a[j],n))-now2+(j-i-1-now2);
				int now=-1+2*bit.query(a[j])-2*now2;
//				cerr<<"["<<i<<","<<j<<"] = "<<now<<endl;
				if(now<inc)
				{
					inc=now;
					cnt=1;
				}
				else if(now==inc)
					cnt++;
				bit.radd(a[j],a[j],1);
//				printf("wtf!\n");
//				modify(a[j],1);
				now2++;
			}
		}
	}
	#else
	sort(vv.begin(),vv.end());
	for(int i=1;i<=n;i++)//维护离散化后的值域上个数
	{//思想:保存插入时的历史版本,对每个前缀建树(n棵)
		Insert(1,vv.size(),root[i-1],root[i],getid(a[i]));
	}//第i棵存储前i个值出现次数
//	bsort(a,5);
//	for(int i=1;i<=5;i++)
//		cout<<a[i]<<' ';
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int len=j-i-1;
			int d1=getrk(i+1,j-1,a[i],n),c2=getrk(i+1,j-1,a[j],n);
			int now=2*c2-2*d1;
			if(a[i]>a[j])
				now--;
			else
				now++;
//			cerr<<"["<<i<<","<<j<<"] = "<<now<<endl;
			if(now<inc)
			{
				inc=now;
				p1=i,p2=j;
				cnt=1;
			}
			else if(now==inc)
				cnt++;
		}
	msort(a,1,n);
	#endif // wtf
	if(inc==inf)
		inc=0;
	cout<<inc+sum<<' '<<cnt<<'\n';
//	cout<<p1<<' '<<p2<<endl;
	return 0;
}
/*
 *交换两个数的位置使得冒泡排序次数最少
 *枚举交换的点对(l,r),求逆序对
 *[1,l],[l,r],[r,n]
 *只有中间的区间会受到影响
 *增加[l,r]区间内>a[l]的数,减去<a[l]的数,加上<a[r]的数,减去>a[r]的数
 *预处理[1,i]<x的数
*/

