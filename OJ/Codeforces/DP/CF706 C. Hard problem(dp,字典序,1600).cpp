#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
const ll llinf=0x3f3f3f3f3f3f3f3f;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
string s[maxn],rev[maxn];
ll c[maxn],dp[maxn][2];
signed main()
{//0不反转,1反转
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(dp,llinf,sizeof(dp));
//	fill(dp,dp+maxn*2,llinf);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		rev[i]=s[i];
		reverse(rev[i].begin(),rev[i].end());
	}
	dp[1][0]=0,dp[1][1]=c[1];
	for(int i=2;i<=n;i++)
	{
		if(s[i]>=s[i-1])
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(s[i]>=rev[i-1])
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(rev[i]>=s[i-1])
			dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		if(rev[i]>=rev[i-1])
			dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
	}
	if(dp[n][0]==llinf&&dp[n][1]==llinf)
		cout<<-1<<endl;
	else
		cout<<min(dp[n][0],dp[n][1])<<endl;
	return 0;
}


