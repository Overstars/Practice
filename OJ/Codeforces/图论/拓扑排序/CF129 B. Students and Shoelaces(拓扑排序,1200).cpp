#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
vector<int> G[maxn];
int deg[maxn];
int topsort(int n)
{
	int sum=0;
	queue<int>QAQ,TAT;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			QAQ.push(i);
	while(!QAQ.empty())
	{
		sum++;
		while(!QAQ.empty())
		{
			int x=QAQ.front();
			QAQ.pop();
			for(auto &v:G[x])
			{
				deg[x]--;
				deg[v]--;
			}
		}
		for(int i=1;i<=n;i++)
			if(deg[i]==1)
				QAQ.push(i);
	}
	return sum;
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{//不会有重边
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	cout<<topsort(n)<<endl;
	return 0;
}
