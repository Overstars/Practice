#include<stdio.h>
int main(void)
{
	long long n;
	unsigned long long sum=0,temp;
	long long i;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%llu",&temp);
		sum+=temp*n*(n-i);
	}
	printf("%llu",sum%1000000007);
	return 0;
}
