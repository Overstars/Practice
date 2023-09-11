#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e6+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn];
ll dp[maxn]={1};
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll k,n,ans=0;
	cin>>k>>s+1;
	n=strlen(s+1);
	for(int i=1,now=0;i<=n;i++)
	{
		if(s[i]=='1')
			now++;
		if(now>=k)//以i为结尾,含1个数为k的数目
			ans+=dp[now-k];
		dp[now]++;//1为now的字符串++
	}
	cout<<ans<<endl;
	return 0;
}


