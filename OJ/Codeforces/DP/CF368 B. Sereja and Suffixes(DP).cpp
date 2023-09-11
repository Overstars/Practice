#include<bits/stdc++.h>
using namespace std;
int a[100005],l[100005],dp[100005];
bool vis[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[n]=1;
	vis[a[n]]=1;
	for(int i=n-1;i>0;i--)
		if(!vis[a[i]])
		{
			dp[i]=dp[i+1]+1;
			vis[a[i]]=1;
		}
		else
			dp[i]=dp[i+1];
	while(m--)
	{
		int q;
		cin>>q;//a[q:n]有多少个不同的数
		cout<<dp[q]<<endl;
	}
	return 0;
}
