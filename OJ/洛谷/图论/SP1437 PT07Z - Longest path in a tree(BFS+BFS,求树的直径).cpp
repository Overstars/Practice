#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=10005;
struct node
{
	int v,w;
	node(int v,int w=1):
		v(v),w(w){}
};
vector<node> G[maxn];
bool vis[maxn];
//int dis[maxn];//x点到其他点距离
int bfs(int x,int &d)
{
	memset(vis,0,sizeof(vis));
//	memset(dis,0,sizeof(vis));
	queue<node> QAQ;
	QAQ.push(node(x,0));
	vis[x]=1;
	int farn=x;
	while(!QAQ.empty())
	{
		node now=QAQ.front();
		QAQ.pop();
		for(int i=0;i<G[now.v].size();i++)
		{
			node nex=G[now.v][i];
			if(vis[nex.v])
				continue;
			vis[nex.v]=1;
//			dis[nex.v]=max(dis[nex.v],dis[now.v]+1);
			int dis=now.w+nex.w;
			if(d<dis)
			{
				d=dis;
				farn=nex.v;
			}
			QAQ.push(node(nex.v,dis));
		}
	}
	return farn;
}
int main()
{
	int n,dist=0;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(node(v));
		G[v].push_back(node(u));
	}
	bfs(bfs(1,dist),dist);
	cout<<dist<<endl;
	return 0;
}
