#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
int siz[maxn],id[maxn],dfn[maxn],tim=0;
void dfs(int x)
{
	dfn[x]=++tim;
	id[tim]=x;
	siz[x]=1;
	for(auto &v:G[x])
	{
		dfs(v);
		siz[x]+=siz[v];
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,u,k;
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		cin>>u;
		G[u].push_back(i);
	}
	dfs(1);
	while(q--)
	{
		cin>>u>>k;//第k个得到u下达的命令
		cout<<(siz[u]>=k?id[dfn[u]+k-1]:-1)<<endl;
	}
	return 0;
}
