#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
char s[maxn];
ll dp[maxn],ans=0;
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	for(int i=1;i<l;i++)
	{//dp连续vv的个数
		if(s[i]=='v'&&s[i-1]=='v')
		{
			dp[i]=dp[i-1]+1;
		}
		else
			dp[i]=dp[i-1];
	}
	for(int i=1;i<l;i++)
	{
//		printf("dp[%d]=%d\n",i,dp[i]);
		if(s[i]=='o')
			ans+=dp[i]*(dp[l-1]-dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
