
#include<stdio.h>
int main(void)
{
	int length,width;
	printf("请输入长方形的长\n");
	scanf("%d",&length);
	
	printf("请输入长方形的宽\n");
	scanf("%d",&width);
	
	int circumference,square;   /*这个单词我从网上搜来的*/
	circumference=2*(length+width);
	square=length*width;
	printf("长方形的周长为%d\n长方形的面积为%d",circumference,square);
	
	return 0;
}
