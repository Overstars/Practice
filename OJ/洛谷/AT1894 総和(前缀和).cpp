#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100005];
int main()
{
	long long n,k,i;
	long long temp;
	cin>>n>>k;
	long long c=n-k+1;//c组k长度
	for(i=1;i<=n;i++){
		cin>>temp;
		if(i<c&&i<k)
			a[i]=a[i-1]+temp*i;
		else if(i>n-c+1&&i>n-k+1)
			a[i]=a[i-1]+temp*(n-i+1);
		else
			a[i]=a[i-1]+temp*min(k,c);//中间
//		printf("n=%lld,sum=%lld\n",i,a[i]);
	}
	cout<<a[n]<<endl;
	return 0;
}
