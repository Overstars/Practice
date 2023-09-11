#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int grid[1005][1005],dist[1005],flag[1005];
const int inf=0x3f3f3f3f;
void dijkstra(int sta,int fin)
{
	for(int i=1;i<=fin;i++)
	{
		dist[i]=grid[sta][i];
		flag[i]=0;
	}
	dist[sta]=0;
	flag[sta]=1;
	for(int i=1;i<=fin;i++)
	{
		int temp=inf,t=sta;
		for(int j=1;j<=fin;j++)
		{
			if(!flag[j]&&dist[j]<temp)
			{
				t=j;
				temp=dist[j];
			}
		}
		if(t==sta)
			return;
		flag[t]=1;//到t的最短路已确认
		for(int j=1;j<=fin;j++)
			if(!flag[j]&&grid[t][j]<inf&&dist[j]>dist[t]+grid[t][j])
			{
				dist[j]=dist[t]+grid[t][j];
			}
	}
}
int main()
{
	int n,t,x,y,dis;
	while(cin>>t>>n){
		memset(grid,inf,sizeof(grid));
		for(int i=1;i<=t;i++){
			scanf("%d%d%d",&x,&y,&dis);
			grid[x][y]=min(grid[x][y],dis);
			grid[y][x]=grid[x][y];
		}
		dijkstra(1,n);
		cout<<dist[n]<<endl;
	}
	return 0;
}
