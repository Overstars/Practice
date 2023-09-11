//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
vector<int>G[maxn];
int n,c[maxn],deg[maxn],del[maxn];
int bfs(int x)
{
	int done=0,ans=0;
	queue<int> q[4];
	for(int i=1;i<=n;i++)
		del[i]=0;
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			q[c[i]].push(i);
	while(done<n)
	{
		while(!q[x].empty())
		{
			int u=q[x].front();
			q[x].pop();
			done++;
			ans++;
			for(int &v:G[u])
			{
				del[v]++;
				if(del[v]==deg[v])
					q[c[v]].push(v);
			}
		}
		x++;
		if(x==4)
			x=1;
		if(done==n)
			break;
		ans++;
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int k,u;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		deg[i]=k;
		for(int j=1;j<=k;j++)
		{
			cin>>u;
			G[u].push_back(i);
		}
	}
	int ans=inf;
	for(int i=1;i<=3;i++)
		ans=min(ans,bfs(i));
	cout<<ans<<endl;
	return 0;
}


