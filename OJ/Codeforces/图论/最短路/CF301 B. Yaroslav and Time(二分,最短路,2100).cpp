//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
struct node
{//需要保存
	int v;
	ll val,d;
	bool used;
	node(){}
	node(int v,ll d,ll val,bool u):
		v(v),d(d),val(val),used(u){}
	bool operator <(const node &y)const
	{
		return d>y.d;
	}
};
int n,a[maxn],mp[maxn][maxn];
ll dis[maxn][2];
bool vis[maxn][2];
vector<pii> r;
bool check(ll val)
{
	for(int i=1;i<=n;i++)
	{
		dis[i][0]=dis[i][1]=INF;
		vis[i][0]=vis[i][1]=0;
	}
	bool ok=0;
	priority_queue<node>q;
	dis[1][0]=0;
	q.push(node(1,0,val,0));
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		int u=now.v;
		if(vis[u][now.used])
			continue;
		vis[u][now.used]=1;
		for(int v=1;v<=n;v++)
		{
			bool f=now.used;
			if(!vis[v][f]&&dis[v][f]>dis[u][f]+mp[u][v]-a[v])
			{
				dis[v][f]=dis[u][f]+mp[u][v]-a[v];
				q.push(node(v,dis[v][f],now.val,f));
			}
//			if(now.val-now.d>=mp[u][v]&&dis[v][f]>dis[u][f]+mp[u][v])
//			{//不改变状态
//				dis[v][f]=dis[u][f]+mp[u][v];
//				q.push(node(v,dis[v][f],now.val,f));
//			}
//			if(!f&&now.val-now.d>=mp[u][v]&&dis[v][1]>dis[u][0]+mp[u][v])
//			{//可以走到v,并且在v回复
//				dis[v][1]=dis[u][0]+mp[u][v];
//				q.push(node(v,dis[v][1],now.val+a[v],1));
//			}
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%lld%c",dis[i][1],(i==n?'\n':' '));
	return dis[n][1]<INF||dis[n][0]<INF;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int d,x,y;
	cin>>n>>d;
	for(int i=2;i<=n-1;i++)
		cin>>a[i];//恢复的时间
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		r.push_back(pii(x,y));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=d*(abs(r[i-1].ff-r[j-1].ff)+abs(r[i-1].ss-r[j-1].ss));
	check(0);
	cout<<dis[n][0]<<endl;
//	ll ans=inf,l=0,r=d*mp[1][n];
//	while(l<=r)
//	{
//		ll mid=(l+r)>>1;
//		printf("l=%lld,r=%lld,m=%lld\n",l,r,mid);
//		if(check(mid))
//		{
//			ans=min(ans,mid);
//			r=mid-1;
//			for(int i=1;i<=n;i++)
//				printf("%lld%c",dis[i][0],(i==n?'\n':' '));
//		}
//		else
//			l=mid+1;
//	}
//	cout<<ans<<endl;
	return 0;
}
/*
 *消耗d*距离,有一次机会恢复a[i]
 *二分答案并跑状态dijk进行check
 *log(4e7)*n*n
 *读错题了,不是全局只能使用一次...
 *是每个装置只能使用一次...
 *距离总会大于补充,最短路裸题
*/
/*
12 1609
196 486 94 344 524 588 315 504 449 201
86 -22
-2 25
-95 -8
-5 -30
-78 71
5 -54
-69 -92
-41 0
10 19
61 17
75 -39
-46 22
ans = 282231
*/
