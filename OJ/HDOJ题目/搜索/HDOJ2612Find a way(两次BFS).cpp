#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,time;
};
char city[205][205];
int n,m,mini,a[205][205],b[205][205],vis[205][205],nx[4]={0,1,0,-1},ny[4]={1,0,-1,0};
const int inf=0x3f3f3f3f;
void bfs(int sx,int sy,int rec[][205])
{
	queue<node> QAQ;
	node now;
	now.x=sx,now.y=sy,now.time=0;
	memset(vis,0,sizeof(vis));
	QAQ.push(now);
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
		rec[now.x][now.y]=now.time;
		for(int i=0;i<4;i++){
			node nex;
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			nex.time=now.time+11;
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m)
				continue;
			if(vis[nex.x][nex.y]||city[nex.x][nex.y]=='#'||city[nex.x][nex.y]=='Y'||city[nex.x][nex.y]=='M')
				continue;
			vis[nex.x][nex.y]=1;
			QAQ.push(nex);
		}
	}
}
int main()
{
	int ax,ay,bx,by;
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf(" %c",&city[i][j]);
				if(city[i][j]=='Y'){
					ax=i;
					ay=j;
				}
				if(city[i][j]=='M'){
					bx=i;
					by=j;
				}
			}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		mini=inf;
		bfs(ax,ay,a);
		bfs(bx,by,b);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(city[i][j]=='@'&&a[i][j]+b[i][j]>0)
					mini=min(mini,a[i][j]+b[i][j]);//最小总共时间
		cout<<mini<<endl;
	}
	return 0;
}
