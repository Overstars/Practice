/*A+B for Input-Output Practice (V)
*16秒读题，1分48秒敲代码，16秒提交并AC*/
#include<stdio.h>
int main(void)
{
	int m,n;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d",&m);
		int temp,sum=0;
		while(m-->0){
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum);
	}
	return 0;
}
