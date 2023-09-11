#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int h[205],dp[205];
int pow(int x,int n)//x的n次幂
{
	int ans=1;
	while(n&1)//n是奇数
	{
		if(n&1)
			ans*=x;
		x*=x;
		n/=2;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	memset(dp,inf,sizeof(dp));
	dp[1]=0;//一开始在第一层
	for(int i=2;i<=n;i++)//到第i级台阶的最少步数
	{
		if(h[i]-h[i-1]==1)
			dp[i]=dp[i-1]+1;//下一级上来
		for(int j=i-1;j>0;j--)
		{
			dp[j]=min(dp[j],dp[i]+i-j);//从i级退下
			for(int k=j-1;k>0;k--)
			{
				int diff=j-k;//退下diff级
				int p=2<<(diff-1);
				if(h[i]-h[k]>p)
					continue;
				dp[i]=min(dp[i],dp[j]+diff+1);//从j退到k,再跳到i
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<"dp["<<i<<"]="<<dp[i]<<endl;
	if(dp[n]>=inf)
		cout<<-1<<endl;
	else
		cout<<dp[n]<<endl;
	return 0;
}
