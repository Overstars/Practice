#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[27][27];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	fill(dp[0],dp[0]+27*27,-inf);
	int n,ans=0;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int l=s[0]-'a',r=s[s.length()-1]-'a',len=s.length();
		for(int i=0;i<26;i++)//lr串
			dp[i][r]=max(dp[i][r],dp[i][l]+len);
		dp[l][r]=max(dp[l][r],len);
	}
	for(int i=0;i<26;i++)
		ans=max(ans,dp[i][i]);
	cout<<ans<<endl;
	return 0;
}


