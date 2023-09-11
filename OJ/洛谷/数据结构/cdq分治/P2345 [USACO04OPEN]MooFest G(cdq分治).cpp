//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e4+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct node
{
	int v,w;
	node(){};
	node(int v,int w):
		v(v),w(w){}
} a[maxn];
ll ans;
bool cmp(const node &x,const node &y)
{
	return x.w<y.w;
}
void cdq(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(a+l,a+mid+1,cmp);
	sort(a+mid+1,a+r+1,cmp);
	ll sum=0,sum2=0;//1统计前半段的w和
	for(int i=l;i<=mid;i++)
		sum+=a[i].w;//sum为比i大的w的和
	for(int i=mid+1,j=l;i<=r;i++)
	{
		for(;a[j].w<a[i].w&&j<=mid;j++)
			sum-=a[j].w,sum2+=a[j].w;
		int p=mid-l+1,cnt=j-l;//总对数,左边w小于i的个数
		ans+=a[i].v*(a[i].w*(2*cnt-p)+sum-sum2);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].v>>a[i].w;
	sort(a+1,a+n+1,[](const node&x,const node&y){//按v从小到大排序
			if(x.v!=y.v)
				return x.v<y.v;
			return x.w>y.w;
		});
	cdq(1,n);
	cout<<ans<<endl;
	return 0;
}


