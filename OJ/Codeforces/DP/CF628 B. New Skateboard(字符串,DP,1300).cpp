#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
typedef long long ll;
char s[maxn];
ll dp[maxn];
int main()
{
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
	{//以i为结尾的被四整除的字串有多少个
		int t=s[i]-'0';
		if(t%4==0)
			dp[i]=1;
		if(i>1)
			t+=(s[i-1]-'0')*10;
		if(t%4==0)//只需末尾两位被四整除
			dp[i]+=i-1;
	}
	ll ans=0;
	for(int i=1;i<=l;i++)
		ans+=dp[i];
	cout<<ans<<endl;
	return 0;
}
