//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
ll dp[maxn][2],a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1][0]=a[1]*r1+r3;//清空,手枪打a次小兵
	dp[1][1]=min({(a[1]+1)*r1,r2});//留一滴血,之后回来解决
	for(int i=2;i<=n;i++)
	{//上一层清完or回去用三种枪任意一种清
		dp[i][0]=min({dp[i-1][0],dp[i-1][1]+d*3+min({r1,r2,r3})})+a[i]*r1+r3+d;
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+d*3+min({r1,r2,r3}))+min((a[i]+1)*r1,r2);//留下一滴血
	}
	cout<<min(dp[n][0],dp[n-1][1]+d*3+min({r1,r2,r3}))<<endl;
	return 0;
}
/*
 *两种怪,1hp,2hp
 *三种枪
 *打一个怪1hp,r1装弹
 *打所有怪1hp,r2装弹
 *秒杀一个怪,r3装弹
 *每关有一个boss和ai个小兵,没清小兵之前不能用1和3打boss
 *这能dp吗...还是贪心?
 */

