/*A+B for Input-Output Practice (VI)
*36秒读题，1分46秒敲代码，53秒修改了一个CE后AC*/
#include<stdio.h>
int main(void)
{
	int N,sum,temp;
	while(scanf("%d",&N)!=EOF){
		sum=0;
		while(N-->0){
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum);
	}
	return 0;
}
