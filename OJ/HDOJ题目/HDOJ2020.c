#include<stdio.h>
#include<stdlib.h>
void quicksort(int ar[],int left,int right);
int main(void)
{
	int n,arr[100];
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		quicksort(arr,0,n-1);
		for(i=0;i<n;i++){
			printf("%d",arr[i]);
			if(i<n-1)
				putchar(' ');
			else
				putchar('\n');
		}
	}
	return 0;
}
void quicksort(int ar[],int left,int right)
{
	if(left>=right) return;
	int absstd,std=ar[left],i=left,j=right;
	if(std<0)
		absstd=-std;
	else
		absstd=std;
	while(i<j){
		while(abs(ar[j])<absstd&&i<j) j--;
		ar[i]=ar[j];
		while(abs(ar[i])>absstd&&i<j) i++;
		ar[j]=ar[i];
	}
	ar[j]=std;
	quicksort(ar,left,j-1);
	quicksort(ar,j+1,right);
}
