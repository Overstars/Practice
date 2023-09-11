#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int pa[maxn],pb[maxn],dp[maxn];
int main()
{
	string s;
	cin>>s;
	int len=s.length(),ans=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='a')
		{
			pa[i+1]=pa[i]+1;
			pb[i+1]=pb[i];
		}
		else{
			pa[i+1]=pa[i];
			pb[i+1]=pb[i]+1;
		}
	for(int i=0;i<=len;i++)//第一个分割点
	{
		for(int j=i;j<=len;j++)//第二个
			ans=max(ans,pa[len]-pa[j]+pb[j]-pb[i-1]+pa[i]);
	}
	cout<<ans<<endl;
	return 0;
}
