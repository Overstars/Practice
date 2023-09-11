//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
void solve()
{//枚举答案的做法
	int n,m;
	cin>>n>>m;
	vector<int>a(n),b(m);
	for(auto &x:a)
		cin>>x;
	for(auto &x:b)
		cin>>x;
	for(int ans=0;ans<(1<<9);ans++)
	{//枚举最小答案
		int cnt=0;
		for(int &x:a)
		{
			bool ok=1;
			for(int &y:b)
			{//x&y的位被ans包含
				if(x&y|ans!=ans)
				{
					ok=0;
					break;
				}
			}
			if(ok)
				cnt++;
			else
				break;
		}
		if(cnt==n)
		{
			cout<<ans<<endl;
			exit(0);
		}
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	vector<vector<int>>dp(n+1,vector<int>((1<<9)+1,0));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	dp[0][0]=1;//第i个数字,可以取到j
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int now=a[i]&b[j];
			for(int k=0;k<(1<<9);k++)
				dp[i][k|now]|=dp[i-1][k];
		}
	}
	for(int i=0;i<(1<<9);i++)
		if(dp[n][i])
			return cout<<i<<endl,0;
	return 0;
}


