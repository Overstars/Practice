#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],b[maxn],dp[maxn];
bool ist[maxn];
signed main()//dp[i]为保留i坐标的塔为末尾的最多数量
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0,lim=0;
	map<int,int>power;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ist[a[i]]=1;
		power[a[i]]=b[i];
		lim=max(lim,a[i]);
	}
	for(int i=0;i<=lim;i++)
	{
		if(ist[i])
		{
			int now=power[i];
			if(now>=i)
			{//消灭了所有的塔
				dp[i]=1;
			}
			else//从范围外转移过来
				dp[i]=dp[i-now-1]+1;
		}
		else
			dp[i]=dp[i-1];
		ans=max(ans,dp[i]);
	}
	cout<<n-ans<<endl;
	return 0;
}


