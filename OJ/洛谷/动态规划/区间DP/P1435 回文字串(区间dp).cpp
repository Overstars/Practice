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
int dp[maxn][maxn];
char s[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1;
	int n=strlen(s+1);
//	memset(dp,inf,sizeof(dp));
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)//枚举起点
		{
			int j=i+l-1;//终点
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1];
			else//插入一个字符保持回文性质
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
		}//右面插入一个左端字符/左面插入右端字符
	}
	cout<<dp[1][n]<<endl;
	return 0;
}


