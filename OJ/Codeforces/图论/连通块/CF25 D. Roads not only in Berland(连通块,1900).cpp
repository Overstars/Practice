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
struct edge
{
	int u,v;
};
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	vector<edge>rec;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		if(!Merge(u,v))
			rec.push_back({u,v});
	}
	set<int>tot;
	for(int i=1;i<=n;i++)
		tot.insert(findfa(fa[i]));
	int root=*tot.begin(),ans=tot.size()-1;
	tot.erase(root);
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		cout<<rec[i-1].u<<' '<<rec[i-1].v<<' ';
		int now=*tot.begin();
		tot.erase(now);
		cout<<root<<' '<<now<<endl;
	}
	return 0;
}
/*
 *这题倒是一读完就有思路
 *并查集维护连通块,将多余的边分组存起来
 *统计连通块数量与多余的边的关系
 *woc边的数量固定n-1,那必定有解啊
 *用时十分钟
*/

