/*A+B for Input-Output Practice (VIII)
*9秒读题，2分23秒敲代码，4分36秒修改了一个CE和PE后AC*/ 
#include<stdio.h>
int main(void)
{
	int n,m,temp,sum;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d",&m);
		sum=0;
		while(m-->0){
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum);
		if(n!=0)
			putchar('\n');
	}
	return 0;
}
