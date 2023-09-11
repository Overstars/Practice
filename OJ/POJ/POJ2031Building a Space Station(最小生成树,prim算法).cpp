#include<iostream>
#include<cstdio>
#include<algorithm>//G++就WA,C++就会AC
#include<cstring>//要将n个泡泡表面连接起来
#include<cmath>//算了还是学一下prim吧
//时间复杂度O(n^2),空间复杂度O(n)
//③ 在V-u中寻找最近的节点t 可使用优先队列,时间复杂度logn,执行n次
//④ 根据加入的t节点更新lowcost和closest 可采用邻接表存储,每次只检查邻接边,检查次数为边数E,入队时间复杂度logn,每次更新复杂度O(Elogn)
//
using namespace std;
const int inf=0x3f3f3f3f,MAXN=105;
struct Node
{
	double x,y,z,r;
} node[MAXN];
bool tree[MAXN];//true则已加入tree
int closest[MAXN];//加入第i个节点时的树上最近节点
double dis[MAXN][MAXN],lowcost[MAXN];//边权表,加入第i个节点的最近树上节点的距离
double prim(int n,int u0,double dis[MAXN][MAXN])
{
	memset(tree,0,sizeof(tree));
	tree[u0]=1;//加入树
	int i,j;
	double ans=0;
	for(i=1;i<=n;i++)//① 初始化,
	{
		if(i!=u0)
		{
			lowcost[i]=dis[u0][i];
			closest[i]=u0;//一开始只有u0
		}
		else
			lowcost[u0]=0;
	}
	for(i=1;i<=n;i++)//② 每次选出来一个最近的节点
	{
		double tempdist=inf;
		int t=u0;
		for(j=1;j<=n;j++)//③ 在V-u中寻找最近的节点t
		{
			if(!tree[j]&&lowcost[j]<tempdist)
			{
				t=j;
				tempdist=lowcost[j];
			}
		}
		if(t==u0)
			break;//找不到t,没有可加入的节点,跳出
		tree[t]=1;//找到了就加入tree
		for(j=1;j<=n;j++) //④ 根据加入的t节点更新lowcost和closest
		{
			if(!tree[j]&&dis[t][j]<lowcost[j])
			{
				lowcost[j]=dis[t][j];
				closest[j]=t;
			}
		}
	}
	for(i=1;i<=n;i++)
		ans+=lowcost[i];
	return ans;
}
int main()
{
	int n,i,j;
	while(cin>>n&&n){
		for(i=1;i<=n;i++)
			cin>>node[i].x>>node[i].y>>node[i].z>>node[i].r;
		for(i=1;i<=n;i++)//计算边权表
			for(j=1;j<=n;j++){
				dis[i][j]=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y)+(node[i].z-node[j].z)*(node[i].z-node[j].z))-node[i].r-node[j].r;
				if(dis[i][j]<0)
					dis[i][j]=0;//已经连接,权值为零
				dis[j][i]=dis[i][j];
			}
		printf("%.3lf\n",prim(n,1,dis));
	}
	return 0;
}
