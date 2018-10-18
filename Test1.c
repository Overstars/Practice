#include<stdio.h>
int main(void)
{
	printf("Let's observe how computers work!\n\n");
	
	int A=2147483647,B;
	B=A+1;
	printf("%d+1=%d\n\n",A,B);
	
	float C=9.999999E37,D;
	D=C*10;
	printf("%f*10=%f\n\n",C,D);
	
	float E=0.19E-4,F;
	F=E/10;
	printf("%f/10=%f\n\n",E,F);
	
	return 0;
	
}
