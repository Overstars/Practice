#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int vis[105][105],a,b,c;//A,B容量
struct node
{
	int x,y,step;
};
struct path
{
	int prex,prey;
};
path pat[105][105];//记录来到x,y之前的
void fun(int n,node *p,node s)
{
	if(n==1)
		p->x=a;
	else if(n==2)
		p->y=b;
	else if(n==3)
		p->x=0;
	else if(n==4)
		p->y=0;
	else if(n==5){//a倒入b
		if(p->x>b-p->y){//倒入b中会溢出
			p->x-=(b-p->y);
			p->y=b;
		}
		else{
			p->y+=p->x;
			p->x=0;
		}
	}
	else{//b倒入a
		if(p->y>a-p->x){//倒入a中会溢出
			p->y-=(a-p->x);
			p->x=a;
		}
		else{
			p->x+=p->y;
			p->y=0;
		}
	}
	if(!vis[p->x][p->y]){
		pat[p->x][p->y].prex=s.x;
		pat[p->x][p->y].prey=s.y;
	}
}
void show(int x,int y)
{
	if(vis[x][y]==-1){
		return;
	}
	show(pat[x][y].prex,pat[x][y].prey);
	switch(vis[x][y])
	{
		case 1:
			printf("FILL(1)\n");
			break;
		case 2:
			printf("FILL(2)\n");
			break;
		case 3:
			printf("DROP(1)\n");
			break;
		case 4:
			printf("DROP(2)\n");
			break;
		case 5:
			printf("POUR(1,2)\n");
			break;
		case 6:
			printf("POUR(2,1)\n");
			break;
		default:
			break;
	}
}
int bfs(int x,int y,int tar)
{
	node now,nex;
	now.x=x,now.y=y,now.step=0;
	vis[x][y]=-1;
	queue<node>QAQ;
	QAQ.push(now);
	while(!QAQ.empty()){
		now=QAQ.front();
		QAQ.pop();
		if(now.x==tar||now.y==tar){
			printf("%d\n",now.step);
			show(now.x,now.y);
			return 1;
		}
//		printf("%d:%d,%d\n",now.step,now.x,now.y);
		for(int i=1;i<=6;i++){
			nex=now;
			fun(i,&nex,now);
			if(vis[nex.x][nex.y])
				continue;
			vis[nex.x][nex.y]=i;//记录操作
			nex.step=now.step+1;
			QAQ.push(nex);
		}
	}
	printf("impossible\n");
	return 0;
}
int main()
{
	while(cin>>a>>b>>c){
		memset(vis,0,sizeof(vis));
		bfs(0,0,c);
	}
	return 0;
}
