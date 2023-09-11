#include<stdio.h>
#define PI 3.1415927
int main(void)
{
	double R,V;
	while(scanf("%lf",&R)!=EOF){
		V=(double)4/3*PI*R*R*R;
		printf("%.3lf\n",V);
	}
	return 0;
}
