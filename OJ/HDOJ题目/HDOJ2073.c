#include<stdio.h>
#include<math.h>
double arr[205][205];
int main(void)
{
	int i,j;
	for(i=0;i<203;i++){//iÊú×Å
		for(j=0;j<=i;j++){
			if(i==0&&j==0)
				arr[0][0]=0;
			else if(j==0)
				arr[i][0]=arr[0][i-1]+sqrt(2*i*i-2*i+1);
			else
				arr[i-j][j]=arr[i-j+1][j-1]+sqrt(2);
		}
	}
//	for(i=0;i<203;i++){
//		for(j=0;j<=i;j++){
//			printf("(%3d,%3d):%.3lf\n",j,i-j,arr[i-j][j]);
//		}
//	}
	int n,x1,y1,x2,y2;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%.3lf\n",fabs(arr[y1][x1]-arr[y2][x2]));
	}
	return 0;
}
