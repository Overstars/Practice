#include<stdio.h>
#define conversion 60
int main(void)
{
	int A,B,C;
	scanf("%d",&A);
	while(A>0){
		C=A/conversion;
		B=A%conversion;
		printf("%d minutes is %d hours %d minutes.\n",A,C,B);
		scanf("%d",&A);
	}
	printf("See you next time.\n");
	return 0;
 } 
