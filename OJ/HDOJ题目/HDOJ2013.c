#include<stdio.h>
int main(void)
{
	int n;//剩一个桃子天数为n
	while(scanf("%d",&n)!=EOF){
		long a=1;//a为从后往前推当天的桃子数
		for(a;n-->1;a=(a+1)*2);	
		printf("%d\n",a);
	} 
	return 0;
 } 
