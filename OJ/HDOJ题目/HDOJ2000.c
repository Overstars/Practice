#include<stdio.h>
int main(void)
{
	char a,b,c,d;
	while(scanf("%c%c%c",&a,&b,&c)!=EOF){
		if(a>b){
			d=a;//�Ѵ�ֵ�����м��� 
			a=b;//��Сֵ����a 
			b=d;//�Ѵ�ֵ����b 
		}
		if(b>c){
			d=b;
			b=c;
			c=d;
		}
		if(a>b){
			d=a; 
			a=b;
			b=d; 
		}
		printf("%c %c %c\n",a,b,c);
		getchar();
	}
	return 0;
}
