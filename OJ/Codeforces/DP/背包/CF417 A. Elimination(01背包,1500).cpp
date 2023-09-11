#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn];//dp[i]表示晋级i个人花费的最小题目
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int c,d,n,m,k;
	cin>>c>>d>>n>>m>>k;
	for(int i=1;i<n;i++)
		dp[i]=min(c,i*d);
	for(int i=n;i<=n*m-k;i++)
		dp[i]=min(dp[i-n]+c,dp[i-1]+d);
	cout<<dp[n*m-k]<<endl;
	return 0;
}
/*
 *每次有两种选择,
 *①花费c晋级n个人
 *②花费d晋级一个人
*/
