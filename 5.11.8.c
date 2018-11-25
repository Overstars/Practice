#include<stdio.h>
int main(void)
{
	int A,B;
	printf("This progrem computes moduli.\nEnter an integer to serve as the second operanf:\n");
	scanf("%d",&A);
	printf("Now enter the first operand:\n");
	scanf("%d",&B);
	while(A>0&&B>0)
	{
		printf("%d %% %d is %d\n",B,A,B%A);
		printf("Enter next number for first operand(<= 0 to quit):\n");
		scanf("%d",&B);
	}
	return 0;
}
