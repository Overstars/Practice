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
//const int inf=0x3f3f3f3f;
const int maxn=2010;
double eps=1e-10,inf=1e10;
//#define DEBUG
struct edge
{
	int v,nex;
	double flow;
	edge(){}
	edge(int v,double flow,int nex):
		v(v),flow(flow),nex(nex){}
} E[maxn<<1];
int head[maxn],d[maxn],cnt=0,ans=0;
void addE(int u,int v,double w=0)
{
	E[++cnt].v=v;
	E[cnt].flow=w;
	E[cnt].nex=head[u];
	head[u]=cnt;
}
void add(int u,int v,double w)
{
	addE(u,v,w);
	addE(v,u,0);
}
bool bfs(int s,int t)
{
	queue<int>q;
	memset(d,-1,sizeof(d));
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];~i;i=E[i].nex)
		{
			int v=E[i].v;
			if(E[i].flow>eps&&d[v]==-1)
			{
				d[v]=d[x]+1;
				q.push(v);
			}
		}
//		printf("...\n");
	}
	return d[t]!=-1;//有增广路
}
double dfs(int x,double maxf,int &t)
{//未加当前弧优化
//	printf("%d\n",++ans);
	if(x==t)
		return maxf;
	double flow=0,f;
	for(int i=head[x];~i;i=E[i].nex)
	{
		int v=E[i].v;
		if(E[i].flow&&d[v]==d[x]+1)
		{
			f=dfs(v,min(maxf-flow,E[i].flow),t);
			E[i].flow-=f;
			E[i^1].flow+=f;
			flow+=f;
			if(flow==maxf)
				return flow;
		}
	}
	if(flow==0)
		d[x]=-2;
	return flow;
}
inline double dinic(int s,int t)
{
	double MaxFlow=0,tmp;
	while(bfs(s,t))
		while(tmp=dfs(s,inf,t))
			MaxFlow+=tmp;
	return MaxFlow;
}
int a[maxn],b[maxn],n,m;
inline double check(int s,int t,double mid)
{
	memset(head,-1,sizeof(head));
	cnt=0;
	for(int i=1;i<=n;i++)
		add(i,t,mid);
	for(int i=1;i<=m;i++)
	{
		add(n+i,a[i],inf);
		add(n+i,b[i],inf);
		add(s,n+1,1.0);
	}
	return ((double)m-dinic(s,t));
}
bool vis[maxn];
void findx(int x)
{
	vis[x]=1;
	if(x>=1&&x<=n)
		ans++;
	for(int i=head[x];~i;i=E[i].nex)
	{
		int v=E[i].v;
		if(!vis[v]&&E[i].flow)
			findx(v);
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
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i];
	if(m==0)
		return cout<<"1\n1"<<endl,0;
	double l=0,r=m+1,wtf=1e10;
	int s=n+m+1,t=n+m+2;
//	cerr<<check(s,t,0)<<endl;
	while(r-l>=1.0/n/n)
	{
		double mid=(l+r)/2,now=check(s,t,mid);
		if(now>0)
			l=mid;//增大g
		else
			r=mid;
//		if(abs(now)<eps)
//			wtf=min(wtf,mid);
//		printf("mid = %.3f,h = %.3f\n",mid,check(s,t,mid));
	}
	check(s,t,l);
	ans=0;
	findx(s);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
		if(vis[i])
			cout<<i<<'\n';
	return 0;
}

