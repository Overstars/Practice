#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
vector<int>G[maxn];
ll deg[maxn],fa[maxn];
bool vis[maxn];
int findfa(int x)
{
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
	{
		fa[b]=a;
	}
	else
	{
		fa[a]=b;
	}
	return 1;
}
vector<int>rec;//记录当前强连通子图节点
bool bfs(int x)
{
	rec.clear();
	queue<int> QAQ;
	vis[x]=1;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int u=QAQ.front();
		QAQ.pop();
		rec.push_back(u);
		for(auto &v:G[u])
		{
			if(!vis[v])
			{
				vis[v]=1;
				QAQ.push(v);
			}
		}
	}
	for(auto &i:rec)
		if(deg[i]!=2)
			return 0;
	return rec.size()>2;//两个点不为环
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&bfs(i))
			ans++;
	cout<<ans<<endl;
	return 0;
}
/*
 *题意:求无向图所有连通子图中环的个数
 *判断一个连通子图中所有点度数是否为2
 *用BFS将连通图存到vector再判断
 */
