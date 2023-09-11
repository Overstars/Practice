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
		for(i=1;i<=t;i++){//���벿�ֿ�ʼ
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
		for(i=1;i<=s;i++){//���㲿�ֿ�ʼ
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
//    dist[beg]=0;//���Լ��ľ���
    flag[beg]=1;
    for(int i=1;i<=n;i++){
        int temp=INF,t=beg;
        for(int j=1;j<=n;j++){
            if(dist[j]<temp&&!flag[j]){//Ѱ��δȷ���㵽Դ�����·�ĵ�
                t=j;
                temp=dist[j];
            }
        }
        if(t==beg)
            return;
        else
            flag[t]=1;//��ʼ�ص�t·���޷��ٽ�������·���Ż�����Ϊ���
        for(int j=1;j<=n;j++){
            if(city[t][j]<INF&&!flag[j]&&(dist[t]+city[t][j])<dist[j]){
                dist[j]=dist[t]+city[t][j];//������t��·���Ż�����δȷ�����·�ĵ�
            }
        }
    }
}
