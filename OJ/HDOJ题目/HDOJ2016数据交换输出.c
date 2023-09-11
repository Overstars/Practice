#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		int i=0,k,min,arr[100];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		min=arr[0];
		k=0;
		for(i=1;i<n;i++){
			if(arr[i]<min){
				min=arr[i];
				k=i;
			}
		}
		i=arr[k];//i重新利用 
		arr[k]=arr[0];
		arr[0]=i;
		for(i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=(n-1))
			printf(" ");//Presentation Error
		}
		printf("\n");
	}
	return 0;
}
