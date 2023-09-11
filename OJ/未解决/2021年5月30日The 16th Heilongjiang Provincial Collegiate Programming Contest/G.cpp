//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=4e6+5,inf=0x3f3f3f3f,mod=1000000007;
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
int dfn[maxn],low[maxn],stk[maxn],belong[maxn],index=0,cnt=0,tim=0;
vector<int>G[maxn];
bool vis[maxn];
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++tim;
	vis[x]=1;//标记在栈中
	stk[++index]=x;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		if(!vis[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
		}
		else
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]&&vis[x])
	{
		cnt++;//双连通分量个数
		do{
//			fprintf(stderr,"bel[%d]=%d\n",stk[index],cnt);
			belong[stk[index]]=cnt;
//			siz[cnt]++;
			vis[stk[index]]=0;
			index--;
		}while(stk[index+1]!=x);
	}
}
bool flag=0,isc[maxn];
void dfs(int x,int fa)
{
	dfn[x]=low[x]=++tim;
	int child=0;
	for(auto &v:G[x])
	{
		if(!dfn[v])
		{
			dfs(v,x);
			low[x]=min(low[x],low[v]);
			if(x==fa)
				child++;
			if(x!=fa&&low[v]>=dfn[x])
				isc[x]=1;
		}
		else if(v!=fa)
			low[x]=min(low[x],dfn[v]);
	}
	if(x==fa&&child>=2)
		isc[x]=1;
}
int n,m;
//char s[2005][2005];
//vector<int> g[maxn];
inline int id(int x,int y)
{
	return m*(x-1)+y;
}
int nx[]={0,1,0,-1},ny[]={1,0,-1,0};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m;
	char (*s)[2005];
	s=new char[2005][2005];
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	vector<int>rec;
//	vector<pii>rec2;
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')
				continue;
			rec.push_back(id(i,j));
			int u=id(i,j),v;
			for(int k=0;k<4;k++)
			{
				int xx=i+nx[k],yy=j+ny[k];
				if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]=='#')
					continue;
				ok=1;
				v=id(xx,yy);
				G[u].push_back(v);
//				rec2.push_back(pii(u,v));
//				G[id(xx,yy)].push_back(id(i,j));
			}
		}
	}
	delete s;
	int ans=0,inc=0;
	for(auto &i:rec)
		if(!dfn[i])
		{
			tarjan(i,i);
			ans++;
		}
//	ans=cnt;
//	for(auto &i:rec2)
//	{
//		ok=1;
//		if(belong[i.ff]==belong[i.ss])
//			continue;
////		g[belong[i.ff]].push_back(belong[i.ss]);
////		fprintf(stderr,"%d->%d\n",i.ff,i.ss);
//		deg[belong[i.ss]]++;
//	}
//	for(int i=1;i<=cnt;i++)
//	{
//		if(siz[i]==1)
//			inc=max(inc,deg[i]-1);
//		else if(g[i].size()>=1)//连接其他点
//			inc=max(inc,1);
//	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	tim=0;
	for(auto &i:rec)
		if(!dfn[i])
			dfs(i,i);
	for(auto &i:rec)
		if(isc[i])
		{
			set<int>st;
			for(auto &v:G[i])
				st.insert(belong[v]);
//			fprintf(stderr,"c=%d,inc=%d\n",i,(int)st.size()-1);
			inc=max(inc,(int)st.size()-1);
			inc=max(inc,1);//同连通分量的
		}
//	fprintf(stderr,"ans=%d,inc=%d\n",ans,inc);
	if(ok)
		cout<<ans+inc<<endl;
	else
		cout<<ans-1<<endl;
	return 0;
}
/*
4 4
#...
#.#.
....
#.##
ans=3

3 3
#.#
...
#.#

3 3
#..
...
..#
ans=2

5 4
....
###.
....
.###
....
ans=2

4 4
##..
##..
...#
...#
ans=2

3 3
###
###
###

2 2
..
..
ans=1

3 3
.#.
#.#
.#.
ans=4

1 2
..
ans=1

5 5
##...
##...
.....
...##
...##
ans=2

7 7
##...##
##...##
..#.#..
.......
..#.#..
##...##
##...##
*/
/*
 * 2021-05-30-12.48.38
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月30日The 16th Heilongjiang Provincial Collegiate Programming Contest\G.cpp
 *
*/

