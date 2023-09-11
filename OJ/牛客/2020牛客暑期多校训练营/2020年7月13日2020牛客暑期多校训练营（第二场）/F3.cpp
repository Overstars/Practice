#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
const int MAXN = 5010;
int arr[N][N],que2[N],que4[N];
int Max[N][N];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            arr[i][j]=i/__gcd(i,j)*j;
    }
    int h2=1,h4=1,t2=0,t4=0;
    for(int i=1; i<=n; i++)
    {
        h2=1,t2=0;
        for(int j=1; j<=m; j++)
        {
            while(h2<=t2&&arr[i][j]>=arr[i][que2[t2]])
                t2--;//递减队列
            que2[++t2]=j;
            while(h2<=t2&&que2[h2]<=j-k)
                h2++;
            if(j>=k)
            {
                if(h2<=t2)
                    Max[i][j-k+1]=arr[i][que2[h2]];
            }
        }
    }
    for(int j=1; j<=m; j++)
    {
        h4=1,t4=0;
        for(int i=1; i<=n; i++)
        {
            while(h4<=t4&&Max[i][j]>=Max[que4[t4]][j])
                t4--;
            que4[++t4]=i;
            while(h4<=t4&&que4[h4]<=i-k)
                h4++;
            if(i>=k)
            {
                if(h4<=t4)
                    Max[i-k+1][j]=Max[que4[h4]][j];
            }
        }
    }
    ll sum=0;
    for(int i=1;i+k-1<=n;i++)
    {
        for(int j=1;j+k-1<=m;j++)
            sum+=Max[i][j];
    }
    printf("%lld\n",sum);
    return 0;
}
