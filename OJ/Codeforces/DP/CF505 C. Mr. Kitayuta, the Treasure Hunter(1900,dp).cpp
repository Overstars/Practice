//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e4+10,inf=0x3f3f3f3f,mod=1000000007;
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
int dp[maxn][700],mp[maxn],ans=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,d,x,lim=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		lim=max(lim,x);
		mp[x]++;
	}
	fill(dp[0],dp[0]+maxn*700,-inf);
	int st=300;
	ans=dp[d][st]=mp[d];
	for(int i=d+1;i<=lim;i++)
	{//dp[i][j]表示数值为i时且相对d的偏移量为j的最大值
		for(int j=-260;j<=260;j++)
		{//枚举偏移量,那么本次长度为d+j,起点即为i-(d+j)
			if(i-(d+j)>0&&i-(d+j)<i)
			{//偏移起点落在(0,i)之间
				dp[i][j+st]=max(
					dp[i][j+st],
					max({dp[i-(d+j)][j+st],dp[i-(d+j)][j+st-1],dp[i-(d+j)][j+st+1]})+mp[i]
				);
			}
			ans=max(ans,dp[i][j+st]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
//int mp[maxn],ans=0;
//map<int,int>dp[maxn];
//signed main(signed argc, char const *argv[])
//{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
//	//	freopen("output.out", "w", stdout);
//	#endif
//	int n,d,x,lim=0;
//	cin>>n>>d;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>x;
//		lim=max(lim,x);
//		mp[x]++;
//	}
//	dp[d][d]=mp[d];
//	for(int i=d;i<=lim;i++)
//	{
////		printf("i = %d\n",i);
//		for(auto &j:dp[i])
//		{
//			int nex=i+j.ff-1,step=j.ff-1;
//			if(j.ff>1)
//				dp[nex][step]=max(dp[nex][step],dp[i][j.ff]+mp[nex]);
//			step=j.ff,nex=i+j.ff;
//			if(nex<=30000)
//				dp[nex][step]=max(dp[nex][step],dp[i][j.ff]+mp[nex]);
//			step=j.ff+1,nex=i+j.ff+1;
//			if(nex<=30000)
//				dp[nex][step]=max(dp[nex][step],dp[i][j.ff]+mp[nex]);
//			ans=max(ans,j.ss);
//		}
//	}
//	cout<<ans<<endl;
//	return 0;
//}
/*
 * 2021-04-22-09.37.06
*/

