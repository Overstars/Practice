//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],dp[maxn],dp2[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		{
			dp[i]=dp[i-1]+1;
		}
		else
			dp[i]=1;
		ans=max(ans,dp[i]);
	}
	for(int i=n;i>=1;i--)
		if(a[i]<a[i+1])
			dp2[i]=dp2[i+1]+1;
		else
			dp2[i]=1;
	for(int i=1;i<=n;i++)
	{//将a[i]修改为合适的
		if(a[i+1]-a[i-1]>=2)
			ans=max(ans,dp[i-1]+dp2[i+1]+1);
		else
			ans=max({ans,dp[i-1]+1,dp2[i+1]+1});
	}
	cout<<ans<<endl;
	return 0;
}
/*
5
2 3 4 5 1

6
3 4 5 6 2 1
*/

