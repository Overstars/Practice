//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],q[maxn],head,tail=1;
int sum[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,ans=-inf;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&sum[q[tail]]>=sum[i-1])
			tail--;
		while(head<=tail&&i-q[head]>=m)
			head++;
		q[++tail]=i-1;
		if(head<=tail)
			ans=max(ans,sum[i]-sum[q[head]]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *乍一看似乎前缀和枚举m长度,但事实上可以比m块少
 *还有负数,并不是单调递增的
 *在前缀和上进行操作,sum[i]-sum[j]
 *很明显sum[i]越大,sum[j]越小越好
 *枚举区间右端点,维护一个单调递增的队列
*/

