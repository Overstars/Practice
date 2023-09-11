//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int d[maxn];
vector<int>G[maxn];
int solve(int n,int m)
{
	vector<bool> vis(n+1,0);
	queue<pii>q;
	for(int i=1;i<=n;i++)
		if(d[i]==0)
			q.push(pii(i,0));
	int cnt=0;
	while(!q.empty())
	{
		pii now=q.front();
		q.pop();
		if(now.ss)
			cnt++;
//		cerr<<"x = "<<now.ff<<", d = "<<now.ss<<endl;
		vis[now.ff]=1;
		if(cnt==m)
			return now.ss;
		for(int &v:G[now.ff])
		{
			if(vis[v])
				continue;
			q.push(pii(v,now.ss+1));
		}
	}
	return 0;
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
		cin>>d[i];
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<solve(n,m)<<endl;
	return 0;
}
/*
 *在树中选m个点使得这m个点到关键点(d=0)的最小距离最大值最小
 *怪欸不是从关键点开始bfs就好了吗
 *前置知识:https://www.luogu.com.cn/problem/P3942
*/

