/*A+B for Input-Output Practice (IV)
*14����⣬2��11���ô��룬18���ύ��AC*/
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
