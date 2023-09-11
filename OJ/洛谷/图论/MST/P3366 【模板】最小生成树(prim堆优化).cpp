#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5005,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
bool vis[maxn];
vector<pii> G[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(make_pair(w,v));
		G[v].push_back(make_pair(w,u));
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	int ans=0;
	for(auto &v:G[1])//从节点1开始
		pq.push(v);
	vis[1]=1;
	while(!pq.empty())
	{//取出可达当前树的最短边
		pii now=pq.top();
		pq.pop();
		if(!vis[now.second])
		{
			ans+=now.first;
			vis[now.second]=1;
			n--;
		}
		for(auto &v:G[now.second])
			if(!vis[v.second])//已经访问过的话,这个边是加进来了的
				pq.push(v);
	}
	if(n==1)
		cout<<ans<<endl;
	else
		cout<<"orz"<<endl;
	return 0;
}


