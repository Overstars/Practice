#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int dp[maxn];
char s[maxn];
int main()
{
	int n,m,a,b;
	cin>>s+1>>m;
	n=strlen(s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=dp[i-1];
	}
	while(m--)
	{
		cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<endl;
	}
	return 0;
}
