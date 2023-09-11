#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fra[505]={0,0,1,3},f[505];
int main()
{
    int t;
    for(int i=2;i<=500;i++)
    {
        fra[i]=fra[i-1]+i-1;
        printf("fra[%d]=%lld\n",i,fra[i]);
    }
    for(int i=1;i<=500;i++)
    {
        f[i]=f[i-1]+2*i-1+fra[i];
        printf("f[%d]=%lld\n",i,f[i]);
    }
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<f[x]<<endl;
    }
    return 0;
}
/*
 *没有注意顶点向下三角形推出来的错误公式
 *f[n]=f[n-1]+2n-1+(1+2+3+...+n-1)
 */

