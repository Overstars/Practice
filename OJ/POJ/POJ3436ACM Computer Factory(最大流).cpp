#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
using namespace std;
const int arraysize=1005;
const int inf=0x3f3f3f3f;
const int maxData=0x7fffffff;
int capacity[arraysize][arraysize]; //记录残留网络的容量
int flow[arraysize]; //标记从源点到当前节点实际还剩多少流量可用
int pre[arraysize];  //标记在这条路径上当前节点的前驱,同时标记该节点是否在队列中
int n,m;//点数,边数
queue<int> myqueue;
int BFS(int src,int des)
{
    while(!myqueue.empty())   //队列清空
        myqueue.pop();
    for(int i=1;i<=n;++i)
        pre[i]=-1;//目前无前驱,且不在队列中
    pre[src]=0;
    flow[src]= inf;//起点的剩余流量设为inf
    myqueue.push(src);//从源点开始广搜
    while(!myqueue.empty())
    {
        int index = myqueue.front();
        myqueue.pop();
        if(index == des)   //找到了增广路径
            break;//到达汇点
        for(int i=1;i<=n;++i)//遍历n个节点
        {//非s,容量大于0,且不在队列中
            if(i!=src && capacity[index][i]>0 && pre[i]==-1)
            {
                 pre[i]=index; //记录前驱(可通过index到达i)
                 flow[i]=min(capacity[index][i],flow[index]);//流过该点的流量
                 //关键：迭代的找到增量
                 myqueue.push(i);//将i推入队列,尝试找到i点流向其他点的流量
            }
        }
    }
    if(pre[des]==-1)      //残留图中不再存在增广路径
        return -1;
    else
        return flow[des];
}
int maxFlow(int src,int des)
{
    int increasement= 0;
    int sumflow = 0;
    while((increasement=BFS(src,des))!=-1)//仍然存在增广路径
    {
         int k = des;          //利用前驱寻找路径
         while(k!=src)
         {
              int last = pre[k];//从汇点回溯...
              capacity[last][k] -= increasement; //改变正向边的容量(保证不为负)
              capacity[k][last] += increasement; //改变反向边的容量(同样不会为负)
              k = last;
         }
         sumflow += increasement;//成功找增广路径
    }
    return sumflow;
}
int mach[105][10],q[55];//记录i机器的输入输出与容量
int main()
{
    int start,endt,ci;
    while(cin>>n>>m>>start>>endt)//点数,边数,源点,汇点
    {
        memset(capacity,0,sizeof(capacity));
        memset(flow,0,sizeof(flow));
        for(int i=0;i<n;++i)
        {
            int u,v;
            cin>>u>>v>>ci;//边的两端及权值
            if(u==v)               //考虑起点终点相同的情况
               continue;
            capacity[u][v] +=ci;     //此处注意可能出现多条同一起点终点的情况
        }
        cout<<maxFlow(start,endt)<<endl;
    }
    //将p个零件作为节点建图,
    int p,n;
    while(cin>>p>>n)//零件p,车床数n
	{
		memset(capacity,0,sizeof(capacity));
		for(int i=1;i<=n;i++)//读入机床(边)
		{
			cin>>q[i];
			for(int j=0;j<p;j++)
				cin>>mach[i][j];//必须的输入状态
			for(int j=0;j<p;j++)
				cin>>mach[i+n][j];//输出状态
		}
		for(int i=1;i<=n;i++)
		{
			capacity[i][i+n]=q[i];//初始化,使得i->i+n
		}

	}
    return 0;
}

