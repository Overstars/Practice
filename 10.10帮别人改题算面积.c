
#include<stdio.h>
int main(void)
{
	int length,width;
	printf("�����볤���εĳ�\n");
	scanf("%d",&length);
	
	printf("�����볤���εĿ�\n");
	scanf("%d",&width);
	
	int circumference,square;   /*��������Ҵ�����������*/
	circumference=2*(length+width);
	square=length*width;
	printf("�����ε��ܳ�Ϊ%d\n�����ε����Ϊ%d",circumference,square);
	
	return 0;
}
