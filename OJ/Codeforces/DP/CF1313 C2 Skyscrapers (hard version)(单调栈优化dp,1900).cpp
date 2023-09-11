//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int h[maxn],l[maxn],r[maxn];
int stk[maxn],top;
int dp[maxn],dp2[maxn];
int b[maxn];
void build(int ans,int p,int n)
{
	b[p]=h[p];
	for(int i=p+1,lim=h[p];i<=n;i++)
	{
		lim=min(lim,h[i]);
		b[i]=lim;
	}
	for(int i=p-1,lim=h[p];i>=1;i--)
	{
		lim=min(lim,h[i]);
		b[i]=lim;
	}
}
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
		cin>>h[i],l[i]=0,r[i]=n+1;
	for(int i=1;i<=n;i++)
	{//求出第一个<=h[i]的位置,维护单调递增的单调栈
		while(top&&h[stk[top]]>h[i])
			top--;
		dp[i]=dp[stk[top]]+(i-stk[top])*h[i];
		stk[++top]=i;
	}
	top=0;
	stk[++top]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&h[stk[top]]>h[i])
			top--;
		dp2[i]=dp2[stk[top]]+(stk[top]-i)*h[i];
		stk[++top]=i;
//		fprintf(stderr,"%d:[%d,%d]\n",i,l[i],r[i]);
	}
	int ans=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		int val=dp[i]+dp2[i]-h[i];
		if(val>ans)
		{
			ans=val;
			pos=i;
		}
	}
	build(ans,pos,n);
	for(int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	return 0;
}
/*
 * 2021-04-19-12.38.44
 * 简单版本大概枚举一下峰顶就好了,n^2
 * 这个版本可能要分别处理前后缀
 * 利用单调不减的特性
 * 需要:快速定位区间第一个>x的位置,并且区间推平,支持区间求和
 * 以上可以通过线段树来解决...然而不太想改,精神污染
 * 思考单调栈的做法
 * 通过单调栈可以求出左右第一个≤h[i]的位置
 * dp[i]=dp[j]+h[i]*(i-j),j是第一个h[j]<=h[i]位置
 * 因为贪心可以发现i-j越大越好,但是越过h[j]就不能建这么高
*/

