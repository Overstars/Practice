//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct Dinic
{//复杂度O(n^2m)
	struct Edge
	{
		int from, to, cap, flow;
		Edge(int u, int v, int c, int f):
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
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cap)
	{
//		edges.emplace_back(Edge(from, to, cap, 0));//魔改蔡队模板
//		edges.emplace_back(Edge(to, from, 0, 0)); //反向弧,初始容量为0
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
//		memset(d, 0, sizeof(d));
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
				if (!vis[e.to] && e.cap > e.flow)
				{//只考虑残量网络中的弧
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;//构造分层图
					q.push(e.to);
				}
			}
		}
		return vis[t];//有无增广路,s->t
	}
	int DFS(int x, int a)//x为当前点,a为当前边上流量
	{//在层次图上向t延伸,多路增广
		if(x==t||a==0)//到达目标/流量为0断流
			return a;
		int flow = 0, f;
		for(int& i=cur[x];i<G[x].size();i++)//从上一次x遍历跑到的点开始跑
		{//从上次考虑的弧
			Edge& e = edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow))) > 0)
			{//只从层数编号较小的点到下一层的点
				e.flow += f;//该路径上边流量都增加f
				edges[G[x][i]^1].flow -= f;//方便反悔
				flow += f;
				a -= f;//用去可增广量
				if(a==0)//a等于0及时退出
					break;//当a!=0,说明当前节点还存在另一个增广路分支。
			}
		}
		if(!flow)//增广后容量满了
			d[x] = -1;//炸点优化,不必要的点下一次就不用遍历
		return flow;//返回x节点最大流量,传递到上一级
	}
	int Maxflow(int s, int t)
	{
		this->s = s, this->t = t;
		int flow = 0;
		while (BFS())//不停地用bfs构造分层网络，然后用dfs沿着阻塞流增广
		{
			memset(cur, 0, sizeof(cur));//建完分层图后cur也要初始化
			flow += DFS(s,inf);
		}
		return flow;
	}
} di;
const int MAXN=200010;
int phi[MAXN+1],prime[MAXN+1],psize;//psize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist(void)
{
	memset(isprime,1,sizeof(isprime));
	psize=0;
	isprime[1]=false;
	phi[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++psize]=i,phi[i]=i-1;
		for(int j=1;j<=psize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
struct node
{//能量,魔力,等级
	int p,c,l;
	node(int p,int c,int l):
		p(p),c(c),l(l){}
};
signed main(signed argc, char const *argv[])
{
	getlist();
//	cout<<isprime[7]<<endl;
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,ans=inf,x,y,z;
	cin>>n>>k;
	vector<node> rec[3];//1,奇数,偶数
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;//能量,魔力,等级
		if(y==1)
			rec[0].push_back(node(x,y,z));
		else if(y&1)
			rec[1].push_back(node(x,y,z));
		else
			rec[2].push_back(node(x,y,z));
	}
	sort(rec[0].begin(),rec[0].end(),[](const node &a,const node &b){
			return a.p>b.p;
		});
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1,sum=0;
		int s=n+1,t=s+1,sf=0,sf2=rec[1].size();
		di.init(t+10);
		if(rec[0].size())
		{
			for(auto &i:rec[0])
			{
				if(i.l<=mid)
				{
					di.AddEdge(s,1,i.p);
					sum+=i.p;
					sf++;
					for(int j=0;j<rec[2].size();j++)
					{
						if(rec[2][j].l>mid)
							continue;
						if(isprime[1+rec[2][j].c])
							di.AddEdge(1,sf+sf2+j+1,inf);
					}
					break;
				}
			}
		}
		for(int i=0;i<rec[1].size();i++)
		{
			if(rec[1][i].l>mid)
				continue;
			sum+=rec[1][i].p;
			di.AddEdge(s,sf+i+1,rec[1][i].p);
			for(int j=0;j<rec[2].size();j++)
			{
				if(rec[2][j].l>mid)
					continue;
//				cerr<<rec[1][i].c<<" + "<<rec[2][j].c<<endl;
				if(isprime[rec[1][i].c+rec[2][j].c])
					di.AddEdge(sf+i+1,sf+sf2+j+1,inf);
			}
		}
//		cerr<<"sum = "<<sum<<endl;
		for(int j=0;j<rec[2].size();j++)
		{
			if(rec[2][j].l>mid)
				continue;
			di.AddEdge(sf+sf2+j+1,t,rec[2][j].p);
			sum+=rec[2][j].p;
		}
		int flow=di.Maxflow(s,t);
		int now=sum-flow;
//		cerr<<"mid = "<<mid<<", now = "<<now<<endl;
//		cerr<<"sum = "<<sum<<", flow = "<<flow<<endl;
		if(now>=k)
		{
			r=mid-1;
			ans=min(ans,mid);
		}
		else
			l=mid+1;
	}
	cout<<(ans<inf?ans:-1)<<endl;
	return 0;
}
/*
 *2021-03-31-19.22.04
 *p总能量不小于k,不能取l高于自己等级的牌,取出来的牌两两c之和不能出现质数
 *求最小等级x
 *集合内两两元素不冲突,容易想到最大独立集
 *要弄成二分图,可以奇数一组,偶数一组
 *1+1去不掉,留一个价值最大的1
*/

