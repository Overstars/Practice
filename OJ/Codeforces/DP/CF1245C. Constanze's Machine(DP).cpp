#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int mod=1000000007;
char s[maxn];
int dp[maxn];
int main()
{
	cin>>s+1;
	int len=strlen(s+1);
	bool flag=1;
	if(s[1]=='w'||s[1]=='m')
		flag=0;
	dp[0]=1;//这个是为了dp[2]的时候不用特判= =
	dp[1]=1;//表示截止到i时的所有可能
	if(flag)
	{
		for(int i=2;i<=len;i++)
		{
			if(s[i]=='w'||s[i]=='m')
			{
				flag=0;
				break;
			}
			if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n'))
				dp[i]=(dp[i-2]+dp[i-1])%mod;
			else
				dp[i]=dp[i-1];//至少有之前的可能
		}
	}
//	for(int i=1;i<=len;i++)
//		cout<<"dp["<<i<<"]="<<dp[i]<<endl;
	if(flag)
		cout<<dp[len]<<endl;
	else
		cout<<0<<endl;
	return 0;
}
