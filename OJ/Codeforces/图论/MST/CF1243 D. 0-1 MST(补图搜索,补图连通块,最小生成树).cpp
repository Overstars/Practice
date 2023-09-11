#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
set<int> G[maxn];//使用set存原图,加快速度
int bfs(int n)
{
	int ans=0;
	set<int> unvis;//已访问节点,从原图上删除
	for(int i=1;i<=n;i++)
		unvis.insert(i);
	while(!unvis.empty())//BFS求连通块个数
	{
		ans++;//从未访问集里拿出新的元素,新增一个连通块
		int now=*(unvis.begin());//取出第一个
        unvis.erase(now);

        queue<int> QwQ;
        QwQ.push(now);
        while(!QwQ.empty())//找出与now联通的节点,并从unvis中删去
		{
			int nex=QwQ.front();//与now联通的点之一
			QwQ.pop();
			vector<int> v1;//记录要删去的节点
			for(auto i:unvis)//遍历未访问集合
				if(G[nex].find(i)==G[nex].end())
				{//now与i由补边连接,权重为0
					v1.push_back(i);
					QwQ.push(i);//放进队列里,继续向下求联通点
				}
			for(int i=0;i<v1.size();i++)
				unvis.erase(v1[i]);//在集合中删去搜到的联通节点
		}
	}
	return ans;
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;//m条边权重为1
	for(int i=1;i<=m;i++)//无向边
	{
		cin>>a>>b;//求最小生成树
		G[a].insert(b);
		G[b].insert(a);
	}
	cout<<bfs(n)-1<<endl;
	return 0;
}
