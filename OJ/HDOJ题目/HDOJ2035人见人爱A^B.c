#include<stdio.h>
#define mod 1000 
int main(void)
{
	int a,b;
	long long result;
	while(scanf("%d %d",&a,&b)==2&&(a!=0&&b!=0)){
		int i;
		result=1;
		for(i=1;i<=b;i++){
			result=((result%mod)*(a%mod))%mod;
		}
		printf("%lld\n",result);
	}
	return 0;
}

