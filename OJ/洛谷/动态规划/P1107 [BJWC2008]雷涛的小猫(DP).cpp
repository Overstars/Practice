#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2005;
ll a[maxn],mp[maxn][maxn*4],rec[maxn*2],dp[maxn][maxn];
int main()
{
    int n,h,d;//n棵树,高度h
    scanf("%d%d%d",&n,&h,&d);
    for(int i=1;i<=n;i++)
    {
        ll tmp1,tmp2;
        scanf("%lld",&tmp1);
        for(int j=1;j<=tmp1;j++)
        {
            scanf("%lld",&tmp2);
            mp[i][tmp2]++;
        }
    }
    for(int i=h;i>=0;i--)//高度
    {
        for(int j=1;j<=n;j++)//树
        {
            dp[i][j]=max(dp[i+1][j],rec[i+d])+mp[j][i];
            rec[i]=max(rec[i],dp[i][j]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[0][i]);
    printf("%lld\n",ans);
    return 0;
}
