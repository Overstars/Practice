/*ÿ����������ռ1��,ÿ�����ݵĿ�ʼ��2������n(0<=n<=100)��m(0<=m<=100),�ֱ��ʾ����A�ͼ���B��Ԫ�ظ�����Ȼ�������n+m��Ԫ�أ�ǰ��n��Ԫ�����ڼ���A�������
���ڼ���B. ÿ��Ԫ��Ϊ������int��Χ������,Ԫ��֮����һ���ո����.���n=0����m=0��ʾ����Ľ�������������
Output
���ÿ���������һ������,��ʾA-B�Ľ��,������Ϊ�ռ��ϣ��������NULL��,�����С����������,Ϊ�˼����⣬ÿ��Ԫ�غ����һ���ո�.
*/
#include<stdio.h>
#include<string.h>
void selectsort(int arr[],int n);
int main(void)
{
	int arr[2][105],output[105],i,j,count,n,m,temp;
	while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)){//��������ÿӡ��� 
		memset(arr,0,sizeof(int));
		count=0;
		for(i=0;i<n;i++){//���ظ��ض���A���� 
			scanf("%d",&temp);
			for(j=0;j<i;j++){
				if(arr[1][j]==temp){
					break;
				}
			}
			if(i==j){
				arr[1][i]=temp;
				arr[0][i]=1;
			}
		}
		for(i=0;i<m;i++){//ȥ��A������B���ϵ�Ԫ�� 
			scanf("%d",&temp);
			for(j=0;j<n;j++){
				if(temp==arr[1][j]){
					arr[0][j]=0;
					break;
				}
			}
		}
		for(i=0;i<n;i++){
			if(arr[0][i]==1){//��������ʣ�µ�Ԫ�����뵽output 
				output[count]=arr[1][i];
				count++;//count��ʾ���� 
			}
		}
		selectsort(output,count);
		for(i=0;i<count;i++)//���output 
			printf("%d ",output[i]);
		if(count==0)
			printf("NULL\n");
		else
			printf("\n");
	}
	return 0;
}
void selectsort(int arr[],int n)
{
	int i,j,loc,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1,temp=arr[j],loc=j;j<n;j++){
			if(temp>arr[j]){
				temp=arr[j];
				loc=j;
			}
		}
		if(arr[i]>arr[loc]){
			arr[loc]=arr[i];
			arr[i]=temp;
		}
	}
	return;
}
