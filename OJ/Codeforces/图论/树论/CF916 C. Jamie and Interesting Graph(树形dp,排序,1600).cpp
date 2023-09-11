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
int deg[maxn],ans[maxn],siz[maxn];//x子树的叶子数量
vector<int>G[maxn];
void dfs(int x)
{
	if(deg[x]==1&&x!=1)
		siz[x]=1;
	for(auto &v:G[x])
	{
		dfs(v);
		siz[x]+=siz[v];
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v,p,cnt=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>p;
		G[p].push_back(i);
		deg[i]++;
		deg[p]++;
	}
	if(n==1)
		return cout<<1<<endl,0;
	dfs(1);
	sort(siz+1,siz+n+1);
	int now=0,j=1,col=0;
	for(int i=1;i<=n;i++)
	{
		for(;now<i;j++)//当前快乐结点的数量
		{//使j节点变为快乐结点的颜色
			if(col<siz[j])
				col=siz[j];
			now++;
		}
		ans[i]=col;
		cout<<ans[i]<<' ';
	}
	return 0;
}


