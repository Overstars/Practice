//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int h[maxn],v[maxn],a[maxn];
int stk[maxn],top=0;
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
		cin>>h[i]>>v[i];//高度,能量值
	for(int i=1;i<=n;i++)
	{
		while(top&&h[stk[top]]<=h[i])
			top--;
		if(top)
			a[stk[top]]+=v[i];
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&h[stk[top]]<=h[i])
			top--;
		if(top)
			a[stk[top]]+=v[i];
		stk[++top]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,a[i]);
	cout<<ans<<endl;
	return 0;
}
/*
 *寻找左右第一个高度大于h[i]的,维护一个单调递减的单调栈
 *从左向右扫,找到左面第一个,即为向左发射的
*/

