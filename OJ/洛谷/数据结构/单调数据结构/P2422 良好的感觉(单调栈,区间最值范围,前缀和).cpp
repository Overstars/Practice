//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
int a[maxn],sum[maxn],l[maxn],r[maxn];
int stk[maxn],top;
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
		r[i]=n;
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]]>=a[i])
		{
			r[stk[top]]=i-1;
			top--;
		}
		l[i]=stk[top]+1;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)
	{
//		printf("a[%d]=%d,l=%d,r=%d\n",i,a[i],l[i],r[i]);
		ans=max(ans,a[i]*(sum[r[i]]-sum[l[i]-1]));
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *区间最小值*区间和
 *求上面这个的最大值
 *在区间最小值不减小的情况下尽量扩大区间
 *维护一个单调递增的单调栈,求a[i]作为区间极值的范围
 *在前缀和上求出
*/

