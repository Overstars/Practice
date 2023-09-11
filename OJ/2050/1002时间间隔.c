#include<stdio.h>
int main(void)
{
	int n,minute,second;
	int a,b,c,d;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d-%d-%d %d:%d:%d",&a,&b,&c,&d,&minute,&second);
		if(minute==0&&second==0)
			printf("0\n");
		else if(second!=0)
			printf("%d\n",((60-minute-1)*60+(60-second))%100);
		else
			printf("%d\n",((60-minute)*60)%100);
	}
	return 0;
}
