#include<stdio.h>
int main(void)
{
	double a;
	while(scanf("%lf",&a)!=EOF){
		if(a<0)
			a=-a;
		printf("%.2lf\n",a);
	}
	return 0;
}
