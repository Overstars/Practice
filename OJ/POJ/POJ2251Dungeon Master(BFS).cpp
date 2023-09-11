#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char dun[30][30][30];
struct node
{
	int x,y,z,step;
};
int l,r,c,ans,flag,vis[30][30][30];
int nx[6]={0,-1,0,1,0,0},ny[6]={1,0,-1,0,0,0},nz[6]={0,0,0,0,1,-1};
void bfs(int step,int x,int y,int z)
{
	node now,nex;
	now.x=x,now.y=y,now.z=z,now.step=0;
	queue<node> orz;
	orz.push(now);
	while(!orz.empty()){
		now=orz.front();
		orz.pop();
		if(dun[now.x][now.y][now.z]=='E'){
			flag=1;
			ans=now.step;
			return;
		}
		int i;
		for(i=0;i<6;i++){
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			nex.z=now.z+nz[i];
			if(dun[nex.x][nex.y][nex.z]=='#'||vis[nex.x][nex.y][nex.z])
				continue;
			if(nex.x<0||nex.x>=l||nex.y<0||nex.y>=r||nex.z<0||nex.z>=c)
				continue;
			vis[nex.x][nex.y][nex.z]=1;
			nex.step=now.step+1;
			orz.push(nex);
		}
	}
}
int main()
{
	int i,j,k,sx,sy,sz;
	while(cin>>l>>r>>c&&(l||r||c)){
		flag=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<l;i++)
			for(j=0;j<r;j++)
				for(k=0;k<c;k++){
					scanf(" %c",&dun[i][j][k]);
					if(dun[i][j][k]=='S'){
						sx=i;
						sy=j;
						sz=k;
					}
				}
		bfs(0,sx,sy,sz);
		if(flag)
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
	}
	return 0;
}
