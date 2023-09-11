#include<bits/stdc++.h>
using namespace std;
int a[505],dp[505];
int main()
{
	int n,k,tot=0;//n天和两天内散步至少k次
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		if(a[i-1]+dp[i-1]+a[i]<k)
		{
			dp[i]=k-a[i]-a[i-1]-dp[i-1];
			tot+=dp[i];
		}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]+dp[i]<<' ';
	return 0;
}
/*
给你n个有序整数，和一个整数k
要求使这个整数序列变得相邻两个数之和不小于k
请输出最小增加数值之和与操作后的序列
*/
