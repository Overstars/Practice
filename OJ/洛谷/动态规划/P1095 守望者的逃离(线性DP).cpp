#include<bits/stdc++.h>
using namespace std;
const int maxn=300005,inf=0x3f3f3f3f;
int dp[maxn];
int main()
{
	int m,s,t;//魔法值,距离,剩余时间,v=17m/s
	cin>>m>>s>>t;//瞬移一次10点，移动60m，1s恢复4点
//	memset(dp,inf,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=t;i++)
	{//只依靠瞬移
		if(m>=10)
			dp[i]=dp[i-1]+60,m-=10;
		else
			dp[i]=dp[i-1],m+=4;
	}
	for(int i=1;i<=t;i++)//这不是标准贪心吗...
	{
		dp[i]=max(dp[i],dp[i-1]+17);
		if(dp[i]>=s)
			return cout<<"Yes\n"<<i,0;
	}
	cout<<"No"<<'\n'<<dp[t]<<endl;
	return 0;
}
