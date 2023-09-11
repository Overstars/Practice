#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char build[2][15][15];
bool flag[2][15][15];
//typedef struct
//{
//	int step;
//	int x,y,z;
//} jud;
//jud arr[100]={{0,0,0,0}};
int n,m,t,flagp,posx,posy,posz;
void dfs(int x,int y,int z,int time);
int main()
{
	long long c;
	cin>>c;
	while(c--){
		cin>>n>>m>>t;
		int i,j,k;
		flagp=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<2;i++)
			for(j=0;j<n;j++)
				for(k=0;k<m;k++){
					scanf(" %c",&build[i][j][k]);
					if(build[i][j][k]=='P'){
						posz=i;
						posx=j;
						posy=k;
					}
				}
		if(posx+posy<=t)//公主最短路径在t时间可到达
			dfs(0,0,0,0);//row/col/build/time
		if(flagp)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
void dfs(int x,int y,int z,int time)
{
	int i,j,k;
//	arr[time].step=time,arr[time].x=x,arr[time].y=y,arr[time].z=z;
	if(build[z][x][y]=='P'&&time<=t){//找到公主且未超时
		flagp=1;
//		for(k=0;k<=time;k++){
//			printf("step%d:(%d,%d,%d)\n",arr[k].step,arr[k].x,arr[k].y,arr[k].z);
//		}
		return;
	}
	if(x>=n||x<0||y>=m||y<0||flag[z][x][y])//越界/来过
		return;
	if(flagp||time>t||build[z][x][y]=='*')//找到公主/超时/撞墙
		return;
	int remain=abs(x-posx)+abs(y-posy);//剩下的最短步数(假设在同层),大于剩余时间
	if(remain>t-time)//奇偶剪枝不能用,没说恰好在t时刻到达||(t-time-remain)%2==1
		return;
	flag[z][x][y]=1;
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++){
			if(abs(i)+abs(j)==1&&!flag[z][x+i][y+j]&&build[z][x+i][y+j]!='*')//四个方向,未搜过,不是墙
				if(build[z][x+i][y+j]=='#'){//传送到另一层对应位置
					if(build[!z][x+i][y+j]!='#'&&build[!z][x+i][y+j]!='*')//门后是墙/门则忽略
						dfs(x+i,y+j,(!z),time+1);//否则进入传送门
				}
				else
					dfs(x+i,y+j,z,time+1);
		}
	flag[z][x][y]=0;
}
