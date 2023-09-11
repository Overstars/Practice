#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=10005;
struct node
{
	int v,w;
	node(int v,int w):
		v(v),w(w){}
};
vector<node> G[maxn];
bool vis[maxn];
int dis[maxn][maxn];
int bfs(int x,int &d)
{
	memset(vis,0,sizeof(vis));
	queue<int> QAQ;
	QAQ.push(x);
	vis[x]=1;
	dis[x][x]=0;
	int farn=x;
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		QAQ.pop();
		for(int i=0;i<G[now].size();i++)
		{
			int nex=G[now][i].v;
			if(vis[nex])
				continue;
			vis[nex]=1;
			dis[x][nex]=max(dis[x][nex],dis[x][now]+G[now][i].w);
			QAQ.push(nex);
			if(dis[x][nex]>d)
			{
				d=dis[x][nex];
				farn=nex;
			}
//			cout<<"IN QUEUE"<<endl;
		}
	}
	return farn;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int u,v,w,dist=0;
	while(cin>>u>>v>>w)
	{
		G[u].push_back(node(v,w));
		G[v].push_back(node(u,w));
	}
	bfs(bfs(1,dist),dist);
	cout<<dist<<endl;
	return 0;
}
