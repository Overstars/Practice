//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
bool cmp(const int &a,const int&b)
{
    return a>b;
}
int a[maxn],dp[maxn],ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int top=0;
		ans[1]=1;
		dp[++top]=a[1];
		for(int i=2;i<=n;i++)
		{
			if(dp[top]>a[i])
			{
				dp[++top]=a[i];
				ans[i]=top;
			}
			else{//查找第一个小于等于x的数
				int pos=lower_bound(dp+1,dp+top+1,a[i],cmp)-dp;
//				for(int j=1;j<=top;j++)
//					printf("dp[%d]=%d\n",j,dp[j]);
				ans[i]=pos;
				dp[pos]=a[i];
			}
//			ans[i]=top;
		}
		cout<<top<<endl;
		cout<<ans[1];
		for(int i=2;i<=n;i++)
			cout<<' '<<ans[i];
		cout<<endl;
	}
	return 0;
}
/*
999
6
2 4 6 3 1 5
*/
/*
 * 2021-04-13-16.11.48
 *
 *
*/
