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
	for(i=1;i<=n;i++){//�ֳ�m��,�͵����ֵ��С
		scanf("%d",&temp);
		left=max(left,temp);
		a[i]=a[i-1]+temp;
	}
	right=a[n];
	while(left<=right){
		mid=(left+right)/2;
		int cnt=1;//̰��ͳ���ܺͲ�����mid������,��m���бȽ�
		for(i=1,j=2;j<=n;j++){
			if(a[j-1]-a[i-1]<=mid&&a[j]-a[i-1]>mid){
				cnt++;//i��j-1��Ϊһ��,��ʼ��һ�μ���
				i=j;
			}
		}
		if(cnt>m){//midС��
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<left<<endl;//�����к͵����ֵ
	return 0;
}
