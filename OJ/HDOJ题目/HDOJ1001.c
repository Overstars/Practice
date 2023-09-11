#include<stdio.h>
int main(void)
{
	int x=0;
	long long sum=0;
	while(scanf("%d",&x)!=EOF){
		sum=0;
		while(x>0){
		sum+=x;
		x--;
		}
	printf("%d\n\n",sum);
	}
	
	return 0;
}
