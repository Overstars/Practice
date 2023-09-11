#include<stdio.h>
#include<string.h>
int head[1005];
int find(int x);
void join(int x,int y);
int main(void)
{
	int i,j;
	int t,n,m;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d %d",&n,&m);
		memset(head,0,sizeof(int));
		for(i=1;i<=n;i++)
			head[i]=i;
		int x1,x2,count=0;
		while(m-->0){
			scanf("%d %d",&x1,&x2);
			if(find(x1)!=find(x2))
				join(x1,x2);
		}
		for(i=1;i<=n;i++){
			if(i==head[i])
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
int find(int x)
{
	int i=x,temp;
	while(x!=head[x])
		x=head[x];
	while(i!=x){
		temp=i;
		i=head[i];
		head[temp]=x;
	}
	return x;
}
void join(int x,int y)
{
	int boss1=find(x);
	int boss2=find(y);
	if(boss1!=boss2){
		head[boss2]=boss1;
	}
	return;
}
