#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0X3F3F3F3F;
typedef struct node
{
	int x,y,time;
	bool operator<(const node &f) const {//优先队列,
        return f.time<time;
   }
} node;
char matrix[105][105];
int n,m,flag,dir[105][105],fight[105][105],vis[105][105],mini,t;
int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};
void output(int x,int y)//尾递归输出
{
	if(x==0&&y==0){
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",mini);
		return;
	}
	int prex=x-nx[dir[x][y]],prey=y-ny[dir[x][y]];
	output(prex,prey);
	printf("%ds:(%d,%d)->(%d,%d)\n",t++,prex,prey,x,y);
	while(fight[x][y]-->0){
		printf("%ds:FIGHT AT (%d,%d)\n",t++,x,y);
	}
}
void bfs(int x,int y,int cnt)
{
	priority_queue<node> QAQ;
	node start;
	start.x=start.y=start.time=0;
	QAQ.push(start);
	while(!QAQ.empty()){
		node now;
		now=QAQ.top();
		QAQ.pop();
		if(now.x==n-1&&now.y==m-1&&(matrix[now.x][now.y]=='0'||matrix[now.x][now.y]=='.')){
			flag=1;
			mini=now.time;
			t=1;
			output(now.x,now.y);
			return;
		}
		if(flag)
			break;
		for(int i=0;i<4;i++){
			node temp;
			temp.x=now.x+nx[i];
			temp.y=now.y+ny[i];
			temp.time=now.time+1;
			if(matrix[temp.x][temp.y]=='X'||vis[temp.x][temp.y])//是墙
				continue;
			if(temp.x<0||temp.x>=n||temp.y<0||temp.y>=m)
				continue;
			if(matrix[temp.x][temp.y]>'0'&&matrix[temp.x][temp.y]<='9'){
				temp.time+=matrix[temp.x][temp.y]-'0';
				fight[temp.x][temp.y]=matrix[temp.x][temp.y]-'0';
				matrix[temp.x][temp.y]='.';
			}
			dir[temp.x][temp.y]=i;//记录来到当前节点的方式
			vis[temp.x][temp.y]=1;
			QAQ.push(temp);
		}
	}
	return;
}
int main()
{
	while(cin>>n>>m){
		flag=0;
		mini=INF;
		memset(fight,0,sizeof(fight));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf(" %c",&matrix[i][j]);
		bfs(0,0,0);
		if(!flag)
			puts("God please help our poor hero.");
		puts("FINISH");
	}
	return 0;
}
