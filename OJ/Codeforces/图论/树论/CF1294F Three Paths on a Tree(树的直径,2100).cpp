#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>G[maxn];
int root=1,dist[maxn],rec1[maxn],rec2[maxn];
bool vis[maxn];
void bfs(int rt)
{
	memset(vis,0,sizeof(vis));
	queue<int>QAQ;
	QAQ.push(rt);
	dist[rt]=0;
	vis[rt]=1;
	while(!QAQ.empty())
	{
		int u=QAQ.front();
		if(dist[u]>dist[root])
			root=u;
		QAQ.pop();
		for(auto &v:G[u])
		{
			if(vis[v])
				continue;
			vis[v]=1;
			dist[v]=dist[u]+1;
			QAQ.push(v);
		}
	}
}
int main()
{
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);//找到一个端点a
	int a=root,b,c=0,ans;
	bfs(root);//求出直径,找到另一个端点b
	b=root,ans=dist[root];
	memcpy(rec1,dist,sizeof(int)*(n+1));//节点到a距离
	bfs(root);//求出节点到b距离
	memcpy(rec2,dist,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)
	{
		if(i!=a&&i!=b&&rec1[i]+rec2[i]>rec1[c]+rec2[c])
			c=i;
	}
	ans=(ans+rec1[c]+rec2[c])/2;
	cout<<ans<<endl;
	cout<<a<<' '<<b<<' '<<c<<endl;
	return 0;
}
