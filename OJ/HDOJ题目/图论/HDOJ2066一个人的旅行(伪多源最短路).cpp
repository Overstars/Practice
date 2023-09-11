#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
void dijkstra(int beg,int n);
int dist[1002],city[1002][1002];
bool flag[1002];
int  main()
{
	int t,s,d,i,j,x,y,mini;
	int sc[1002],dc[1002];
	while(cin>>t>>s>>d){
		memset(city,INF,sizeof(city));
		mini=INF;
		int cnt=0,time;
		for(i=1;i<=t;i++){//输入部分开始
			scanf("%d %d %d",&x,&y,&time);
			if(x>cnt||y>cnt)
				cnt=max(x,y);
			if(time<city[x][y])
				city[x][y]=city[y][x]=time;
		}
		for(i=1;i<=cnt;i++)
			city[i][i]=0;
		for(i=1;i<=s;i++)
			scanf("%d",&sc[i]);
		for(i=1;i<=d;i++)
			scanf("%d",&dc[i]);
		for(i=1;i<=s;i++){//计算部分开始
			memset(dist,INF,sizeof(dist));
			memset(flag,0,sizeof(flag));
			dijkstra(sc[i],cnt);
			for(j=1;j<=d;j++){
				if(dist[dc[j]]<mini)
					mini=dist[dc[j]];
			}
		}
		printf("%d\n",mini);
	}
	return 0;
}
void dijkstra(int beg,int n)
{
	for(int i=1;i<=n;i++){
        dist[i]=city[beg][i];
    }
//    dist[beg]=0;//到自己的距离
    flag[beg]=1;
    for(int i=1;i<=n;i++){
        int temp=INF,t=beg;
        for(int j=1;j<=n;j++){
            if(dist[j]<temp&&!flag[j]){//寻找未确定点到源点最短路的点
                t=j;
                temp=dist[j];
            }
        }
        if(t==beg)
            return;
        else
            flag[t]=1;//起始地到t路径无法再借助其他路径优化，即为最短
        for(int j=1;j<=n;j++){
            if(city[t][j]<INF&&!flag[j]&&(dist[t]+city[t][j])<dist[j]){
                dist[j]=dist[t]+city[t][j];//尝试用t的路径优化其他未确定最短路的点
            }
        }
    }
}
