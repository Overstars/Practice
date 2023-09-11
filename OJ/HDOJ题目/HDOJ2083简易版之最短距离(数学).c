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
		for(i=0;i<n;i++){//i是点的序号
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		aver=(double)sum/n;
		quicksort(arr,0,n-1);
		for(i=0;arr[i]<=aver&&i<n;i++);//退出来时i是大于aver的
//		if(i>=1)
//			loc=(fabs(aver-arr[i-1])<fabs(aver-arr[i]))?i-1:i;//选择最接近aver的点作为出发点
//		else
//			loc=0;
		long long ans=0;
		loc=n/2;//选择中位数作为出发点
		for(i=0;i<n;i++)
			ans+=abs(arr[loc]-arr[i]);//出发点到朋友家距离
		printf("%lld\n",ans);
	}
	return 0;
}
void quicksort(int arr[],int left,int right)//从小到大排序
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
