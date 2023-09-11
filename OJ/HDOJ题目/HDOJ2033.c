#include<stdio.h>
int main(void)
{
	int N;//共有N组数据
	const hour=3600;
	const minute=60; 
	scanf("%d",&N);
	while(N-->0){
		int time[5],a,second;
		int n_hour,n_minute,n_second;
		for(a=0;a<=5;a++)
		scanf("%d",&time[a]);
		second=(time[0]+time[3])*hour+(time[1]+time[4])*minute+time[2]+time[5];
		n_second=second%minute;
		n_minute=second/minute;
		n_minute=n_minute%minute;
		n_hour=second/hour;
		printf("%d %d %d\n",n_hour,n_minute,n_second);
	}
	return 0;
}
