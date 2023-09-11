#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,inf=0x3f3f3f3f;
char s[maxn];
int dp[4][maxn],rec[maxn];
void dfs(int x,int flag)//第x位为flag
{
	if(x<1)
		return;
	if(flag==1)//这一位为R,x-1为G/B
	{
		if(dp[2][x-1]<dp[3][x-1])
			dfs(x-1,2);
		else
			dfs(x-1,3);
	}
	else if(flag==2)
	{
		if(dp[1][x-1]<dp[3][x-1])
			dfs(x-1,1);
		else
			dfs(x-1,3);
	}
	else{
		if(dp[1][x-1]<dp[2][x-1])
			dfs(x-1,1);
		else
			dfs(x-1,2);
	}
	if(flag==1)
		cout<<"R";
	else if(flag==2)
		cout<<"G";
	else
		cout<<"B";
}
int main()//RGB:123
{
	int n;
	cin>>n>>s+1;
	for(int i=1;i<=n;i++)
	{//维持至i所需代价
		if(s[i]=='R')
		{//计算将i改为R/G/B最小代价
			dp[1][i]=min(dp[2][i-1],dp[3][i-1]);//R
			dp[2][i]=min(dp[1][i-1],dp[3][i-1])+1;//G
			dp[3][i]=min(dp[1][i-1],dp[2][i-1])+1;//B
		}
		else if(s[i]=='G')
		{
			dp[1][i]=min(dp[2][i-1],dp[3][i-1])+1;//R
			dp[2][i]=min(dp[1][i-1],dp[3][i-1]);//G
			dp[3][i]=min(dp[1][i-1],dp[2][i-1])+1;//B
		}
		else//B
		{
			dp[1][i]=min(dp[2][i-1],dp[3][i-1])+1;//R
			dp[2][i]=min(dp[1][i-1],dp[3][i-1])+1;//G
			dp[3][i]=min(dp[1][i-1],dp[2][i-1]);//B
		}
	}
	int ans=inf,pos;
	for(int i=1;i<=3;i++)
		if(dp[i][n]<ans)
		{
			pos=i;
			ans=dp[i][n];
		}
	cout<<ans<<endl;
	dfs(n,pos);
	return 0;
}
