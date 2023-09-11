#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn = 10005;
int n,p,q;//n辆探测车
bool flag=0;
struct MCMF
{
	struct Edge
	{
		int from, to, cap, flow, cost;
		Edge(int u, int v, int c, int f, int w)
			: from(u), to(v), cap(c), flow(f), cost(w) {}
	};
	int n, m;
	vector<Edge> edges;//边表。edge[e]和edge[e^1]互为反向弧
	vector<int> G[maxn];//邻接表，G[i][j]表示节点i的第j条边在edges数组中的序号
	int inq[maxn]; //是否在队列中
	int dist[maxn]; //bellmanford
	int prevv[maxn]; //上一条弧
	int a[maxn]; //可改进量
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap, int cost)
	{
//		edges.emplace_back(Edge(from, to, cap, 0, cost));
//		edges.emplace_back(Edge(to, from, 0, 0, -cost));
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BellmanFord(int s, int t, int& flow, ll& cost)
	{
		for (int i = 0; i < n; i++)
			dist[i] = inf;
		memset(inq, 0, sizeof(inq));
		dist[s] = 0;
		inq[s] = 1;
		prevv[s] = 0;
		a[s] = inf;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if (e.cap > e.flow && dist[e.to] > dist[u] + e.cost)
				{
					dist[e.to] = dist[u] + e.cost;
					prevv[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
//		cout<<"DEBUG:BellmanFord\n";
//		cout<<"flow"<<flow<<",cost="<<cost<<endl;
		if (dist[t] == inf)
			return false; // 当没有可增广的路时退出
		flow += a[t];
		cost += (ll)dist[t] * (ll)a[t];
		for (int u = t; u != s; u = edges[prevv[u]].from)
		{
			edges[prevv[u]].flow += a[t];
			edges[prevv[u] ^ 1].flow -= a[t];
		}
		return true;
	}
	int MincostMaxflow(int s, int t, ll& cost)
	{
		int flow = 0;
		cost = 0;
		while(BellmanFord(s, t, flow, cost));
		return flow;
	}
	void dfs(int x,int y,int u,int no);
} mm;
//#define debug
int mp[55][55];
void MCMF::dfs(int x,int y,int u,int no)//第no号机器人到达了u节点
{
	int kx,ky,dir;//0向下,1向右
	int res=p*q+u;//u节点的拆点编号
	if(flag)//no号到达了终点
		return;
	for(int i=0;i<G[res].size();i++)
	{
		if(flag)
			return;
		if(edges[G[res][i]].flow>0&&(edges[G[res][i]].to==u+1||edges[G[res][i]].to==u+p))//残余流量大于0
		{//q行,p列,x与q同方向,表示第几行
			edges[G[res][i]].flow--;
			if(edges[G[res][i]].to==u+1)//向右
			{
				dir=1;
			}
			else{
				dir=0;
			}
			printf("%d %d\n",no,dir);
			if(dir==1)
			{
//				printf("(%d,%d)->(%d,%d)\n",x,y,x,y+1);
				dfs(x,y+1,u+1,no);
			}
			else{
//				printf("(%d,%d)->(%d,%d)\n",x,y,x+1,y);
				dfs(x+1,y,u+p,no);
			}
			if(edges[G[res][i]].to==p*q)
				flag=1;
		}
	}
}
int main()
{
	#ifdef debug
	freopen("P3356.in","r",stdin);
	#endif // debug
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>p>>q;
	for(int i=1;i<=q;i++)//q行,p列
		for(int j=1;j<=p;j++)//与深海探测不同的是节点有权
			cin>>mp[i][j];//0平坦,1障碍,2标本
	int s=0,t=p*q*2+1,nx[4]={1,0},ny[4]={0,1};//x与q同方向,表示第几行
	mm.init(t+10);//编号=(i-1)*p+j
	mm.AddEdge(s,1,n,0);
	mm.AddEdge(p*q*2,t,n,0);
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=p;j++)
		{
			int id=(i-1)*p+j;
			if(mp[i][j]==1)
				continue;
			else
				mm.AddEdge(id,p*q+id,inf,0);//拆点
			if(mp[i][j]==2)
				mm.AddEdge(id,p*q+id,1,-1);//第一个来的采集
			for(int k=0;k<2;k++)
			{
				int x=i+nx[k],y=j+ny[k];
				if(x<0||x>q||y<0||y>p)
					continue;
				mm.AddEdge(p*q+id,(x-1)*p+y,inf,0);//连接点与点
			}
		}
	}
	ll cost;
	mm.MincostMaxflow(s,t,cost);
//	cout<<-cost<<endl;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		mm.dfs(1,1,1,i);//起点(1,1),出点1,第i号机器人
	}
	return 0;
}

