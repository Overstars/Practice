#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void qs(long long left,long long right);
//bool cmp(long long a,long long b);
bool cmp(int a,int b);
int arr[1000005];
int main()
{
	long long n,m,i;
	while(cin>>n>>m){
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
//		qs(0,n-1);
		sort(arr,arr+n,cmp);
		for(i=0;i<m;i++){
			printf("%d",arr[i]);
			if(i!=m-1)
				cout<<' ';
		}
		putchar('\n');
	}
	return 0;
}
void qs(long long left,long long right)
{
	if(left>=right)
		return;
	long long st=arr[left],i=left,j=right;
	while(i<j){
		while(arr[j]<=st&&i<j)
			j--;
		arr[i]=arr[j];
		while(arr[i]>=st&&i<j)
			i++;
		arr[j]=arr[i];
	}
	arr[j]=st;
	qs(left,j-1);
	qs(j+1,right);
}
bool cmp(int a,int b)
{
    return a>b;
}
