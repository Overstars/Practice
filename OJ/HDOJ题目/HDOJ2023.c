#include<stdio.h>
int main(void)
{
	int n,m,flag=0;
	int arr[50][5];
	double averstu[50],aversub[5];
	while(scanf("%d %d",&n,&m)==2){
//		if(flag) putchar('\n');flag=1;
		int i,j,sum=0,count=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		for(i=0;i<n;i++){
			sum=0;
			for(j=0;j<m;j++)
				sum+=arr[i][j];
			averstu[i]=(double)sum/m;//存储每个学生平均成绩
		}
		for(j=0;j<m;j++){
			sum=0;
			for(i=0;i<n;i++)
				sum+=arr[i][j];
			aversub[j]=(double)sum/n;//存储每门课平均成绩
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(arr[i][j]<aversub[j])
					break;
				else if(j==(m-1))
					count++;
			}
		}
		for(i=0;i<n;i++){
			printf("%.2lf",averstu[i]);
			(i!=(n-1))?putchar(' '):putchar('\n');
		}
		for(i=0;i<m;i++){
			printf("%.2lf",aversub[i]);
			(i!=(m-1))?putchar(' '):putchar('\n');
		}
		printf("%d\n\n",count);
	}
	return 0;
}
