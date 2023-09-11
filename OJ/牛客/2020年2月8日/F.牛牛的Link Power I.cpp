#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
char s[maxn];
ll sum[maxn],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n>>s+1;
	for(int i=1,tot=0;i<=n;i++)
	{
		sum[i]=sum[i-1]+tot;//tot每个步长+1
		sum[i]%=mod;
		if(s[i]=='1')//之前的个数
			tot++;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
			dp[i]=(dp[i-1]+sum[i])%mod;
		else
			dp[i]=dp[i-1];
	}
	cout<<dp[n]<<endl;
	return 0;
}


