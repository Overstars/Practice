/*A+B for Input-Output Practice (IV)
*14秒读题，2分11秒敲代码，18秒提交并AC*/
#include<stdio.h>
int main(void)
{
	int N,temp,sum;
	while((scanf("%d",&N)!=EOF)&&N!=0){
		sum=0;
		while(N-->0){
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum);
	}
	return 0;
}
