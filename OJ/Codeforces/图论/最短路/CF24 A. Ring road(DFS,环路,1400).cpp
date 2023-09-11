#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct edge
{
	int u,v,w;
	bool p;//正向
	edge(int u,int v,int w,bool p):
		u(u),v(v),w(w),p(p){}
};
vector<edge> G[maxn];
bool vis[maxn];
int dfs(int x,int fa)
{
	if(vis[x])
		return 0;
	vis[x]=1;
	for(auto nex:G[x])
	{
		int v=nex.v;
		if(v==fa)
			continue;
		if(nex.p)
			return dfs(v,x);
		else
			return dfs(v,x)+nex.w;
	}
}
int main()
{//一个有向环,求变为强联通环的最小代价
	int n,sum=0,u,v,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>w;
		sum+=w;
		G[u].push_back(edge(u,v,w,1));
		G[v].push_back(edge(v,u,w,0));
	}
	int ans=dfs(1,0);
	cout<<min(ans,sum-ans)<<endl;
	return 0;
}
