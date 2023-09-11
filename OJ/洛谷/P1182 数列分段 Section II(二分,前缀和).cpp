#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int a[100005];
int main()
{
	int n,m,i,j,temp,left=0,right,mid;
	cin>>n>>m;
	for(i=1;i<=n;i++){//分成m段,和的最大值最小
		scanf("%d",&temp);
		left=max(left,temp);
		a[i]=a[i-1]+temp;
	}
	right=a[n];
	while(left<=right){
		mid=(left+right)/2;
		int cnt=1;//贪心统计总和不超过mid的数量,与m进行比较
		for(i=1,j=2;j<=n;j++){
			if(a[j-1]-a[i-1]<=mid&&a[j]-a[i-1]>mid){
				cnt++;//i到j-1分为一段,开始下一段计数
				i=j;
			}
		}
		if(cnt>m){//mid小了
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<left<<endl;//各段中和的最大值
	return 0;
}
