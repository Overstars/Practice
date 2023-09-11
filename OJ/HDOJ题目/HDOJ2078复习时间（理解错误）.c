#include<stdio.h>
int main(void)
{
	int T,n,m,efficiency;//T组数据，n门课，最多学m门
	scanf("%d",&T);
	while(T-->0){
		int a[39],i,min,c;//min为数组中最小的 
		for(i=0;i<40;i++)
		scanf("%d",&a[i]);
		min=a[0];
		int b;
		for(b=0;b<40;b++){
			if(min>a[b])
			min=a[b];
		}
		efficiency=(100-a[1])*(100-a[1]);
		c=(a[1]-min)*(a[1]-min);
		if(efficiency<c)
		efficiency=c;
		printf("%d",efficiency);
	}
	return 0;
 } 
