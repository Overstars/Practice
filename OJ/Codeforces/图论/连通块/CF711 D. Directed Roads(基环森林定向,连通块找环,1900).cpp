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
ll qmod(ll a,ll b,ll mod)  //快速幂
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
vector<int>G[maxn];
bool vis[maxn];
ll depth[maxn];
ll dfs(int x,int fa)
{
	vis[x]=1;
	depth[x]=depth[fa]+1;
//	printf("%d has been visited.\n",x);
	ll ret=0;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		if(vis[v])
		{
			ret=max(depth[x]-depth[v]+1,ret);
			continue;
		}
		ret=max(ret,dfs(v,x));
	}
	return ret;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,tmp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		G[i].push_back(tmp);
		G[tmp].push_back(i);
	}
	ll ans=1,cnt=0,c2=0;
	vector<ll>cir;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ll now=dfs(i,i);
			if(now==0)
			{
				c2++;//反向边,特殊统计
				continue;
			}
			cir.push_back(now);
			cnt+=now;
//			printf("now=%lld\n",now);
		}
	}
	for(ll &x:cir)
		ans=(ans*(qmod(2,x,mod)-2))%mod;
	cout<<qmod(2,n-c2-cnt,mod)*ans%mod<<endl;
	return 0;
}
/*
 *给你一个基环森林,定向,求无环的个数
*/

