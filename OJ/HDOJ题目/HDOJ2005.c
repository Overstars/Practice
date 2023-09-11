#include<stdio.h>
int main(void)
{
	int year,month,day;
	while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
		int February=28;
		if((year%4==0&&year%100!=0)||year%400==0)
			February=29;
		if(month<3)
			switch(month){
				case 1:
					printf("%d\n",day);
					break;
				case 2:
					printf("%d\n",31+day);
					break;
			}
		if(month>=3){
			switch(month){
				case 3:
					printf("%d\n",31+February+day);
					break;
				case 4:
					printf("%d\n",31+February+31+day);
					break;
				case 5:
					printf("%d\n",31*2+February+30+day);
					break;
				case 6:
					printf("%d\n",31*3+February+30+day);
					break;
				case 7:
					printf("%d\n",31*3+February+30*2+day);
					break;
				case 8:
					printf("%d\n",31*4+February+30*2+day);
					break;
				case 9:
					printf("%d\n",31*5+February+30*2+day);
					break;
				case 10:
					printf("%d\n",31*5+February+30*3+day);
					break;
				case 11:
					printf("%d\n",31*6+February+30*3+day);
					break;
				case 12:
					printf("%d\n",31*6+February+30*4+day);
					break;
			}
		}
		
	}
	return 0;
}
