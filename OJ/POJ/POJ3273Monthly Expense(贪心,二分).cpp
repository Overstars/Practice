#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];//�ֳ�m��,ʹ�����һ�����С
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
		int cnt=0,temp=0;//��̰��ͳ��С���Ҿ����ӽ���mid�ķֿ����
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
