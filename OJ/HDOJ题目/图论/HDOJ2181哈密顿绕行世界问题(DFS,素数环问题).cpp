#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int city[3];
};
node MAP[21];
int vis[21],path[21],cnt,n;
void dfs(int x,int step)
{
	if(step==20&&x==n)
	{
		printf("%d:  ",++cnt);
		for(int i=0;i<20;i++)
			printf("%d ",path[i]);
		printf("%d\n",n);
		return;
	}
	if(step>20)
		return;
	if(step>0&&step<20&&x==n)
		return;
	for(int i=0;i<3;i++){
		if(!vis[MAP[x].city[i]]){
			vis[MAP[x].city[i]]=1;
			path[step+1]=MAP[x].city[i];
			dfs(MAP[x].city[i],step+1);
			vis[MAP[x].city[i]]=0;
		}
	}
}
int main()
{
	int i,j;
	for(i=1;i<=20;i++){
		for(j=0;j<3;j++){
			scanf("%d",&MAP[i].city[j]);
		}
		sort(MAP[i].city,MAP[i].city+3);
//		printf("%d %d %d\n",MAP[i].city[0],MAP[i].city[1],MAP[i].city[2]);
	}
	while(cin>>n&&n){
		cnt=0;
		path[0]=n;
		dfs(n,0);
	}
	return 0;
}
