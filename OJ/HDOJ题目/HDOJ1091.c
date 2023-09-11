/*A+B for Input-Output Practice (III)
*19秒看题，1分34秒敲代码，47秒修改了一个PE*/
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
