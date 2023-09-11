#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int> G[maxn],g[maxn];
bool vis[maxn],ok[maxn];
int dist[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,s,t;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>t;
		G[s].push_back(t);
		g[t].push_back(s);//反向建图+搜索
	}
	cin>>s>>t;
	queue<int>qaq;
	qaq.push(t);
	while(!qaq.empty())
	{
		int x=qaq.front();
		qaq.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(auto &v:g[x])
			if(!vis[v])
				qaq.push(v);
	}//处理出可达t的点
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		for(auto &v:G[i])
			if(!vis[v])
			{//存在不可达t节点
				flag=0;
				break;
			}
		ok[i]=flag;//处理出可选节点
	}
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	qaq.push(s);
	dist[s]=0;
	while(!qaq.empty())
	{
		int x=qaq.front();
		qaq.pop();
		if(vis[x]||!ok[x])
			continue;
		vis[x]=1;
		for(auto &v:G[x])
			if(ok[v])
			{
				dist[v]=min(dist[v],dist[x]+1);
				qaq.push(v);
			}
	}
	cout<<(dist[t]==inf?-1:dist[t])<<endl;
	return 0;
}


