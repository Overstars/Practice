#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,x=1;//aΪ��ǰ�������ֵ,xΪ��ǰ�˻� 
		while(n-->0){
			scanf("%d",&a);
			if(a%2==1)
			x*=a;
		}
		printf("%d\n",x);
	}
	return 0;
}
