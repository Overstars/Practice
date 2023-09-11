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
char s[maxn];
int dp[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>s+1;
		int n=strlen(s+1);
		int ans=0,cnt=0;
		bool have=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1'&&s[i-1]!='1')
			{
				if(!have)
					ans+=a;
				else
					ans+=min(a,cnt*b);
				have=1;
			}
			if(s[i]=='1')
			{
				have=1;
				cnt=0;
			}
			else
				cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 *a元引爆地雷,b元放置地雷
*/

