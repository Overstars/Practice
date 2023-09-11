#include<stdio.h>
int main(void)
{
	int arr[105],i,m,n;
	for(i=0;i<100;i++)
		arr[i]=(i+1)*2;
	while(scanf("%d %d",&n,&m)!=EOF){
		int j;
		for(j=0;j<n-m;j+=m){
			int sum=0;
			for(i=j;i<j+m;i++)
				sum+=arr[i];
			printf("%d ",sum/m);
		}
		if(j<n){
			int sum=0;
			for(i=j;i<n;i++)
				sum+=arr[i];
			printf("%d",sum/(n-j));
		}
		printf("\n");
	}
	return 0;
}
