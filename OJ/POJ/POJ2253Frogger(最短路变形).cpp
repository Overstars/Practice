#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;//从1开始将每个石头都跳一遍,最后落在2号
const int inf=0x3f3f3f3f;
int flag[205];
double dist[205],grid[205][205];//dist存储1到该节点最短路的最小边
void dijkstra(int st,int ed)
{

}
int main()//使最短路的最大边尽量小
{
	int n;
	double ans,x[205],y[205];
	while(cin>>n&&n){
		ans=0;
		memset(dist,inf,sizeof(dist));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				grid[i][j]=grid[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		cout<<dist[2]<<endl;
	}
	return 0;
}
