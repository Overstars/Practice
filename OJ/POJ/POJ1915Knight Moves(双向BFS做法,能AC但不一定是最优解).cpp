#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int sx,sy,tx,ty,n,vis[2][305][305];
int nx[8]={-2,-2,-1,-1,1,1,2,2},ny[8]={-1,1,-2,2,-2,2,-1,1};
struct node
{
	int x,y,step;
};
int bfs(void)
{
	queue<node> q1,q2;
	node now,now2;
	now.x=sx,now.y=sy,now.step=0;
	now2.x=tx,now2.y=ty,now2.step=0;
	memset(vis,inf,sizeof(vis));
	vis[0][sx][sy]=0;//记录步数
	vis[1][tx][ty]=0;
	q1.push(now);
	q2.push(now2);
	while(!q1.empty()||!q2.empty()){//虽然能AC但我觉得还是不对,节点扩张并不能保证是最优解
		int flag;//起点BFS标记为0，终点BFS标记为1
		if(q1.size()<=q2.size()){
			flag=0;//扩张起点
			now=q1.front();
			q1.pop();
		}
		else{
			flag=1;
			now=q2.front();
			q2.pop();
		}
		if(vis[1-flag][now.x][now.y]<inf)
			return now.step+vis[1-flag][now.x][now.y];
		for(int i=0;i<8;i++){//逐层扩展
			node nex;
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			nex.step=now.step+1;
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=n||nex.step>=vis[flag][nex.x][nex.y])
				continue;
			vis[flag][nex.x][nex.y]=nex.step;
			if(flag==0)
				q1.push(nex);
			else
				q2.push(nex);
		}
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>sx>>sy>>tx>>ty;
		memset(vis,0,sizeof(vis));
		cout<<bfs()<<endl;
	}
	return 0;
}
