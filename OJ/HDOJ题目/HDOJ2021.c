#include<stdio.h>
int page(long salary);
int main(void)
{
	int n;
	long teach[100];
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int i,sum=0;
		for(i=0;i<n;i++){
			scanf("%ld",&teach[i]);
		}
		for(i=0;i<n;i++){
			sum+=page(teach[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}
int page(long salary)//计算一个老师工资的张数 
{
	int i=0,count=0,arr[6]={100,50,10,5,2,1};
	long temp;
	for(temp=salary;temp>0;){
		for(i=0;temp<arr[i]&&i<6;i++)
			continue;
		temp-=arr[i];
		count++;
		if(temp<arr[i]&&i<6) i++;
//		printf("\ntemp=%d\tcount=%d\ti=%d\n",temp,count,i);
	}
	return count;
}
