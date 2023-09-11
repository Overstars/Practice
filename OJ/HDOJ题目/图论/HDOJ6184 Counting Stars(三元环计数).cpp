#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn=100005;
const int MOD =0x3f3f3f3f;
const int N = 100000+5;
ll fac[N],inve[N];//fac为阶乘,inve为1~n的所有逆元
void init()
{
    fac[0]=fac[1]=inve[0]=inve[1]=1;
    for(ll i=2; i<N; i++)
	{
        fac[i]=fac[i-1]*i%MOD;
        inve[i]=(MOD-MOD/i)*inve[MOD%i]%MOD;
    }
    for(int i=1; i<N; i++)
        inve[i]=inve[i]*inve[i-1]%MOD;
}
long long C(long long n,long long m,long long p)
{//组合数C(n,m)取模p(p是素数)
    if(n<0 || m<0 || m>n) return 0;
    if(n==m) return 1;
    return fac[n]*inve[m]%p*inve[n-m]%p;
}
struct edge
{
	int u,v,cnt;
	edge(int u=0,int v=0,int c=0):
		u(u),v(v),cnt(c){}
};
vector<edge> edges,G[maxn];
int vis[maxn],deg[maxn];
int cycle3(int n)
{
	int ans=0;
	for(int i=1;i<=n;i++)
		G[i].clear();
	memset(vis,0,sizeof(vis));
	memset(deg,0,sizeof(deg));
	for(auto &e:edges)
	{
		deg[e.u]++;
		deg[e.v]++;
	}
	for(auto &e:edges)
	{
		if(deg[e.u]<deg[e.v]||(deg[e.u]==deg[e.v]&&e.u<e.v))
			G[e.u].push_back(edge(e.u,e.v));
		else
			G[e.v].push_back(edge(e.v,e.u));
	}
	for(int x=1;x<=n;x++)
	{//x->y->z
		for(auto y:G[x])
			vis[y.v]=x;
		for(auto &y:G[x])//x->y
		{
			for(auto &z:G[y.v])//y->z
			{
				if(vis[z.v]==x)
				{
					ans++;
					for(auto &tem:G[x])
					{
						if(tem.v==z.v)
						{
							tem.cnt++;
							y.cnt++;
							z.cnt++;
							break;
						}
					}
				}
			}
		}
	}
	return ans;
}
signed main()
{
	int n,m;
	init();
//	for(int i=0;i<5;i++)
//		for(int j=0;j<5;j++)
//			printf("C(%d,%d)=%lld\n",i,j,C(i,j,MOD));
	while(cin>>n>>m)
	{
		int u,v;
		edges.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			edges.push_back(edge(u,v,0));//加一次就够了
		}
		cycle3(n);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(auto &e:G[i])
			{
				if(e.cnt>=2)
					ans+=e.cnt*(e.cnt-1)/2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
