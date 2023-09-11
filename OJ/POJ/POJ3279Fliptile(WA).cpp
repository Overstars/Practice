#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,a[20][20],mp[20][20],vis[20][20],flag,ans;
int nx[5]={0,0,1,0,-1},ny[5]={0,1,0,-1,0};
int jud(void)
{
	int i,j,TAT=1;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if(a[i][j]-mp[i][j]!=0){
				TAT=0;
				goto tar;
			}
		}
	tar:
	return TAT;
}
void change(int x,int y)
{
	int i,j;
	for(i=0;i<5;i++){
		int nnx=x+nx[i];
		int nny=y+ny[i];
		if(nnx<0||nnx>=m||nny<0||nny>=n)
			continue;
		mp[nnx][nny]=1-mp[nnx][nny];
	}
}
void dfs(int x,int y,int step)
{
	int i,j;
	if(jud()==1){
		flag=1;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%d",vis[i][j]);
				if(j<n-1)
					putchar(' ');
				else
					putchar('\n');
			}
		}
		return;
	}
//	{
//		printf("step:%d\n",step);
//		for(i=0;i<m;i++){
//			for(j=0;j<n;j++){
//				printf("%d",vis[i][j]);
//				if(j<n-1)
//					putchar(' ');
//				else
//					putchar('\n');
//			}
//		}
//		printf("\n*********\n");
//	}
	if(flag||x<-1||x>=m||y<0||y>=n)
		return;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if(!vis[i][j]){
				vis[i][j]=1;
				change(i,j);
				dfs(i,j,step+1);
				change(i,j);
				vis[i][j]=0;
			}
		}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
//			mp[i][j]=a[i][j];
		}
	dfs(-1,0,0);
	if(!flag)
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
