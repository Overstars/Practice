#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3e5+5,inf=0x3f3f3f3f,mod=998244353;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int> e[maxn];
int col[maxn];//黑白染色
bool dfs(int x,int c)
{
	col[x]=c;
	for(auto &v:e[x])
	{
		if(col[v]==c)
			return 0;
		if(col[v]==0&&!dfs(v,-c))
			return 0;
	}
	return 1;
}
bool isBipartite(int n)
{
	for(int i=1;i<=n;i++)
		if(col[i]==0&&!dfs(i,1))
			return 0;
	return 1;
}
ll now1=0,now2=0;
bool vis[3][maxn];
void dfs2(int x,int c,bool top)
{
	if(vis[c][x])
		return;
	vis[c][x]=1;
	if(c==0)//该点可奇可偶
	{
		now1=2,now2=1;//起始点奇偶
		vis[1][x]=vis[2][x]=1;
		for(auto &v:e[x])
			dfs2(v,1,0);
		for(auto &v:e[x])//起点为奇数,now1
			dfs2(v,2,1);
	}
	else{
		if(c==1)
		{
			if(top)
				now1=(now1*2)%mod;
			else
				now2=(now2*2)%mod;
		}
		for(auto &v:e[x])
			dfs2(v,((c==2)?1:2),top);
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
			col[i]=0;
			vis[0][i]=vis[1][i]=vis[2][i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(!isBipartite(n))
			cout<<0<<endl;
		else{
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				if(!vis[1][i]&&!vis[0][i])
				{
					dfs2(i,0,0);
					ll sum=(now1+now2)%mod;
//					ans=(ans*sum%mod+sum)%mod;
					if(ans==0)
						ans=sum;
					else
						ans=(ans*sum)%mod;
//					printf("%lld,%lld,ans=%lld\n",now1,now2,ans);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


