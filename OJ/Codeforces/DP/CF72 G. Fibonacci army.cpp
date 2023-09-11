#include<iostream>
using namespace std;
long long dp[60]={1,1},n;
int main()
{
	for(int i=2;i<=20;i++)
		dp[i]=dp[i-1]+dp[i-2];
	cin>>n;
	cout<<dp[n]<<endl;
	return 0;
}
