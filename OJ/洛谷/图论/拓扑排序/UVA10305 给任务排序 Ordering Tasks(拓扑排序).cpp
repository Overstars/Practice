#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=105;
vector<int> G[maxn];
int n,m,top[maxn],node[maxn];
void topsort(void)
{
	priority_queue<int,vector<int>,greater<int> > QAQ;
//	queue<int> QAQ;
	for(int i=1;i<=n;i++)
		if(G[i][0]==0)
			QAQ.push(i);
	int cnt=0;
	while(!QAQ.empty())
	{
		int x=QAQ.top();
//		int x=QAQ.front();
		top[x]=++cnt;
		QAQ.pop();
		for(int i=1;i<G[x].size();i++)
		{
			if(--G[G[x][i]][0]==0)
				QAQ.push(G[x][i]);
		}
	}
	if(cnt!=n)//
		return;
	for(int i=1;i<=n;i++)
	{
		if(G[i][0])
			return;
	}
	for(int i=1;i<=n;i++)
		node[top[i]]=i;
	for(int i=1;i<=n;i++)
		printf("%d%c",node[i],i<n?' ':'\n');
	return;
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	while(cin>>n>>m&&(n||m))
	{
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			G[i].push_back(0);
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v][0]++;
		}
		topsort();
	}
	return 0;
}
