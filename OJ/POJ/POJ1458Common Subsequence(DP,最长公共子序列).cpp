#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
char a[1005],b[1005];
int dp[1005][1005];//a串0~i与b串0~j序列相同字母数
int main()
{
	while(cin>>a>>b)
	{
		memset(dp,0,sizeof(dp));
		int al=strlen(a),bl=strlen(b),i,j;
		for(i=0;i<al;i++)
			for(j=0;j<bl;j++)
			{
				if(a[i]==b[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		cout<<dp[al][bl]<<endl;
	}
	return 0;
}

