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
int a[maxn],ans[maxn];
int stk[maxn],top=0,l[maxn],r[maxn];
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
		cin>>a[i],r[i]=n;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]]>=a[i])
		{
			r[stk[top]]=i-1;//确定栈顶的右端点
			top--;
		}
		l[i]=stk[top]+1;//栈顶元素小于a[i],[stk[top]+1,
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)
	{
//		printf("a[%d]=%d,[%d,%d]\n",i,a[i],l[i],r[i]);
		int len=r[i]-l[i]+1;
		ans[len]=max(ans[len],a[i]);
	}
	for(int i=n-1;i>=1;i--)
		ans[i]=max(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
 *n个小熊站成一排,每个都有一个高度ai。
 *对于一个区间[L,R],定义该区间的strength值为:该区间的最小值。
 *对于相同长度的区间strength值中的最大值为多少
 *从len=1开始输出。肯定是单调递减的
 *求所有k长区间最大最小值
 *应该是维护最小值,弹出时根据长度更新答案
 *维护一个单调递增的栈
 *http://codeforces.com/contest/547/problem/B
*/

