#include<cstdio>
using namespace std;
int n,m,k,t,ans; int a[4001][4001],dp[4001][4001],que[4001][2];
inline int MIN(int g1,int g2){
    return g1<=g2?g1:g2;
}
inline int MAX(int g1,int g2){
    return g1>=g2?g1:g2;
}
int main(){
	freopen("P3800_1.in", "r", stdin);
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(int i=1;i<=k;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%d",&a[x][y]);
    }
    for(int i=1;i<=n;++i){
        int head=1,tail=0;
        for(int j=1;j<=MIN(m,t);++j){
            while(que[tail][0]<=dp[i-1][j]&&head<=tail)
                --tail;
            que[++tail][0]=dp[i-1][j];
            que[tail][1]=j;
        }
        for(int j=1;j<=m;++j){
            if(j+t<=m){
                while(que[tail][0]<=dp[i-1][j+t]&&head<=tail)
                    --tail;
                que[++tail][0]=dp[i-1][j+t];
                que[tail][1]=j+t;
            }
            if(que[head][1]<j-t)
                ++head;
            dp[i][j]=que[head][0]+a[i][j];
        }
    }
    for(int i=1;i<=m;++i)
        ans=MAX(ans,dp[n][i]);
    printf("%d",ans);
    return 0;
}
