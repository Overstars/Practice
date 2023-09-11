#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		printf("%d\n",cows(n));
	}
	return 0;
}
int cows(int n)
{
	if(0<n&&n<5)
		return n;
	else
		return cows(n-1)+cows(n-3);
}
