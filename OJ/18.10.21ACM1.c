#include<stdio.h>
int main (void)
{
	unsigned int N,A;
	
	scanf("%d",&N);
	
	A=N*(N+1)/2;
	
	printf("%u\n%u",N*N,3*A);
	
	return 0;
}
