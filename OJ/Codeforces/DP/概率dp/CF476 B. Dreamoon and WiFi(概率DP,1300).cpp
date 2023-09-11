#include<bits/stdc++.h>
using namespace std;
const int maxn=106,val=15;
double dp[maxn][maxn];
int main()
{
	string s,t;
	cin>>s>>t;
	int pos=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='+')
			pos++;
		else
			pos--;
	dp[0][0+val]=1;//dp[i][j]在i时刻达到j位置的概率
	for(int i=0;i<t.length();i++)
	{
		for(int j=1;j<12+val;j++)
			if(t[i]=='+')
				dp[i+1][j]=dp[i][j-1];
			else if(t[i]=='-')
				dp[i+1][j]=dp[i][j+1];
			else
				dp[i+1][j]=0.5*dp[i][j-1]+0.5*dp[i][j+1];
	}
//	for(int i=0;i<t.length();i++)
//		for(int j=0;j<12+val;j++)
//			cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//	cout<<"pos="<<pos<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(12)<<dp[t.length()][pos+val]<<endl;
	return 0;
}
