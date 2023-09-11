#include<stdio.h>
int main(void)
{
	int M,N,T;
	float A,sum;
	scanf("%d %d",&N,&M);
	while(M>0)
	{
		scanf("%d %f",&T,&A);
		if(N>=T)
		{
			sum=sum+A;
			N=N-T;
		}
		M=M-1;
	}
	printf("%f",sum);
	
	return 0;
}
