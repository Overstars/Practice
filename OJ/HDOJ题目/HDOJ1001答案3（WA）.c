#include<stdio.h>
int main(void)
{
	int N=0;
	long long sum=0;
	while(scanf("%d",&N)!=EOF){
		sum=N*(N+1)/2;
		printf("%lld\n\n",sum);
	}
	return 0;
}
