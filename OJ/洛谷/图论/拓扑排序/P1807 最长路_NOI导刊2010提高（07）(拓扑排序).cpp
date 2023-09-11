#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1505;
struct node
{
	int v,w;
	node(int v,int w):
		v(v),w(w){}
};
vector<node> G[maxn];
int n,m,into[maxn],dist[maxn];
//#define DEBUG
int toposort(void)
{
	dist[1]=0;
	queue<int> QAQ;//节点的编号
	for(int i=1;i<=n;i++)
	{
		if(into[i]==0)
			QAQ.push(i);
	}
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		for(int i=0;i<G[x].size();i++)
		{
			dist[G[x][i].v]=max(dist[G[x][i].v],dist[x]+G[x][i].w);
			if(--into[G[x][i].v]==0)
				QAQ.push(G[x][i].v);
		}
	}
	if(dist[n]==-inf)
		return -1;
	else
		return dist[n];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while(cin>>n>>m)//求i到n的最长路
	{
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
		}
		memset(into,0,sizeof(into));//入度清空
		fill(dist,dist+maxn,-inf);
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			G[u].push_back(node(v,w));
			into[v]++;
		}
		cout<<toposort()<<endl;
	}
	return 0;
}
