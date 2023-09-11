#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=4005,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int b[maxn],dp[maxn][maxn];
signed main()
{//两个数交替出现的最长子序列
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,tot=0;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(mp[b[i]]==0)
			mp[b[i]]=++tot;
		b[i]=mp[b[i]];//离散化
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=1;
	int ans=1;
	for(int i=1;i<=n;i++)
	{//以下标i为结尾,改变量为b[j]的最长长度
		for(int j=1;j<i;j++)
		{//j作为序列中上一个元素
			dp[i][b[j]]=max(dp[i][b[j]],dp[j][b[i]]+1);
			ans=max(ans,dp[i][b[j]]);
		}
	}
	cout<<ans<<endl;
	return 0;
}


