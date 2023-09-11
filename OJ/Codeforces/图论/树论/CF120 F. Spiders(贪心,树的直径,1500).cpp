#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
vector<int> G[maxn];
bool vis[maxn];
int root=0,dist[maxn];
int bfs(int st,int n)
{
	queue<int>QAQ;
	dist[st]=0;
	memset(vis,0,sizeof(vis));
	vis[st]=1;
	QAQ.push(st);
	while(!QAQ.empty())
	{
		int u=QAQ.front();
		QAQ.pop();
		if(dist[u]>dist[root])
			root=u;
		for(auto &v:G[u])
		{
			if(vis[v])
				continue;
			vis[v]=1;
			dist[v]=dist[u]+1;
			QAQ.push(v);
		}
	}
	return dist[root];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,u,v,ans=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(root=1,n);
		ans+=bfs(root,n);
	}
	cout<<ans<<endl;
	return 0;
}
