//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
bool vis[maxn];
set<int>G[maxn],unvis;
int qq[maxn];
int bfs(int x,int n)
{
//	queue<int>q;
//	q.push(x);
	int siz=0,st=0,ed=0;
	qq[++ed]=x;
	unvis.erase(x);
	vis[x]=1;
	while(st<ed)
	{
		x=qq[++st];
//		unvis.erase(x);
//		x=q.front();
//		q.pop();
//		if(vis[x])
//			continue;
		vis[x]=1;
		siz++;
		vector<int>tmp;//记录未访问的且不和x相连的
		for(int v:G[x])
			if(unvis.count(v))
				tmp.push_back(v),unvis.erase(v);
		for(int v:unvis)//剩下的是未访问且相邻的
			qq[++ed]=v;
		unvis.clear();
		for(int v:tmp)
			unvis.insert(v);
	}
	return siz;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		unvis.insert(i);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].insert(v);
		G[v].insert(u);
	}
	vector<int>ans;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			ans.push_back(bfs(i,n));
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int &x:ans)
		cout<<x<<' ';
	return 0;
}


