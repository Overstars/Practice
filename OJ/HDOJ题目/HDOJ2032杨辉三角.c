#include<stdio.h>
int main(void)
{
	int n,i,j;
	int arr[35][35]={0};
	arr[0][0]=1;
	for(i=1;i<31;i++)
		for(j=0;j<=i;j++)
			if(j>0)
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			else
				arr[i][j]=1;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				printf((j!=i)?"%d ":"%d\n",arr[i][j]);
		putchar('\n');
	}
	return 0;
}
