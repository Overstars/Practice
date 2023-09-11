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
struct edge
{
	int u,v;
	edge(int u,int v):
		u(u),v(v){}
};
vector<int> G[maxn];
vector<edge>ans,ans2;
bool vis[maxn];
int n,m,top[maxn],deg[maxn];//节点i拓扑顺序为top[i]
bool ok=1;
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,t,u,v;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		ans2.clear();
		ans.clear();
		for(int i=1;i<=n;i++)
			vis[i]=0,G[i].clear(),deg[i]=0;
		for(int i=1;i<=m;i++)
		{
			cin>>t>>u>>v;
			if(t)
			{
				G[u].push_back(v),deg[v]++;
				ans2.push_back({u,v});
			}
			else
				ans.push_back({u,v});
		}
		queue<int> QAQ;//若要求字典序用优先队列
		for(int i=1;i<=n;i++)
			if(deg[i]==0)//G[i][0]表示入度
				QAQ.push(i);
		int tim=0;
		while(!QAQ.empty())
		{
			int x=QAQ.front();
			top[x]=++tim;//top[x]表示x号节点的次序编号
			QAQ.pop();
			for(auto &v:G[x])
			{
				if(--deg[v]==0)//节点入度为0时入队
					QAQ.push(v);
			}
		}
		if(tim!=n)//
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			for(auto &x:ans)
				if(top[x.u]<top[x.v])
					cout<<x.u<<' '<<x.v<<endl;
				else
					cout<<x.v<<' '<<x.u<<endl;
			for(auto &x:ans2)
				cout<<x.u<<' '<<x.v<<endl;
		}
	}
	return 0;
}


