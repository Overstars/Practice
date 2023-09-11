//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
vector<int>G[maxn];
vector<int>rec;
int n,t,ok=0,deg[maxn],t1[maxn],t2[maxn];
void findn(int x,int fa)
{
	if(x==n)
	{
		ok=1;
		rec.push_back(x);
		return;
	}
	if(ok)
		return;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		findn(v,x);
	}
	if(ok)
		rec.push_back(x);
}
void dfs(int *dis,int x,int fa)
{
	dis[x]=dis[fa]+1;
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(dis,v,x);
	}
}
int ans=0;
void dfs1(int x,int fa)
{
	t1[x]=t1[fa]+1;
	if(t1[x]>t2[x])
		return;
	if(t1[x]==t2[x])
	{
		ans=max(ans,t1[x]);
		return;
	}
	if(t1[x]<t2[x])
	{
		ans=max(ans,t1[x]+1);
		if(deg[x]==1)
			ans=max(ans,t2[x]);
	}
	for(int &v:G[x])
	{
		if(v==fa)
			continue;
		dfs1(v,x);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int u,v;
	cin>>n>>t;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	findn(1,1);
	if(t-1>=rec.size())//直接被抓到
	{
		return cout<<0<<endl,0;
	}
	reverse(rec.begin(),rec.end());
//	for(int &x:rec)
//		cout<<x<<' ';
	int rt=rec[t];//所在节点
//	printf("rt=%d\n",rt);
	t1[0]=t2[0]=-1;
	dfs(t2,n,0);
	for(int i=1;i<=n;i++)
	{
		if(t2[i]%2!=0)
			t2[i]++;
		t2[i]/=2;//处理O到每个点时间
//		printf("t1[%d]=%d,t2=%d\n",i,t1[i],t2[i]);
	}
	dfs1(rt,0);
//	for(int i=1;i<=n;i++)
//	{
//		if(t1[i]<=t2[i])
//		{
//			if(t1[i]==t2[i])
//				ans=max(ans,t1[i]);
//			else if(deg[i]==1)
//				ans=max(ans,t2[i]);
//			else
//				ans=max(ans,t1[i]+1);
//		}
//	}
	cout<<ans<<endl;
	return 0;
}
/*
1 2
2 3
3 4
4 5
5 6
6 7
*/

