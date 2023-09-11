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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,l,r;
	cin>>n>>m;
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));//a(n+1,vector<int>(m+1,0));
	vector<int> a(m+1),rec(n+1,inf);
	for(int i=1;i<=n;i++)
		for(int j=1,tmp;j<=m;j++)
		{
			cin>>tmp;
			if(tmp>=a[j])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=i;
			a[j]=tmp;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			rec[i]=min(rec[i],dp[i][j]);
	cin>>k;
	while(k--)
	{
		cin>>l>>r;
		cout<<(rec[r]<=l?"Yes":"No")<<endl;
	}
	return 0;
}


