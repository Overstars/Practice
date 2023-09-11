//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
int val[maxn];
vector<int>G[maxn];
bool vis[maxn];
signed main()
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
		vector<int>rec;
		for(int i=1;i<=n;i++)
		{
			cin>>val[i];
			G[i].clear();
			vis[i]=0;
			fa[i]=i;
			rec.push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		sort(rec.begin(),rec.end(),[](const int &a,const int &b){
				return val[a]>val[b];
			});
		ll ans=0;
		for(int &u:rec)
		{
			vis[u]=1;//按点权顺序将u加入
			for(int &v:G[u])
			{
				if(!vis[v])
					continue;
				int y=findfa(v);//v节点在之前已加入,找到v节点的根
				if(u==y)
					continue;
				ans+=val[y]-val[u];
				fa[y]=u;//将新加进来的作为连通块根结点,方便得到最小权值
			}
		}
		for(int i=1;i<=n;i++)
			if(fa[i]==i)//最后将每个连通块根节点加上
				ans+=val[i];
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
3 2
4 5 3
1 2
2 3
*/
