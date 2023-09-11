//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
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
int dp[1005][1005];
bool dfs(int n,int k)
{
	if(n<=k)//必胜
		return 1;
	if(dp[n][k]!=-1)
		return dp[n][k];
	bool win=0;
	for(int i=1;i<=k;i++)
		if(!dfs(n-i,k))
		{
			win=1;
			break;
		}
	return dp[n][k]=win;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	memset(dp,-1,sizeof(dp));
//	for(int i=1;i<=100;i++)
//		for(int j=1;j<i;j++)
//		{
//			if(i%(j+1))
//				printf("dp[%d,%d]=%d\n",i,j,dfs(i,j));
//		}
	int n,k;
	cin>>n>>k;
	bool ok=1;
//	if(n<=k||(n-k)%2==0)
//		ok=1;
	if(n==0)
		ok=0;
	else if(k==1&&n%2==0)
		ok=0;
	cout<<(ok?"Adrien":"Austin")<<endl;
	return 0;
}
/*
 * 2021-04-24-14.04.34
*/

