#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct tower
{
	char ch;//射击方向,子弹和小A不能穿过城堡
	int t,v;
} tow[101][101];//子弹和A的移动都是离散的，只有同时出现在同一点，A才会被杀死
int m,n,k,d,ans;//城堡数量k,d秒内到达
bool vis[1001][101][101];//用int会MLE成狗
int nx[5]={1,0,-1,0,0},ny[5]={0,1,0,-1,0};
struct node
{
	int x,y,time;
};
int bfs(int x,int y,int time)
{
	node now;
	now.x=x,now.y=y,now.time=time;
	queue<node>QAQ;
	QAQ.push(now);
	vis[time][x][y]=1;
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
//		printf("time:%d,x=%d,y=%d\n",now.time,now.x,now.y);
		if(now.time>d)
			break;
		if(now.x==m&&now.y==n){
			ans=now.time;
			return 1;
		}
		for(int i=0;i<5;i++){
			node nex;
			nex.x=now.x+nx[i];
			nex.y=now.y+ny[i];
			nex.time=now.time+1;
			if(nex.x<0||nex.x>m||nex.y<0||nex.y>n||vis[nex.time][nex.x][nex.y]||tow[nex.x][nex.y].t||nex.time>d)
				continue;
			int flag=1;//是否会被击中
			if(!tow[nex.x][nex.y].t){//所在之处没有塔
					for(int j=nex.x-1;j>=0;j--)
						if(tow[j][nex.y].t)//找到第一个炮台
							if(tow[j][nex.y].ch!='S')//不向下开炮
								break;
							else{//向下开炮
								int dist=nex.x-j;//距离
								if(dist%tow[j][nex.y].v)
									break;//子弹不会出现在该点
								int time2=dist/tow[j][nex.y].v;//第一发子弹飞到这里的时间
								if(nex.time<time2)//第一发子弹还没飞到
									break;//安全
								if((nex.time-time2)%tow[j][nex.y].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;//跳出该方向循环,尝试下个方向
					for(int j=nex.x+1;j<=m;j++)
						if(tow[j][nex.y].t)//找到第一个炮台
							if(tow[j][nex.y].ch!='N')//不向上开炮
								break;
							else{
								int dist=j-nex.x;//距离
								if(dist%tow[j][nex.y].v)
									break;//子弹不会出现在该点
								int time2=dist/tow[j][nex.y].v;//第一发子弹飞到这里的时间
								if(nex.time<time2)
									break;//安全
								if((nex.time-time2)%tow[j][nex.y].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;
					for(int j=nex.y-1;j>=0;j--)
						if(tow[nex.x][j].t)//找到第一个炮台
							if(tow[nex.x][j].ch!='E')//不向右开炮
								break;
							else{//向右开炮
								int dist=nex.y-j;//距离
								if(dist%tow[nex.x][j].v)
									break;//子弹不会出现在该点
								int time2=dist/tow[nex.x][j].v;//第一发子弹飞到这里的时间
								if(nex.time<time2)
									break;//安全
								if((nex.time-time2)%tow[nex.x][j].t==0){
									flag=0;
									break;
								}
							}

					if(flag==0)
						continue;
					for(int j=nex.y+1;j<=n;j++)
						if(tow[nex.x][j].t)//找到第一个炮台
							if(tow[nex.x][j].ch!='W')//不向左开炮
								break;
							else{//向左开炮
								int dist=j-nex.y;//距离
								if(dist%tow[nex.x][j].v)
									break;//子弹不会出现在该点
								int time2=dist/tow[nex.x][j].v;//第一发子弹飞到这里的时间
								if(nex.time<time2)
									break;//安全
								if((nex.time-time2)%tow[nex.x][j].t==0){
									flag=0;
									break;
								}
							}

					vis[nex.time][nex.x][nex.y]=1;
					if(flag==0)
						continue;
					QAQ.push(nex);
			}
		}
	}
	return 0;
}
int main()//从0,0到m,n
{
	while(cin>>m>>n>>k>>d){
		char ch;
		int t,v,x,y;//周期,射速,城堡位置
		memset(vis,0,sizeof(vis));
		memset(tow,0,sizeof(tow));
		for(int i=0;i<k;i++){
			scanf(" %c%d%d%d%d",&ch,&t,&v,&x,&y);//注意x,y
			tow[x][y].ch=ch,tow[x][y].t=t,tow[x][y].v=v;//在地图上标记塔的位置
		}
		if(bfs(0,0,0))
			cout<<ans<<endl;
		else
			cout<<"Bad luck!"<<endl;
	}
	return 0;
}
