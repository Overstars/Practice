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
int deg[maxn],dfn[maxn],tim;
vector<int> G[maxn];
void dfs(int x,int fa)
{
	dfn[x]=++tim;
	for(auto &v:G[x])
	{
		if(v==fa)
			continue;
		dfs(v,x);
	}
}
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,cnt=0,u,v;
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		exit(0);
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	dfs(1,1);
	vector<int>rec;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			rec.push_back(i);
	sort(rec.begin(),rec.end(),[](const int &x,const int &y){
			return dfn[x]<dfn[y];
		});
	cnt=rec.size();
	cout<<cnt/2+cnt%2<<endl;
	for(int i=0;i<cnt/2;i++)
		cout<<rec[i]<<' '<<rec[cnt/2+cnt%2+i]<<endl;
	if(cnt%2)
		cout<<rec[cnt/2]<<' '<<1<<endl;
	return 0;
}


