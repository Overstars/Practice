#include<stdio.h>
int fun(long long num);
int main(void)
{
	int x,y,n;
	while((scanf("%d %d",&x,&y))!=EOF&&(x||y)){
		int flag=1;
		long long t;
		for(n=x;n<=y;n++){
			t=n*n+n+41;
			if(fun(t)==0){
				flag=0;
				break;
			}
		}
		if(flag)
			printf("OK\n");
		else
			printf("Sorry\n");
	}
	return 0;
}
int fun(long long num)
{
	long long ret=1,i;
	for(i=2;i<num;i++){
		if(num%i==0){
			ret=0;
			break;
		}
	}
	return ret;
}
