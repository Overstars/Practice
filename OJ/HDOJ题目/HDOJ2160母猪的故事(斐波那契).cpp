#include<iostream>
#include<cstdio>
using namespace std;
int arr[25]={0,1,2};
int main()
{
	int n,t;
	for(n=3;n<20;n++)//小猪当天不生崽
		arr[n]=arr[n-1]+arr[n-2];
	cin>>t;
	while(t--){
		cin>>n;
		cout<<arr[n]<<endl;
	}
	return 0;
}
