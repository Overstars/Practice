//https://blog.csdn.net/Miaplacidus/article/details/92118141
#include<stdio.h>
#include<math.h>
int arr[10005];
void quicksort(int arr[],int left,int right);
int main(void)
{
	int m,n,i,sum,loc;
	double aver;
	scanf("%d",&m);
	while(m--){
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){//i�ǵ�����
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		aver=(double)sum/n;
		quicksort(arr,0,n-1);
		for(i=0;arr[i]<=aver&&i<n;i++);//�˳���ʱi�Ǵ���aver��
//		if(i>=1)
//			loc=(fabs(aver-arr[i-1])<fabs(aver-arr[i]))?i-1:i;//ѡ����ӽ�aver�ĵ���Ϊ������
//		else
//			loc=0;
		long long ans=0;
		loc=n/2;//ѡ����λ����Ϊ������
		for(i=0;i<n;i++)
			ans+=abs(arr[loc]-arr[i]);//�����㵽���ѼҾ���
		printf("%lld\n",ans);
	}
	return 0;
}
void quicksort(int arr[],int left,int right)//��С��������
{
	int std=arr[left],i=left,j=right;
	if(left>right)
		return;
	while(i<j){
		while(arr[j]>=std&&i<j)
			j--;
		arr[i]=arr[j];
		while(arr[i]<=std&&i<j)
			i++;
		arr[j]=arr[i];
	}
	arr[j]=std;
	quicksort(arr,j+1,right);
	quicksort(arr,left,j-1);
}
