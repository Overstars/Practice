#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dp[100][100005];//第i位结尾,以j结尾的答案
int main()
{
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=l;i++)
        dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        int pre=0;
        for(int j=1;j<=l;j++)
            pre=(pre+dp[i-1][j])%mod;
        for(int j=1;j<=l;j++)//第i位以j结尾
        {
            int diss=0;
            for(int k=j<<1;k<=l;k+=j)//去掉被j整除的
                diss=(diss+dp[i-1][k])%mod;
            dp[i][j]=(pre-diss)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=l;i++)
        ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
    return 0;
}
