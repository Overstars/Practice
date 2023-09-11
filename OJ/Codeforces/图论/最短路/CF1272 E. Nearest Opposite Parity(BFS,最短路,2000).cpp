#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn],dist[maxn];
vector<int> G[maxn];
int main()
{
	memset(dist,-1,sizeof(dist));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	queue<int> QAQ;
	for(int i=1;i<=n;i++)//反向建边
	{
		if(i+a[i]<=n)
			G[i+a[i]].push_back(i);
		if(i-a[i]>=1)
			G[i-a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)//将所有能一步到位的预处理出来
	{
		int x=i+a[i];
		if(x<=n&&(a[x]^a[i])&1)//奇偶性不同
			dist[i]=1;
		x=i-a[i];
		if(x>=1&&(a[x]^a[i])&1)
			dist[i]=1;
		if(dist[i]==1)
			QAQ.push(i);
	}
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		for(auto &v:G[x])
			if(dist[v]==-1)//这里没有能一步跳到奇偶性不同的点
			{
				dist[v]=dist[x]+1;
				QAQ.push(v);
			}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<' ';
	}
	return 0;
}
