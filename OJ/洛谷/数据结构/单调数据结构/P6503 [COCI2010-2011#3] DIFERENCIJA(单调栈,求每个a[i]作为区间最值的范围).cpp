//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],n,l[maxn],r[maxn];
int stk[maxn],top=0;
ll get()
{//获得所有段最大值之和,维护一个单调递增的栈
	for(int i=1;i<=n;i++)
		l[i]=0,r[i]=n;
	top=0;
	ll ret=0,now=0;//
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]]<a[i])
		{//[栈顶,i]可以用a[i]表示
			r[stk[top]]=i-1;//得到stk[top]的右边界i-1,[stk[top],i-1]
//			ret+=(i-stk[top])*a[stk[top]];
			top--;
		}
		l[i]=stk[top]+1;//得到i的左边界[stk[top]+1,i]
//		ret+=(i-stk[top])*a[i];//[stk[top]+1,i]都可以用a[i]表示
		stk[++top]=i;//作为左边界
	}
	for(int i=1;i<=n;i++)
		ret+=a[i]*(i-l[i]+1)*(r[i]-i+1);
	return ret;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=get();
	for(int i=1;i<=n;i++)
		a[i]*=-1;
	cout<<ans+get()<<endl;
	return 0;
}
/*
 *定义一个子序列的权值为序列内最大值与最小值的差。
 *求出所有连续子序列的权值和。
 *求最大最小和可以分开求
 *求max和,维护一个单调递减的单调栈,按段计算贡献
 *https://www.luogu.com.cn/blog/_post/310636
 *上面这个看不懂
*/

