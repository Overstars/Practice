//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=5010,inf=0x3f3f3f3f,mod=1000000007;
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
struct edge
{
	int u,v,c;
};
//int deg[maxn],top[maxn];
vector<pii>G[maxn];
//bool topo(int n)
//{
//	queue<pii>q;
//	for(int i=1;i<=n;i++)
//		if(deg[i]==0)
//			q.push(i);
//	int cnt=0;
//	while(!q.empty())
//	{
//		pii x=q.front();
//		q.pop();
//		top[x.ff]=++cnt;
//		for(pii &v:G[x])
//			if(--deg[v.ff]==0)
//				q.push(v);
//	}
//	return cnt!=n;
//}
vector<edge>E;
//bool vis[maxn],cir=0;
//vector<int>rec;
//int now=0;
//void dfs(int x,int fa)
//{
//	if(vis[x])
//	{
//		cir=1;
//		return;
//	}
//	vis[x]=1;
//	for(pii &e:G[x])
//	{
//		if(e.ff==fa)
//			continue;
//		rec.push_back(e.ss);
//		dfs(e.ff,x);
//		if(now==3)
//			continue;
//		if(E[e.ss].c==2)//全0,涂1
//		{//有2,0,剩下的涂1
//			if(now==1)//1,2
//				now=3;
//			else
//				now=2;
//		}
//		else if(E[e.ss].c==1)
//		{
//			if(now==2)
//				now=3;
//			else
//				now=1;
//		}
//	}
//	vis[x]=0;
//	return;
//}
bool flag=0;
int vis[maxn];
void dfs(int x)
{
	vis[x]=1;
	for(pii &e:G[x])
	{
		if(vis[e.ff]==0)//树边
			dfs(e.ff),E[e.ss].c=1;
		else if(vis[e.ff]==1)//返祖边
			E[e.ss].c=2,flag=1;
		else//前向边和横边
			E[e.ss].c=1;
	}
	vis[x]=2;//访问完毕
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		E.push_back({u,v,0});
		G[u].push_back(pii(v,i-1));
//		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
//	cout<<(topo(n)?2:1)<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		memset(vis,0,sizeof(vis));
//		rec.clear();
//		now=cir=0;
//		dfs(i,i);
//		flag|=cir;
//		for(int &x:rec)//0->全0,1->有01,2->有0,2,3->有012
//			if(E[x].c==0)
//			{
//				if(cir&&now==0)
//				{
//					E[x].c==2;
//					cir=0;
//				}
//				else
//					E[x].c=((now==0||now==2||now==3)?1:2);
//			}
//	}
	cout<<(flag?2:1)<<endl;
	for(auto &e:E)
		cout<<e.c<<' ';
	return 0;
}
/*
 *有向图,染色,n,m都小于5e3
 *两个环的公共边染成第二种颜色
 *树论找返祖边...
 */
/*
6 9
1 2
2 3
3 1
1 4
4 3
3 5
5 2
2 6
6 1
*/
