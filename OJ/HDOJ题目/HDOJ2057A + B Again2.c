//%X  使用十六进制数字0xf的无符号十六进制整数
//%I64x 用于64位16进制数据
#include<stdio.h>
int main(void)
{
	long long a,b,sum;
	while(scanf("%I64X %I64X",&a,&b)==2){
		sum=a+b;
		if(sum>=0)
			printf("%I64X\n",sum);
		else
			printf("-%I64X\n",-sum);
	}
	return 0;
}
