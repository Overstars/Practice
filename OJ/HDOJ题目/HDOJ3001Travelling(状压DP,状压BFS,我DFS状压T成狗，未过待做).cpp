#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;//�������·,TSP����
int n,m,mini,route[15][15];//n������,m��·,ÿ��·�Ŀ���
bool vis2[15];
void dfs(int city,int vis,int cost,int step)
{
//	printf("city=%d,vis=%d,cost=%d,mini=%d\n",city,vis,cost,mini);
	if(cost>=inf||step>=2*n||cost>=mini)
		return;
//	if(step==1)
//		vis=1<<(city-1);
	if(vis&(1<<(city-1)))//����һ��
		vis2[city]=1;//���Ϊ�ڶ�����
	else
		vis+=1<<(city-1);//��һ�α����
	if(vis==((1<<n)-1))
	{
		mini=min(mini,cost);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis2[i]||route[city][i]>=inf||i==city)//i��ȥ���ڶ���||ȥ����
			continue;
		dfs(i,vis,cost+route[city][i],step+1);
	}
	if(vis2[city])
		vis2[city]=0;
	return;
}
int main()
{
	int i,j,x,y;
	while(cin>>n>>m){
		mini=inf;
		memset(route,inf,sizeof(route));
//		memset(vis2,0,sizeof(vis2));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			scanf("%d",&route[x][y]);
			route[y][x]=route[x][y];
		}
		for(i=1;i<=n;i++)
		{
			dfs(i,0,0,1);
		}
		if(mini>=inf)
			cout<<-1<<endl;
		else
			cout<<mini<<endl;
	}
	return 0;
}
