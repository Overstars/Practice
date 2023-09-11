#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct pos
{
	int x,y,time,bomb;
};
const int INF=0x3f3f3f3f;
int matrix[10][10],vis[10][10],n,m,sx,sy,flag=0,mini;
int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};
void bfs(int x,int y,int time,int bomb);
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				scanf("%d",&matrix[i][j]);
				if(matrix[i][j]==2){
					sx=i;
					sy=j;
				}
			}
		mini=INF;
		flag=0;
		bfs(sx,sy,0,6);
		if(flag)
			cout<<mini<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
void bfs(int x,int y,int time,int bomb)
{
	queue<pos> QAQ;
//	while (!QAQ.empty())
//		QAQ.pop();
	struct pos start;
	start.x=x,start.y=y,start.time=0,start.bomb=6;
	QAQ.push(start);
	while(!QAQ.empty()){
		struct pos now;
		now=QAQ.front();
		QAQ.pop();
		if(matrix[now.x][now.y]==3){
			if(now.bomb>0){
				flag=1;
				mini=now.time;
			}
			continue;
		}
		if(matrix[now.x][now.y]==4&&bomb>0){
			now.bomb=6;
			matrix[now.x][now.y]=1;
		}
		if(flag)
			break;
		for(int i=0;i<4;i++){
			struct pos temp;
			temp.x=now.x+nx[i];
			temp.y=now.y+ny[i];
			if(matrix[temp.x][temp.y]==0||now.bomb<=1)//是墙
				continue;
			if(temp.x<0||temp.x>=n||temp.y<0||temp.y>=m)
				continue;
			temp.time=now.time+1;
			temp.bomb=now.bomb-1;
			QAQ.push(temp);
		}
	}
	return;
}
//这题很难用DFS写,找到重置装置时很难保证第一次是最短时间
//而不覆盖装置又会导致死循环
