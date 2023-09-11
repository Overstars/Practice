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
int n,p[maxn],fa[maxn];
char s[maxn];
bool mp[maxn][maxn],vis[maxn];
set<int>ans[maxn];
void bfs(int s)
{
	ans[s].insert(p[s]);
	queue<int>QAQ;
	vis[s]=1;
	fa[s]=s;
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
			fa[i]=s;
			ans[s].insert(p[i]);
			QAQ.push(i);
		}
	}
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
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		cin>>s+1;
		for(int j=1;j<=n;j++)
			if(s[j]=='1')
				mp[i][j]=1;
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		bfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		int now=*ans[fa[i]].begin();
		cout<<now<<' ';
		ans[fa[i]].erase(now);
	}
	return 0;
}


