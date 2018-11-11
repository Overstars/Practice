#include<stdio.h>
#include<float.h>
int main(void)
{
	double A=1.0/3.0;
	float B=1.0/3.0;
	
	printf("%.3f %.3f %d %d\n",A,B,FLT_DIG,DBL_DIG);
	printf("%.6f %.6f %d %d\n",A,B,FLT_DIG,DBL_DIG);
	printf("%.12f %.12f %d %d\n",A,B,FLT_DIG,DBL_DIG);
	printf("%.16f %.16f %d %d\n",A,B,FLT_DIG,DBL_DIG);
	printf("%.20f %.20f %d %d\n",A,B,FLT_DIG,DBL_DIG);
	printf("%d",FLT_MANT_DIG);
	
	return 0;
 } 
