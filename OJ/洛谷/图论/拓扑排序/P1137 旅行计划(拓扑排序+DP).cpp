#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=100005;
vector<int> G[maxn];
int dp[maxn],into[maxn],top[maxn],n,m;
void topsort(void)
{
	for(int i=1;i<=n;i++)
		dp[i]=1;//以第i个城市结尾最多游览的城市数量
	queue<int> QAQ;
	for(int i=1;i<=n;i++)
		if(into[i]==0)
			QAQ.push(i);
	int cnt=0;
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		top[x]=++cnt;
		for(int i=0;i<G[x].size();i++)
		{
			dp[G[x][i]]=max(dp[G[x][i]],dp[x]+1);
			if(--into[G[x][i]]==0)
				QAQ.push(G[x][i]);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		into[v]++;
	}
	topsort();
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<endl;
	return 0;
}
