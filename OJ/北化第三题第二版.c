#include<stdio.h>
int main(void)
{
	int M,N,T,A,sum=0;
	scanf("%d %d",&N,&M);
	while(M>0&&N>0)
	{
		scanf("%d %d",&T,&A);
		if(N>=T)
		{
			sum=sum+A;
			N=N-T;
		}
		M=M-1;
	}
	
	printf("%d",sum);
	
	return 0;
} 
