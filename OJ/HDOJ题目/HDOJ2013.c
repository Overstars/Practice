#include<stdio.h>
int main(void)
{
	int n;//ʣһ����������Ϊn
	while(scanf("%d",&n)!=EOF){
		long a=1;//aΪ�Ӻ���ǰ�Ƶ����������
		for(a;n-->1;a=(a+1)*2);	
		printf("%d\n",a);
	} 
	return 0;
 } 
