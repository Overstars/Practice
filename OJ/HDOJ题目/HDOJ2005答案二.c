#include<stdio.h>
int main(void)
{
	int array[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day;
	
	while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
		if((year%4==0&&year%100!=0)||year%400==0){
			array[1]=29;
		}
		else
			array[1]=28;
			
		int i,sum=0;
		for(i=0;i<month-1;i++){
			sum+=array[i];
		}
		sum+=day;
		printf("%d\n",sum);
	}
	return 0;
}
