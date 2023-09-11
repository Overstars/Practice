#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
struct node
{
	ll val;//维护区间数量
} tree[maxn<<2];
inline void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
}
char s[maxn];
void build(int root,int l,int r)
{
	if(l==r)
	{
		if(s[l]=='1')
			tree[root].val=1;
		else
			tree[root].val=0;
		return;
	}
	int mid=l+r>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
void update(int root,int nst,int ned,int p,ll num)
{
	if(p<nst||p>ned)
		return;
	if(nst==ned&&nst==p)
	{
		tree[root].val=num;
		return;
	}
	int mid=nst+ned>>1;
	if(p<=mid)
		update(root<<1,nst,mid,p,num);
	else
		update(root<<1|1,mid+1,ned,p,num);
	pushup(root);
}
ll query(int root,int nst,int ned,int qst,int qed)
{
	if(qst>ned||nst>qed)
		return 0;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].val;
	}
	int mid=nst+ned>>1;
	return query(root<<1,nst,mid,qst,qed)+query(root<<1|1,mid+1,ned,qst,qed);
}
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn];
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(ll *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=this->n;i++)
		{
			add(i,a[i]);
		}
	}
	void add(int k,int num)//修改:a[k]加上num,直接在c数组上操作
	{
		while(k<=this->n)
		{
			c[k]=(c[k]+num)%mod;
			k+=lowbit(k);
		}
	}
	void range_update(int l, int r, int val)//区间更新
	{
		add(l, val);//把l之后所有的点都更新一遍
		add(r + 1, -val);//因为r之后的点是不用更新的，但是多更新了，所以要每个点都-val；
	}
	ll read(int k)//查询:1~k的区间和
	{
		ll sum=0;
		while(k)
		{
			sum=(sum+c[k])%mod;
			k-=lowbit(k);
		}
		return sum;
	}
} bit,bit2;
ll a[maxn],a2[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,q,p,ans=0;
	cin>>n>>s+1;
	for(ll i=1,tot=0,sum=0;i<=n;i++)
	{
		sum=(sum+tot)%mod;
		if(s[i]=='1')
		{
			a[i]=i;
			a2[i]=n-i+1;//到n距离
			ans=(ans+sum)%mod;
			tot++;
		}
	}
	cout<<ans<<'\n';
	build(1,1,n);
	bit.build(a,n);
	bit2.build(a2,n);
	cin>>m;
	while(m--)
	{
		cin>>q>>p;
		ll l=query(1,1,n,1,p-1),r=query(1,1,n,p+1,n);//左右LINK数量
		ll L=bit.read(p-1)%mod,R=(bit2.read(n)-bit2.read(p)+mod)%mod;//p左面点到1距离和,p右面点到n的距离和
		ll chan=0;//改变的值
		if(q==1)//加入
		{
			chan+=((l*p%mod-L+mod)%mod+((n-p+1)*r%mod-R+mod)%mod)%mod;
			update(1,1,n,p,1);//
			bit.add(p,p);
			bit2.add(p,n-p+1);
		}
		else{
			chan-=((l*p%mod-L+mod)%mod+((n-p+1)*r%mod-R+mod)%mod)%mod;
			update(1,1,n,p,0);
			bit.add(p,-p);
			bit2.add(p,-(n-p+1));
		}
		ans=(ans+chan)%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
