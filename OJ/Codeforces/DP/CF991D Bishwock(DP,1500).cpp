#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
char s[3][maxn];
int dp[maxn][5];//0,1,2,3,4表示状态
inline bool jud(int pos,int th)//方块的右端为准
{
	if(th==1)//L
	{
		if(s[1][pos-1]=='0'&&s[2][pos-1]=='0'&&s[2][pos]=='0')
			return 1;
	}
	else if(th==2)//
	{
		if(s[1][pos-1]=='0'&&s[1][pos]=='0'&&s[2][pos-1]=='0')
			return 1;
	}
	else if(th==3)
	{
		if(s[1][pos-1]=='0'&&s[1][pos]=='0'&&s[2][pos]=='0')
			return 1;
	}
	else{
		if(s[1][pos]=='0'&&s[2][pos-1]=='0'&&s[2][pos]=='0')
			return 1;
	}
	return 0;
}
int main()
{
	int n,ans=0;
	scanf("%s%s",s[1]+1,s[2]+1);
	n=strlen(s[1]+1);
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=4;j++)//什么也没放
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
		dp[i][1]=max(dp[i-1][0],max(dp[i-2][3],dp[i-2][4]))+(jud(i,1)?1:0);
		dp[i][2]=max(dp[i-1][0],max(dp[i-2][3],dp[i-2][4]))+(jud(i,2)?1:0);
		dp[i][3]=max(max(dp[i-1][0],dp[i-1][1]),max(dp[i-2][3],dp[i-2][4]))+(jud(i,3)?1:0);
		dp[i][4]=max(max(dp[i-1][0],dp[i-1][2]),max(dp[i-2][3],dp[i-2][4]))+(jud(i,4)?1:0);
	}
	int ans=0;
	for(int i=0;i<5;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}

/*四种放置方法
 1: X0  2:XX  3:XX  4:0X
    XX    X0    0X    XX
*/
