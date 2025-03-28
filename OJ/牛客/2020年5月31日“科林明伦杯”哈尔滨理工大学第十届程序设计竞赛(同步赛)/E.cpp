#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2005,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int> G[maxn];//注意使用前clear()
int linker[maxn];
bool used[maxn];
bool dfs(int x)//
{
	for(auto &v:G[x])
		if(!used[v])//在右边找
		{
			used[v]=1;
			if(!linker[v]||dfs(linker[v]))
			{
				linker[v]=x;//记录右边v号匹配
				return 1;
			}
		}
	return 0;//未找到增广路
}
ll hungry(int n)
{
	ll ans=0;
	memset(linker,0,sizeof(linker));
	for(int i=1;i<=n;i++)//遍历左面
	{
		memset(used,0,sizeof(used));
		if(dfs(i))//能找到增广路
			ans++;
	}
	return ans;
}
ll a[maxn],b[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i]>b[j])
					G[i].push_back(j);
		printf("%lld",hungry(n));
	}
	return 0;
}


