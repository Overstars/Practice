//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e7+10,inf=0x3f3f3f3f,mod=1000000007;
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
int Seed;
inline int rnd () {
	static const int MOD = 1e9;
	return Seed = ( 1LL * Seed * 0x66CCFF % MOD + 20120712 ) % MOD;
}
int a[maxn],dp[maxn],q[maxn],head=1,tail=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,d,x,tp;
	cin>>n>>k>>d>>x>>tp;
	if(tp){
		cin>>Seed;
		for(int i=1;i<=n;i++)
			a[i]=rnd();
	}
	else{
		for(int i=1;i<=n;i++)
			cin>>a[i];
	}
	dp[1]=a[1];
	q[++tail]=1;
	for(int i=2;i<=n;i++)
	{
		while(head<=tail&&i>q[head]+x)
			head++;
		while(head<=tail&&dp[q[tail]]+d*(i-q[tail]-1)>=dp[i-1])
			tail--;
		q[++tail]=i-1;
		dp[i]=dp[q[head]]+d*(i-q[head]-1)+a[i]+k;
	}
	cout<<dp[n]<<endl;
	return 0;
}
/*
 *n个数a1~an,从左向右挨个取,每移动一次+k
 *可以采用瞬移从i到j,消耗为k+(j-i-1)*d
 *即每跳过一个,累加一次d
 *一次最多跳到i+x的位置,top+x>=i
 *求出最少的答案
 *单调队列优化dp,维护一个单调递增的单调队列
 *dp[i]=a_i+k+min(dp[x]+(i-x-1)*d)
*/
/*

*/
