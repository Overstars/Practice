//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
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
int dp[maxn][maxn*10],c[maxn],cost[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,w,b,x;
	cin>>n>>w>>b>>x;
	for(int i=1;i<=n;i++)
		cin>>c[i];//有c只鸟
	for(int i=1;i<=n;i++)
		cin>>cost[i];//召唤一只的花费,召唤一只魔法上限增加b
	return 0;
}
/*
 * 2021-05-19-09.08.53
 * C:\Users\dell\Desktop\C++\OJ\洛谷\动态规划\dp优化\CF922 E. Birds(单调栈优化dp,2200).cpp
 * dp[i][j]表示到第i棵树下有j只鸟
*/

