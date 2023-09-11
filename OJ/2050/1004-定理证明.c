#include<stdio.h>
int main(void)
{
	unsigned long long t,n,out=1;
	scanf("%llu",&t);
	while(t-->0){
		scanf("%llu",&n);
		int i;
		out=1;
		for(i=0;i<n;i++){
			out*=2;
		}
		if(n==1)
			printf("0\n");
		else
			printf("%llu\n",out-n+2);
	}
	return 0;
}
