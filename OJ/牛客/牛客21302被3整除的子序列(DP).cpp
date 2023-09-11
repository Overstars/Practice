#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int a[55],dp[55][3];
char s[55];
int main()
{
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        a[i]=(int)(s[i]-'0')%3;
    }
    int ans=0;
    for(int i=1;i<=len;i++)
    {//以i结尾种数
        if(a[i]==0)
        {
            dp[i][0]=2*dp[i-1][0]+1;
            dp[i][1]=2*dp[i-1][1];
            dp[i][2]=2*dp[i-1][2];
        }
        else if(a[i]==1)
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][2];
            dp[i][1]=dp[i-1][1]+dp[i-1][0]+1;
            dp[i][2]=dp[i-1][2]+dp[i-1][1];
        }
        else{
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][1]+dp[i-1][2];
            dp[i][2]=dp[i-1][2]+dp[i-1][0]+1;
        }
        for(int j=0;j<3;j++)
            dp[i][j]%=mod;
//            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
//        ans+=dp[i][0];
    }
    cout<<dp[len][0]<<endl;
    return 0;
}
