//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
struct node
{
	int x,h;
	node(){}
	node(int x,int h):
		x(x),h(h){}
	bool operator <(const node &y)const
	{
		return x<y.x;
	}
} a[maxn];
int n,d,q[maxn],head=1,tail=0;
bool f[maxn],f2[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].h;
	sort(a+1,a+n+1);
	head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&a[q[tail]].h<=a[i].h)
			tail--;
		while(head<=tail&&a[q[head]].x+d<a[i].x)
			head++;
		q[++tail]=i;
//		printf("a[%d]=%d->a[%d]=%d\n",i,a[i].h,q[head],a[q[head]].h);
		if(a[q[head]].h>=a[i].h*2)
			f[i]=1;
	}
	head=1,tail=0;
	for(int i=n;i>=1;i--)
	{
		while(head<=tail&&a[q[tail]].h<=a[i].h)
			tail--;
		while(head<=tail&&a[q[head]].x-d>a[i].x)
			head++;
		q[++tail]=i;
//		printf("a[%d]=%d->a[%d]=%d\n",i,a[i].h,q[head],a[q[head]].h);
		if(a[q[head]].h>=a[i].h*2)
			f2[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(f[i]&&f2[i])
			ans++;
	cout<<ans<<endl;
	return 0;
}
/*
 *注意是左且右而不是或
 *分别跑两边单调队列
 *都维护一个单调递减的单调队列
*/

