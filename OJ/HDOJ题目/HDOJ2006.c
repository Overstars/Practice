#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,x=1;//a为当前输入的数值,x为当前乘积 
		while(n-->0){
			scanf("%d",&a);
			if(a%2==1)
			x*=a;
		}
		printf("%d\n",x);
	}
	return 0;
}
