#include<stdio.h>
int main(void)
{
	int i,n,time=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
		unsigned long long A,B;
		scanf("%llu %llu",&A,&B);
		printf("Case %d:\n",n);
		printf("%llu + %llu = %llu\n",A,B,A+B);
        if(i!=n)
            putchar('\n');
	}
	return 0;
}
