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
char s[maxn];
int dp[maxn],pre[maxn],del[maxn];
int stk[maxn],top=0;
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
		cin>>s+1;
		n=strlen(s+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			del[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=3&&i<=n-2&&s[i]=='o'&&s[i-1]=='w'&&s[i-2]=='t'&&s[i+1]=='n'&&s[i+2]=='e')
			{
				del[i]=1;
				ans++;
			}
			else if(i>=3&&s[i]=='o'&&s[i-1]=='w'&&s[i-2]=='t')
			{
				del[i-1]=1;
				ans++;
			}
			else if(i<=n-2&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
			{
				del[i+1]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			if(del[i])
				cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}
/*
 * 2021-05-18-12.59.53
*/

