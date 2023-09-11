#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int sx,sy,tx,ty,n,vis[305][305];
int nx[8]={-2,-2,-1,-1,1,1,2,2},ny[8]={-1,1,-2,2,-2,2,-1,1};
struct node
{
	int x,y,step;
};
int bfs(void)
{
	queue<node> q;
	node now;
	now.x=sx,now.y=sy,now.step=0;
	vis[sx][sy]=1;
	q.push(now);
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.x==tx&&now.y==ty)
			return now.step;
		for(int i=0;i<8;i++){
			node nex;
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=n||vis[nex.x][nex.y])
				continue;
			vis[nex.x][nex.y]=1;
			nex.step=now.step+1;
			q.push(nex);
		}
	}
	return 0;//少了这句就WA了
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
