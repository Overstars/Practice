#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;//��1��ʼ��ÿ��ʯͷ����һ��,�������2��
const int inf=0x3f3f3f3f;
int flag[205];
double dist[205],grid[205][205];//dist�洢1���ýڵ����·����С��
void dijkstra(int st,int ed)
{

}
int main()//ʹ���·�����߾���С
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
