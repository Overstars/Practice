#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	while(n-->0){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a%b==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
