#include<stdio.h>
#include<math.h>
int main(void)
{
	float x1,y1,x2,y2,length;
	while(scanf("%f %f %f %f",&x1,&y1,&x2,&y2)==4){
	
	length=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	printf("%.2f\n",length);
	}
	return 0;
}
