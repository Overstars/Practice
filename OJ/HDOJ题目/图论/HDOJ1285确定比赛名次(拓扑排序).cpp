#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=505;
int Top[maxn],Node[maxn],n,m;
vector<int> G[maxn];
void topsort(void)
{
	priority_queue<int,vector<int>,greater<int> > QAQ;//小根堆
	for(int i=1;i<=n;i++)
		if(G[i][0]==0)//入度为0
			QAQ.push(i);
	int cnt=0;
	while(!QAQ.empty())
	{
		int x=QAQ.top();
		Top[x]=++cnt;//记录拓扑排序,x节点的次序
		QAQ.pop();
		for(int i=1;i<G[x].size();i++)
		{
			if(--G[G[x][i]][0]==0)//去掉x节点后,下一节点入度变为0
				QAQ.push(G[x][i]);
		}
//		cout<<"IN QUEUE"<<endl;
	}
	if(cnt!=n)//有不连通的
		return;
	for(int i=1;i<=n;i++)
	{
		if(G[i][0])//有环图
			return;
	}
	for(int i=1;i<=n;i++)
		Node[Top[i]]=i;//反函数,Node[i]=x:第i号为x
	for(int i=1;i<=n;i++)
		printf("%d%c",Node[i],i<n?' ':'\n');
	return;
}
int main()
{
	while(cin>>n>>m)//n个队伍,m场比赛
	{
		for(int i=1;i<=n;i++)//初始化
		{
			G[i].clear();
			G[i].push_back(0);//G[i][0]记录入度
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v][0]++;//v点的入度+1
		}
		topsort();
	}
	return 0;
}
