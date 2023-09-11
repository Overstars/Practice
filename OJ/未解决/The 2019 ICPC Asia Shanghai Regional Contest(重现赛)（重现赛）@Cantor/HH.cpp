//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
//struct edge
//{
//	int u,v;
//	ll w;
//	edge(){}
//	edge(int u,int v,ll w):
//		u(u),v(v),w(w){}
//};
vector<int>G[maxn];
ll w[maxn],val[maxn];
void dfs(int x,int fa)
{
	val[x]=w[x];
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
		val[x]+=val[v];
	}
}
ll cnt=0,lim=0;
ll dfs2(int x,int fa)
{
	ll ret=0;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		if(val[x]-ret<=lim)//合法了
			break;
		cerr<<"del:"<<x<<" -> "<<v<<endl;
		if(val[v]<=lim&&val[v]+w[x]>lim)
		{//100%删掉该子树
			cnt++;
			ret+=val[v];
			continue;
		}
		else{//子树里面还需要删
			ret+=dfs2(v,x);//val[x]-ret是x子树上当前剩余部分
			cnt++;
		}
	}
	return val[x]-ret;//被删除的部分
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n,k,u,v;
	scanf("%lld",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%lld%lld",&n,&k);
		ll l=1,r=0,ans=LLONG_MAX;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%lld %lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&w[i]);
			l=max(l,w[i]);
			r+=w[i];
		}
		ans=r;
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			sort(G[i].begin(),G[i].end(),[](const int &x,const int &y){
					return val[x]>val[y];
				});
//			for(auto &v:G[i])
//			{
//				cerr<<"val["<<v<<"] = "<<val[v]<<endl;
//				cerr<<i<<" now = "<<v<<endl;
//			}
		}
		while(l<=r)
		{
			ll mid=(l+r)>>1;
//			printf("l = %lld, r = %lld\n",l,r);
			lim=mid;
			cnt=0;
			val[0]=LLONG_MAX;
			dfs2(1,0);
			cnt++;
//			printf("mid = %lld, cnt = %lld\n",mid,cnt);
			if(cnt<=k)
			{//合法
				r=mid-1;
				ans=min(ans,mid);
			}
			else{
				l=mid+1;
			}
		}
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
/*
999
6 2
1 2
1 3
3 4
3 5
1 6
1 8 2 3 2 1

4 2
1 2
1 3
1 4
9 1 2 3

5 3
1 2
2 3
1 4
1 5
2 7 8 2 2

ans =  9,12,8
*/
/*
 * 2021-04-28-17.17.43
*/


