/*A+B for Input-Output Practice (VI)
*36����⣬1��46���ô��룬53���޸���һ��CE��AC*/
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
