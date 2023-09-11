//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
vector<int>G[maxn],p;
ll sum[maxn],dist[3][maxn];
void bfs(ll d[],int st)
{
	d[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int &v:G[x])
		{
			if(d[v]>d[x]+1)
			{
				d[v]=d[x]+1;
				q.push(v);
			}
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
	int t,n,m,a,b,c,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b>>c;//求a->b->c最短路径
		for(int i=1;i<=n;i++)
			dist[0][i]=dist[1][i]=dist[2][i]=sum[i]=INF;
		for(int i=1;i<=n;i++)
			G[i].clear();
		p.clear();
		for(int i=1,tmp;i<=m;i++)
		{
			cin>>tmp;
			p.push_back(tmp);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		sort(p.begin(),p.end());
		for(int i=1;i<=m;i++)
			sum[i]=sum[i-1]+p[i-1];
		bfs(dist[0],a);
		bfs(dist[1],b);
		bfs(dist[2],c);
		ll ans=INF;
		for(int i=1;i<=n;i++)
		{//b->i,a->i,i->c
			ll l1=dist[1][i],l2=dist[0][i],l3=dist[2][i];
//			printf("i=%d,%lld\n",i,sum[l1]+sum[l1+l2+l3]);
//			printf("(%lld,%lld,%lld)\n",l1,l2,l3);
//			ans=min(ans,2*sum[l1]+sum[l1+l2]-sum[l1]+sum[l1+l2+l3]-sum[l1+l2]);
			if(l1+l2+l3<=m)//不能越界,加这个就过了...
				ans=min(ans,sum[l1]+sum[l1+l2+l3]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 *列表平均时间45min
 *应该是看a->b和b->c有没有公共路径
 *可以看作b->a和b->c,先以b为起点先做一遍bfs,删掉多余的边
 *标记出b->a和b->c的路径,并贪心从小到大分配边权
 *好像不是很行...
 *枚举两条路径的公共端点
 *
*/

