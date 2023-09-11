#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#define pb push_back
using namespace std;
const int mo=1e9+7;
const int maxn=4e6+10;
int n,st[maxn],to[maxn],nt[maxn],topt;
long long dp[maxn],ans[maxn],sum1[maxn],sum2[maxn],v[maxn];
vector<long long>pre[maxn],suf[maxn];
inline void add(int x,int y){to[++topt]=y; nt[topt]=st[x]; st[x]=topt;}
long long po(long long a,long long b)
{
	if (!b) return 1;
	if (b==1) return a%mo;
	long long c=po(a,b/2);
	if (b&1) return c*c%mo*a%mo;else return c*c%mo;
}
void dfs1(int x,int fa)
{
	dp[x]=1; int p=st[x];
	while (p)
	{
		if (to[p]!=fa) dfs1(to[p],x),dp[x]=dp[x]*(dp[to[p]]+1)%mo;
		p=nt[p];
	}
}
void dfs2(int x,int fa,long long now)
{
	ans[x]=dp[x]*(now+1)%mo; int p=st[x],cnt=0;
	while (p)
	{
		if (to[p]!=fa) v[++cnt]=dp[to[p]]+1;
		p=nt[p];
	}
	sum1[0]=1; pre[x].pb(1);
	for (int i=1;i<=cnt;i++) sum1[i]=sum1[i-1]*v[i]%mo,pre[x].pb(sum1[i]);
	sum2[cnt+1]=1; suf[x].pb(1);
	for (int i=cnt;i>=1;i--) sum2[i]=sum2[i+1]*v[i]%mo;
	for (int i=1;i<=cnt;i++) suf[x].pb(sum2[i]);
	suf[x].pb(1); cnt=0; p=st[x];
	while (p)
	{
		if (to[p]!=fa)
		{
			cnt++;
			dfs2(to[p],x,pre[x][cnt-1]*suf[x][cnt+1]%mo*(now+1)%mo);
		}
		p=nt[p];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1,0); dfs2(1,0,0);
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
return 0;
}
