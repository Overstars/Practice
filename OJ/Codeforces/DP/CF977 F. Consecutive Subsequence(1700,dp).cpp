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
int a[maxn],dp[maxn],rec[maxn];
void dfs(int x)
{
	if(x<=0)
		return;
	dfs(rec[x]);
	cout<<x<<' ';
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0,pos=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	map<int,int> mp;//mp[i]表示上一次出现i的下标
	//dp[i]表示以i为结尾的最长长度,rec[i]表示上一个下标
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[mp[a[i]-1]]+1;
		rec[i]=mp[a[i]-1];
		mp[a[i]]=i;
		if(dp[i]>ans)
		{
			ans=dp[i];
			pos=i;
		}
	}
	cout<<ans<<endl;
	dfs(pos);
	return 0;
}
/*
 *2020年12月27日12点56分
 *长度为n的数组,选出最长的子序列,该子序列在数值上连续
 *打印子序列的下标
 *2020年12月27日13点08分
*/

