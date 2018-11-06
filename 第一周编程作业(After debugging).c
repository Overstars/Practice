#include<stdio.h>
int main(void)
{
	int A,B,C,D,E,F;
	printf("Please input your numbers...\n");
	scanf("%d",&A);
	
	printf("\n\n\nWaiting...\n\n\n\n");
	
	B=A%10;
	C=A/100;
	D=A/10;
	E=D%10;
	F=B*100+E*10+C;
	
	printf("%d\n\n",F);
	
	system("pause");
	
	return 0;
	
	
}
