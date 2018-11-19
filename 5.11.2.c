#include<stdio.h>
int main(void)
{
	int A,B;
	printf("Please enter an integer.\n");
	scanf("%d",&A);
	B=A+9;
	printf("%d",A);
	while(A++<=B)
	{
		printf("	%d",A);
	}
	return 0;
 } 
