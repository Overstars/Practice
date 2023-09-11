#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;
ll maze[5005][5005];

ll gcd(ll a,ll b) //求两个数的最大公约数
{
    return b ? gcd(b,a%b):a;
}

ll lcm(ll m,ll g)  //求两个数的最小公倍数
{
    return m/gcd(m,g)*g;
}

ll maze_max(int y,int x,int k)
{
    ll maxx=-1ll;
    for(int i=x;i<x+k;i++) maxx=max(maxx,maze[y+k-1][i]);
    for(int j=y;j<y+k;j++) maxx=max(maxx,maze[j][x+k-1]);
    return maxx;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) maze[i][j]=lcm(i,j);
    }
    ll sum=0;
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=1;j<=m-k+1;j++)
        sum+=maze_max(i,j,k);
    }
    cout<<sum<<endl;
    //system("pause");
    return 0;
}
