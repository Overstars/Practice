#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int matrix[10][10],m,n,vis[10][10][10][10];
int nx[4]={0,-1,0,1},ny[4]={1,0,-1,0};
struct node
{
	int px,py,bx,by,cnt;
};
int bfsjud(int cur_x,int cur_y,int nex_x,int nex_y,int cur_bx,int cur_by)//判断是否能绕到目的地
{
	int flag[10][10]={0};
//	memset(flag,0,sizeof(flag));
	queue<node> TAT;
	node now,nex;
	now.px=cur_x,now.py=cur_y;
	flag[cur_x][cur_y]=1;
	TAT.push(now);
	while(!TAT.empty()){
		now=TAT.front();
		TAT.pop();
		if(now.px==nex_x&&now.py==nex_y){
			return 1;
		}
		for(int i=0;i<4;i++){
			nex.px=now.px+nx[i];
			nex.py=now.py+ny[i];
			if(nex.px==cur_bx&&nex.py==cur_by)
				continue;
			if(flag[nex.px][nex.py]||matrix[nex.px][nex.py]==1)
				continue;
			if(nex.px<0||nex.px>=m||nex.py<0||nex.py>=n)
				continue;
			flag[nex.px][nex.py]=1;
			TAT.push(nex);
		}
	}
	return 0;
}
int bfs(int sx,int sy,int bx,int by)
{
	queue<node> QAQ;
	node now,nex;
	now.px=sx,now.py=sy,now.bx=bx,now.by=by,now.cnt=0;
	vis[sx][sy][bx][by]=1;
	QAQ.push(now);
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
		if(matrix[now.bx][now.by]==3)
			return now.cnt;
		for(int i=0;i<4;i++){
			nex.bx=now.bx+nx[i];
			nex.by=now.by+ny[i];
			nex.px=now.bx-nx[i];//箱子向i方向推到nex,所以人要绕到后面
			nex.py=now.by-ny[i];
			if(nex.bx<0||nex.bx>=m||nex.by<0||nex.by>=n||nex.px<0||nex.px>=m||nex.py<0||nex.py>=n)
				continue;//任何一个越界
			if(vis[nex.px][nex.py][nex.bx][nex.by]||matrix[nex.px][nex.py]==1||matrix[nex.bx][nex.by]==1)
				continue;
			if(bfsjud(now.px,now.py,nex.px,nex.py,now.bx,now.by)){
				vis[nex.px][nex.py][nex.bx][nex.by]=1;
				nex.cnt=now.cnt+1;
				QAQ.push(nex);
			}
		}
	}
	return -1;
}
int main()//求出推动箱子多少格,用一个BFS搜索箱子的前进路线,另一个BFS搜索当前移动箱子这一步是否可行
{
	int t,sx,sy,bx,by;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>m>>n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
				if(matrix[i][j]==4){
					sx=i;
					sy=j;
				}
				if(matrix[i][j]==2){
					bx=i;
					by=j;
				}
			}
		cout<<bfs(sx,sy,bx,by)<<endl;
	}
	return 0;
}
