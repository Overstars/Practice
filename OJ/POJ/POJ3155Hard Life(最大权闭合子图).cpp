//#pragma GCC optimize(2)
//#pragma G++ optimize("O2") //O2优化
//#pragma comment(linker, "/STACK:102400000,102400000") //手动扩栈
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const double eps = 1e-14;
const int maxn=1205;
//#define DEBUG
struct Dinic
{//复杂度O(n^2m)
	struct Edge
	{
		int from, to;
		double cap,flow;
		Edge(int u, int v, double c, double f):
			from(u), to(v), cap(c), flow(f) {}
	};
	int n, m, s, t; //结点数,边数(包括反向弧),源点编号和汇点编号
	vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
	vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
	bool vis[maxn]; //BFS使用
	int d[maxn]; //从起点到i的距离
	int cur[maxn]; //当前弧下标
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, double cap)
	{
//		edges.emplace_back(Edge(from, to, cap, 0));//魔改蔡队模板
//		edges.emplace_back(Edge(to, from, 0, 0)); //反向弧,初始容量为0
		edges.push_back(Edge(from, to, cap, 0.0));
		edges.push_back(Edge(to, from, 0.0, 0.0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
//		for(int i=0;i<n;i++)
//			d[i]=0;
		memset(d, -1, sizeof(d));
		queue<int> q;
		q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap - e.flow > eps)
				{//只考虑残量网络中的弧
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;//构造分层图
					q.push(e.to);
				}
			}
		}
		return vis[t];//有无增广路,s->t
	}
	double DFS(int x, double a)//x为当前点,a为当前边上流量
	{//在层次图上向t延伸,多路增广
		if(x==t||abs(a)<=eps)//到达目标/流量为0断流
			return a;
		double flow = 0, f;
		for(int& i=cur[x];i<G[x].size();i++)//从上一次x遍历跑到的点开始跑
		{//从上次考虑的弧
			Edge& e = edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow))) > 0)
			{//只从层数编号较小的点到下一层的点
				e.flow += f;//该路径上边流量都增加f
				edges[G[x][i]^1].flow -= f;//方便反悔
				flow += f;
				a -= f;//用去可增广量
//				if(a==0)//a等于0及时退出
				if(abs(a)<=eps)
					break;//当a!=0,说明当前节点还存在另一个增广路分支。
			}
		}
		if(flow<eps)//增广后容量满了
			d[x] = -1;//炸点优化,不必要的点下一次就不用遍历
		return flow;//返回x节点最大流量,传递到上一级
	}
	double Maxflow(int s, int t)
	{
		this->s = s, this->t = t;
		double flow = 0;
		while (BFS())//不停地用bfs构造分层网络，然后用dfs沿着阻塞流增广
		{
			memset(cur, 0, sizeof(cur));//建完分层图后cur也要初始化
			flow += DFS(s,inf);
		}
		return flow;
	}
} di;
int a[maxn],b[maxn],deg[maxn],n,m,ans2;
void getmap(int s,int t,double g)
{//建图
	di.init(t+5);
	for(int i=1;i<=n;i++)
		di.AddEdge(i,t,g);
	for(int i=1;i<=m;i++)
	{
		di.AddEdge(s,n+i,1.0);
		di.AddEdge(n+i,a[i],1e9);
		di.AddEdge(n+i,b[i],1e9);
	}
}
bool vis[maxn];
void dfs(int x)
{//搜索残余网络
//	cerr<<"x = "<<x<<endl;
	vis[x]=1;
	if(x>=1&&x<=n)
		ans2++;
	for (int i = 0; i < di.G[x].size(); i++)
	{
		int nex=di.G[x][i];
		int v=di.edges[nex].to;
		double cap=di.edges[nex].cap,flow=di.edges[nex].flow;
		cerr<<"v = "<<v<<',';
		cerr<<"f = "<<flow<<endl;
		if(!vis[v]&&flow>0)
			dfs(v);
	}
}
vector<int>ans;
void solve()
{
	ans.clear();
//	cerr<<"s = "<<s<<",t = "<<t<<endl;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<di.edges.size();i+=2)
	{
		int u=di.edges[i].from,v=di.edges[i].to;
		double cap=di.edges[i].cap,flow=di.edges[i].flow;
//		printf("f<%d,%d>=%.4f,cap=%.4f\n",u,v,flow,cap);
		if(!vis[u]&&u>=1&&u<=n&&abs(cap-flow)<=eps)
		{//满流,则选择该点
			vis[u]=1;
			ans.push_back(u);
		}
	}
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
	while(cin>>n>>m)
	{
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=m;i++)
		{
			cin>>a[i]>>b[i];
			deg[a[i]]++,deg[b[i]]++;
		}
		if(m==0)
		{
			cout<<"1\n1\n";
			continue;
		}
		double l=0,r=m,res=0,wtf=1e12;
		int s=n+m+1,t=n+m+2;
		while(r-l>=1.0/n/n)
		{
			double mid=(l+r)/2;
			getmap(s,t,mid);
			double h= (double)m - di.Maxflow(s,t);
//			double h = (1.0*m*n - di.Maxflow(s,t))/2;//正权点-最大流得到最大权
//			cerr<<"h = "<<h<<", mid = "<<mid<<endl;
			if(h>0)//g值太大
				l=mid;
			else
				r=mid;
//			if(abs(h)<abs(wtf))
//				solve(),wtf=h;
		}
//		cerr<<"res = "<<(l+r)/2<<endl;
		getmap(s,t,l);
		di.Maxflow(s,t);
//        memset(vis,0,sizeof(vis));
//		dfs(s);
//		cout<<ans2<<'\n';
//		for(int i=1;i<=n;i++)
//			if(vis[i])
//				cout<<i<<'\n';
		solve();
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<'\n';
	}
	return 0;
}
/*
 *emm,答案一直搜不对,绝了
*/
