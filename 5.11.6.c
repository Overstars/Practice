#include<stdio.h>
int main(void)
{
	int A,B=0;
	long long int C;
	printf("This program is used to calculate how many dollors you can make.\n");
	scanf("%d",&A);
	while(++B<A)
	{
		C=C+B*B;
	}
	printf("So you can earn %d dollors in %d days.\n",C,A);
	return 0;
}
