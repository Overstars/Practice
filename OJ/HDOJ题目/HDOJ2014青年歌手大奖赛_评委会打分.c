#include<stdio.h>
int main(void)
{
	int n;
	float array[100];
	while(scanf("%d",&n)!=EOF){
		int i;
		float max,min,sum=0;
		for(i=0;i<n;i++)
			scanf("%f",&array[i]);
		max=array[0];
		min=array[0];
		for(i=0;i<n;i++){
			sum+=array[i];
			if(array[i]>max)
				max=array[i];
			if(array[i]<min)
				min=array[i];
		}
		printf("%.2f\n",(sum-max-min)/(n-2));
	}
	return 0;
}
