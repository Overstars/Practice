#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=1e9+7;
char s[maxn];
int dp[maxn][2];//0连续,1由b隔开
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int ans=0,pre=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='a')//在ans基础上增加pre+1个
			ans=(ans+pre+1)%mod;
		else if(s[i]=='b')
			pre=ans;
	}
	cout<<ans<<endl;
	return 0;
}
