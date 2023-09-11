#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2010,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn];//dp[i]表示[1,i]的回文子串数目
char s[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1;
	ll ans=0,n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{//复杂度n^2
		dp[i]+=dp[i-1];
		for(int j=0;i-j>=1&&i+j<=n;j++)
		{//以i为中心的奇数长度回文
			if(s[i-j]!=s[i+j])
				break;
			else{
				dp[i+j]++;
				ans+=dp[i-j-1];
			}
		}
		for(int j=0;i+j<=n&&i-j-1>=1;j++)
		{//以i-1,1为中心的偶数长度回文
			if(s[i-j-1]!=s[i+j])
				break;
			else{
				dp[i+j]++;
				ans+=dp[i-j-2];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


