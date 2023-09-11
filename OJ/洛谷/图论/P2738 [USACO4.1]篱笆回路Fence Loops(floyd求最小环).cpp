//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=205,inf=0x3f3f3f3f,mod=1000000007;
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
struct edge
{
	int id,l,u,v;
//	vector<int>v1,v2;
//	edge(){}
//	edge(int a,int b,vector<int> &x,vector<int> &y):
//	{
//		id=a,l=b,u=v=0;
//		v1.assign(x.begin(),x.end());
//		v2.assign(y.begin(),y.end());
//	}
};
ll dp[maxn][maxn],a[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,id,n1,n2,u,v,cnt=0;
	ll l;
	cin>>n;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			dp[i][j]=a[i][j]=(i==j?0:inf);
	map<vector<int>,int>mp;
	vector<edge>rec;
	for(int i=1;i<=n;i++)
	{
		cin>>id>>l>>n1>>n2;
		vector<int>v1{id},v2{id};
		for(int j=1;j<=n1;j++)
		{
			cin>>v;
			v1.push_back(v);
		}
		for(int j=1;j<=n2;j++)
		{
			cin>>v;
			v2.push_back(v);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(mp[v1]==0)
			mp[v1]=++cnt;
		if(mp[v2]==0)
			mp[v2]=++cnt;
		u=mp[v1],v=mp[v2];
		dp[u][v]=dp[v][u]=a[u][v]=a[v][u]=min(dp[u][v],l);
//		printf("d<%d,%d>=%lld\n",u,v,l);
//		rec.push_back({id,l,mp[v1],mp[v2]});
	}
	n=cnt;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	ll ans=inf;
	for(int k=1;k<=n;k++)
	{//i->k->j->i
		for(int i=1;i<k;i++)//k为这个环上最大点,直接连接i与j
			for(int j=i+1;j<k;j++)//dp[i][j]表示<i,j>只经过1~k-1优化的最短路
				ans=min(ans,dp[i][j]+a[i][k]+a[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)//如果经过k可以优化,那么它之前一定不经过k
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *给你n个边的信息,点要自己构造
 *建图好难啊
*/

