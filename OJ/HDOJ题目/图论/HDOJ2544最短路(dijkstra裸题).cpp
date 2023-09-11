#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int city[1005][1005],dist[1005],flag[1005];
void dijkstra(int sta,int fin)
{
	for(int i=1;i<=fin;i++)
	{
		dist[i]=city[sta][i];
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
			if(!flag[j]&&city[t][j]<inf&&dist[j]>dist[t]+city[t][j])
			{
				dist[j]=dist[t]+city[t][j];
			}
	}
}
int main()
{
	int n,m,c,x,y,i,j;
	while(cin>>n>>m&&n&&m){//从1走到n
		memset(city,inf,sizeof(city));
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&c);
			city[x][y]=min(city[x][y],c);
			city[y][x]=city[x][y];
		}
		dijkstra(1,n);
		cout<<dist[n]<<endl;
	}
	return 0;
}
