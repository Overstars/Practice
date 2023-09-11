#include<stdio.h>
#define pi 3.1415926
#define halfday 43200
int main(void)
{
	double h,m,s,theta1,theta2;
	int t,temp2;
	double temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf",&h,&m,&s);
		if(h>=12)
			h-=12;
		theta1=360*(h*60*60+m*60+s)/halfday;
		theta2=360*(m*60+s)/(60*60);
		if(theta1>theta2)
			temp=(theta1-theta2);
		else
			temp=(theta2-theta1);
		if(temp>180)
			temp2=(int)(360-temp);
		else
			temp2=(int)temp;
		printf("%d\n",temp2);
	}
	return 0;
}
