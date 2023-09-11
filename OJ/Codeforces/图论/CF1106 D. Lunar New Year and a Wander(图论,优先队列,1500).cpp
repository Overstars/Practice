#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> G[maxn],ans;
bool vis[maxn];
void bfs(int x)
{
	priority_queue<int,vector<int>,greater<int> >QAQ;
	QAQ.push(x);
	vis[x]=1;
	while(!QAQ.empty())
	{
		int u=QAQ.top();
		ans.push_back(u);
		QAQ.pop();
		for(auto &v:G[u])
		{
			if(vis[v])
				continue;
			vis[v]=1;
			QAQ.push(v);
		}
	}
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);
	for(auto &i:ans)
		cout<<i<<' ';
	return 0;
}
/*
 *Kn无向图,从1出发,可以重复经过节点
 *依次记录初次经过节点,求最后字典序最小序列
 */
