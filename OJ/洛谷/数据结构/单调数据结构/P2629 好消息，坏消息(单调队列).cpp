//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],sum[maxn];
int q[maxn],head=1,tail=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		sum[n+i]=sum[n+i-1]+a[i];
//	for(int i=1;i<=n;i++)//
//		sum[n+i]-=sum[i];
	for(int i=1;i<=2*n;i++)
	{//[i-n+1,i]的最小值,此时值减去sum[i-n]
		while(head<=tail&&sum[q[tail]]>=sum[i])
			tail--;
		q[++tail]=i;
		while(head<=tail&&q[head]<=i-n)
			head++;
		if(i>=n+1&&sum[q[head]]-sum[i-n]>=0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *n个数排成一个环,你要选择一个起点
 *从这个起点开始的前缀和不出现负数
 *统计起点的数量
 *断环为链,O(n)枚举查询区间最小值
 *单调队列统计[n+1,2n]长度为n的区间最小值
 *维护一个单调递增的队列
*/

