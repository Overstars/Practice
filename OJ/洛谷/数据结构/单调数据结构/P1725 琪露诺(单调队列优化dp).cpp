///*
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
//struct node
//{
//	int val,pos;
//	node(){}
//	node(int a,int b):
//		val(a),pos(b){}
//} q[maxn];
int a[maxn],dp[maxn];//dp[i]表示在i处的最大值
int q[maxn],head=0,tail=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,l,r,ans=-inf;
	cin>>n>>l>>r;
	for(int i=0;i<=n;i++)
		cin>>a[i],dp[i]=-inf;
	dp[0]=0;
	for(int i=l;i<=n;i++)
	{//
		while(head<=tail&&dp[q[tail]]<=dp[i-l])//将最后一个可以跳到i的位置插入
			tail--;
		q[++tail]=i-l;
		while(head<=tail&&q[head]+r<i)//不能再到i了
			head++;
		dp[i]=dp[q[head]]+a[i];
	}
	for(int i=n-r+1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
/*
 *队列单调递减
 *维护一个区间最大值,用单调队列
*/

