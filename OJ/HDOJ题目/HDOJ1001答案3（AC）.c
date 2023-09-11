#include<stdio.h>
int main(void)
{
	long long N,sum;
	while(scanf("%lld",&N)!=EOF){
		sum=N*(N+1)/2;
		printf("%lld\n\n",sum);
	}
	return 0;
 } 
