#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
} com[1005];
int head[1005],n,d;//n台,通信距离d;
bool flag[1005];
int findpar(int a)//找a的boss
{
	int r=head[a];//与a联通的城市
	while(head[r]!=r){
		r=head[r];
	}
	int temp;
	while(a!=r){
		temp=head[a];//a的上级
		head[a]=r;
		a=temp;
	}
	return r;
}
int join(int a,int b)
{
	int flag=0,dis=(com[a].x-com[b].x)*(com[a].x-com[b].x)+(com[a].y-com[b].y)*(com[a].y-com[b].y);
	int M=findpar(a),N=findpar(b);
	if(M!=N&&dis<=d*d){
		flag=1;
		head[M]=N;
	}
	return flag;
}
int main()
{
	while(cin>>n>>d){
		int i,j,x,y;
		char ch;
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			com[i].x=x,com[i].y=y;
			head[i]=i;
		}
		while(scanf(" %c",&ch)==1){
			if(ch=='O'){
				int no;
				scanf("%d",&no);
				flag[no]=1;
				for(i=1;i<=n;i++)
					if(flag[i])//已经激活的电脑
						join(i,no);
			}
			else{
				scanf("%d%d",&x,&y);
				if(findpar(x)==findpar(y))
					printf("SUCCESS\n");
				else
					puts("FAIL");
			}
		}
	}
	return 0;
}
