//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=19,inf=0x3f3f3f3f,mod=1000000007;
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
ll dp[1ll<<maxn][maxn],ans;
vector<int>G[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		u--,v--;//现在是[0,18]了
		G[u].push_back(v);
		G[v].push_back(u);
	}
	//dp[k][x]表示当前点为x,前面经过点的状态为k的简单路径条数
	//且经过的第一个点是k二进制下第一位
	for(int i=0;i<n;i++)
		dp[1ll<<i][i]=1;
	#define lowbit(x) ((x) & -(x))
	for(int k=1;k<(1ll<<n);k++)
	{
		for(int x=0;x<n;x++)
		{
			if(!dp[k][x])
				continue;
			for(int &v:G[x])
			{//枚举x相邻点v
				if(lowbit(k)>(1ll<<v))//v小于经过第一个点,非法
					continue;
				if(k&(1ll<<v))//x是已经过点
				{
//					bitset<20>foo(k);
//					cout<<"k = "<<foo<<endl;
					if(lowbit(k)==(1ll<<v))//是最早经过点,成环
						ans+=dp[k][x];
				}
				else//未经过点,更新状态
					dp[k|(1ll<<v)][v]+=dp[k][x];
			}
		}
	}
	cout<<(ans-m)/2<<endl;
	return 0;
}


