#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,maxn=20005;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct edge
{
	int v,w;
};
int dis[maxn];
vector<edge>G[maxn];
//int mp[maxn][maxn],dis[maxn];
void dijk(int n,int s)
{
//	for(int i=1;i<=n;i++)
//		dis[i]=mp[s][i];
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	for(auto &e:G[s])
		dis[e.v]=e.w;
	dis[s]=0;
	vector<bool>vis(n+1,false);
	vis[s]=1;
	for(int i=1;i<=n;i++)
	{
		int rec=INF,tar=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<rec)
				tar=j,rec=dis[j];
		}
		if(tar==0)
			break;
		vis[tar]=1;
		for(auto &e:G[tar])
			if(!vis[e.v])
				dis[e.v]=min(dis[e.v],dis[tar]+e.w);
//		for(int j=1;j<=n;j++)//松弛操作
//			if(!vis[j]&&mp[tar][j]<INF)
//				dis[j]=min(dis[j],dis[tar]+mp[tar][j]);
	}
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
//	memset(mp,INF,sizeof(mp));
//	for(int i=1;i<=n;i++)
//		mp[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back({v,w});
//		G[v].push_back({u,w});
//		mp[u][v]=min(mp[u][v],w);
	}
	dijk(n,s);
	for(int i=1;i<=n;i++)
		cout<<(dis[i]==INF?(1ll<<31)-1:dis[i])<<' ';
	return 0;
}
