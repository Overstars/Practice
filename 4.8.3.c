#include<stdio.h>
int main(void)
{
	float A,B;
	printf("Please a number.\n");
	scanf("%f",&A);
	printf("Please enter another one.\n");
	scanf("%f",&B);
	printf("a.The input is%f or %e.\n""b.The input is %+.3f or %E",A,A,B,B);
	
	return 0;
}
