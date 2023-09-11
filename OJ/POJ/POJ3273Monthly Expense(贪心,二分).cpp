#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];//分成m块,使得最大一块和最小
int main()
{
	int n,m,sum=0,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	int left=maxn,right=sum,mid;
	while(left<=right){
		mid=left+right>>1;
		int cnt=0,temp=0;//按贪心统计小于且尽量接近于mid的分块个数
		for(int i=0;i<n;i++){
			if(temp>=a[i])
				temp-=a[i];
			else{
				temp=mid;
				temp-=a[i];
				cnt++;
			}
		}
		if(cnt<=m)
			right=mid-1;
		else
			left=mid+1;
	}
	cout<<left<<endl;
	return 0;
}
