#include<stdio.h>
int main(void)
{
	int BJT,hour,min,UTC;
	scanf("%d",&BJT);
	min=BJT%100;
	hour=BJT/100;
	hour=hour-8;
	if(hour<0)
	{
		hour=hour+24;
	}
	UTC=hour*10+min/10;
	printf("%d%d",UTC,min%10);
	
	return 0;
 } 
