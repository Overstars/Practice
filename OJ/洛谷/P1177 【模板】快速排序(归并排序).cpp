#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],tem[maxn];
void mergesort(int arr[],int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	int p1=l,p2=mid+1;
	for(int i=l;i<=r;i++)
	{
		if((arr[p1]<arr[p2]&&p1<=mid)||p2>r)//治:合并左右区间,保持有序
			tem[i]=arr[p1++];
		else
			tem[i]=arr[p2++];
	}
	for(int i=l;i<=r;i++)//治:将合并后的区间从临时数组更新到原数组
		arr[i]=tem[i];
}
int main()
{
	int n;
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	mergesort(a,1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
