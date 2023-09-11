#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
//define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],dp[3605];//秒数,能否凑出来3600的倍数
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	read(t);
	while(t--)
	{
		read(n);
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			if(a[i]%3600==0)
				ok=1;
			a[i]%=3600;
		}
		if(ok)
		{
			goto label;
		}
		fill(dp,dp+3605,-inf);
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int v=3600;v>=a[i];v--)
			{
				dp[v]=max(dp[v],dp[v-a[i]]+a[i]);
//				printf("dp[%d][%d]=%d\n",i,v,dp[i]);
				if(dp[v]%3600==0)
				{
					ok=1;
					goto label;
				}
				dp[v]%=3600;
			}
		label:
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}


