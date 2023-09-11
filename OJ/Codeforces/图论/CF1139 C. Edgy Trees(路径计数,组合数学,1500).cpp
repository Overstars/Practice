#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,mod=1e9+7;
ll qpow(ll a,ll b)//快速幂
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
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):
		u(u),v(v),w(w){}
};
vector<edge> G[maxn];
bool vis[maxn];
ll dfs(int x)//
{
	vis[x]=1;
	ll ret=1;
	for(auto &v:G[x])
		if(!v.w&&!vis[v.v])
		{
			ret=(ret+dfs(v.v))%mod;
		}
	return ret;
}
int main()
{
	int n,k,u,v,w;
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(edge(u,v,w));
		G[v].push_back(edge(v,u,w));
	}
	ll ans=qpow(n,k);
    for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans=(ans-qpow(dfs(i),k))%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;//小技巧
	return 0;
}
/*
 *一棵树,边为红或黑
 *长度为k的序列a_k,代表经过的节点次序
 *求出都走完之后,至少经过一条黑边的序列种类数

 *思路:算出所有可能,再减去由红边构成的联通块(或者孤立点)
 */

