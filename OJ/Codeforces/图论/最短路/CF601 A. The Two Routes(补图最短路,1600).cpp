#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
int t[maxn],b[maxn];
bool vis[maxn],mp[maxn][maxn];
bool bfs(int n,int s)
{
	t[s]=b[s]=0;
	queue<int>QAQ;
	QAQ.push(s);
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]||!mp[x][i])
				continue;
			vis[i]=1;
			t[i]=min(t[i],t[x]+1);
			QAQ.push(i);
		}
	}
	if(t[n]>=inf)//不能到达
		return 1;
	memset(vis,0,sizeof(vis));
	QAQ.push(s);
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]||mp[x][i])
				continue;
			vis[i]=1;
			b[i]=min(b[i],b[x]+1);
			QAQ.push(i);
		}
	}
	if(b[n]>=inf)//不能到达
		return 1;
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(b,inf,sizeof(b));
	memset(t,inf,sizeof(t));
	int n,m,u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
	if(bfs(n,1))
		cout<<-1<<endl;
	else
		cout<<max(t[n],b[n])<<endl;
	return 0;
}


