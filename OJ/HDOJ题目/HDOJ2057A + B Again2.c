//%X  ʹ��ʮ����������0xf���޷���ʮ����������
//%I64x ����64λ16��������
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
