#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		sum();
	}
	return 0;
}


void sum(void)
{
	int sum=0; 
	while(n>0){
	sum+=n;
	n--;
	}
	printf("%d\n\n",sum);
}
