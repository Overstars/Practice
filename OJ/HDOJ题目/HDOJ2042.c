#include<stdio.h>
int main(void)
{
	int N,m;
	scanf("%d",&N);
	while(N-->0){
		scanf("%d",&m);
		int sum=3;
		for(m;m>0;m--)
		sum=(sum-1)*2;
		printf("%d\n",sum);
	}
	return 0;
}
