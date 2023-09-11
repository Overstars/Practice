#include<stdio.h>
int main(void)
{
	int N=0,sum=0;
	while(scanf("%d",&N)!=EOF){
		sum=N/2;
		sum=sum*(N+1)+(N+1)/2*(N%2);
		printf("%d\n\n",sum);
	}
	return 0;
}
