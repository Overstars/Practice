#include<iostream>
#include<cstdio>
using namespace std;
int n,c[207];
long long ans,f[207][207];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),c[i+n]=c[i];
      for(int i=2;i<=n;i++){
          for(int l=1;l+i-1<2*n;l++){
              int r=l+i-1;
              for(int k=l;k<r;k++)
                f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+c[l]*c[k+1]*c[r+1]);
              printf("dp[%d][%d]=%lld\n",l,r,f[l][r]);
          }
      }
    for(int i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);
    printf("%d\n",ans);
    return 0;
}
