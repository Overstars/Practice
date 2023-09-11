//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int a[6][maxn],pos[6][maxn],dp[maxn];//第i个串前j个数字以k结尾的长度
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,ans=1;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j],pos[i][a[i][j]]=j;
	for(int i=1;i<=n;i++)
		dp[i]=1;//dp[i]表示以数值i结尾的LCM
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			int u=a[1][j],v=a[1][i];//n^2枚举1串中,并且在k串中check
			bool ok=1;
			for(int kk=2;kk<=k;kk++)
				if(pos[kk][u]>pos[kk][v])
					ok=0;
			if(ok)
				dp[v]=max(dp[v],dp[u]+1);
			ans=max(ans,dp[v]);
		}
	}
	cout<<ans<<endl;
	return 0;
}


