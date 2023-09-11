#include<stdio.h>
int main()
{
	double temp,max;
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		max=-99999;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf",&temp);
			if(temp>max)
				max=temp;
		}
		printf("%.2lf\n",max);
	}
	return 0;
}
