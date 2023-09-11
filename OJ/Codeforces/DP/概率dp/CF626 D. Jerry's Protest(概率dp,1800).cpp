//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5005,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],n;
double dp[3][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dp[0][a[j]-a[i]]+=2.0/n/(n-1);//A-B的差
	for(int i=1;i<=5000;i++)
	{//本轮的差,概率dp[0][i]
		for(int j=1;j+i<=5000;j++)
		{//第一轮的差,概率dp[i][j]
			dp[1][i+j]+=dp[0][i]*dp[0][j];
		}
	}
	double ans=0;
	for(int i=3;i<=5000;i++)
		for(int j=2;j<i;j++)
			ans+=dp[0][i]*dp[1][j];
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<endl;
	return 0;
}
/*
 * 2021-05-07-12.20.03
 * 超过5000的不用统计,救不回来的
*/

