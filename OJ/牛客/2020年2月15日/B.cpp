#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
vector<int> G[maxn];
int tot=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn],siz[maxn];
bool vis[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++Index]=x;
	vis[x]=1;
	for(auto &v:G[x])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;
		do{
			belong[stk[Index]]=cnt;
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
//vector<int>Gra[maxn];
int ans[maxn];
int dfs(int rt,int x,int tim)
{
	if(ans[x]==0)
		dfs(rt,G[x][0],tim+1);
	else
		ans[rt]=ans[x]+tim;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		G[i].push_back(v);
		if(i==v)
			ans[i]=1;
//		G[v].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
			tarjan(i);
		siz[belong[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(siz[belong[i]]!=1)
			ans[i]=siz[belong[i]];//环上的点
//	for(int i=1;i<=n;i++)
//		printf("siz[%d]=%d\n",i,siz[i]);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==0)
		{
			dfs(i,G[i][0],1);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res=max(res,ans[i]);
	}
	cout<<res<<endl;
	return 0;
}


