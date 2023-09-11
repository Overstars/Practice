//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
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
int a[maxn],stk[maxn],stk2[maxn],l[maxn],r[maxn],top=0,top2=0;
int f[maxn],ml[maxn],mr[maxn];
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
		f[i]=f[i-1]+i;
		cin>>a[i];
		mr[i]=r[i]=n;
		ml[i]=l[i]=1;
	}
	for(int i=1;i<=n;i++)
	{//求最大值,单调栈单调递增
		while(top&&a[stk[top]]<=a[i])
		{
			mr[stk[top]]=i-1;
			top--;
		}
		if(top)
			ml[i]=stk[top]+1;
		stk[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++)
	{//作为最小值,单调递减的单调栈
		while(top&&a[stk[top]]>=a[i])
		{
			r[stk[top]]=i-1;
			top--;
		}
		if(top)
			l[i]=stk[top]+1;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]*(i-ml[i]+1)*(mr[i]-i+1);
		ans-=a[i]*(i-l[i]+1)*(r[i]-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *2021-04-07-16.47.05
 *单调栈求a[i]作为最值的范围
*/

