/*A+B for Input-Output Practice (III)
*19�뿴�⣬1��34���ô��룬47���޸���һ��PE*/
#include<stdio.h>
int main(void)
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		if(a==0&&b==0)
			break;
		printf("%d\n",a+b);
	}
	return 0;
}
