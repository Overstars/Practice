#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dp[maxn],dp2[maxn],t[maxn];
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>t[i];
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];//转为负数的代价
			if(t[i]>=0)
				dp[i]++;
		}
		int ans=0x3f3f3f3f;
		for(int i=n;i>=2;i--)
		{
			dp2[i]=dp2[i+1];
			if(t[i]<=0)//转为正数的代价
				dp2[i]++;
			ans=min(ans,dp[i-1]+dp2[i]);
//			printf("%d:%d\n",i,dp[i-1]+dp2[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
