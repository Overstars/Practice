#include<stdio.h>
int main(void)
{
	int n,m,arr[101];
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
			break;
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(i=n;m<arr[i];i--){
			arr[i+1]=arr[i];
		}
		arr[i+1]=m;
		for(i=0;i<n+1;i++){
			printf("%d",arr[i]);
			if(i<n)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
