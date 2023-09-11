#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define debug(x) cout<<x<<endl
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int MAXN=1e5+50;
const int inf=0x3f3f3f3f;
const int M=5000*4;
const int mod=1e9+7;
int n;
vector<int>p[MAXN];
ll ans;
ll dp[MAXN];
ll d[MAXN];
ll x[MAXN];
struct sa{
    int u;
    int v;
}mp[MAXN];
void dfs(int x,int fa){
    dp[x]=1;
    int len=p[x].size()-1;
    for(int i=0;i<=len;i++){
        int y=p[x][i];
        if(y==fa)continue;
        dfs(y,x);
        dp[x]+=dp[y];
    }
}
int main()
{
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        mp[i].u=u,mp[i].v=v;
        d[u]++,d[v]++;//度数
        p[u].pb(v);
        p[v].pb(u);
    }
    ll sum=0;
    for(int i=1;i<=n-1;i++)//sum为所有点的度数和,x[i]为边i的度数和
        x[i]=d[mp[i].u]+d[mp[i].v],sum+=x[i];
    dfs(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i];
    sort(x+1,x+n-1+1);
    ll sb=0;
    for(int i=1;i<=n-1;i++){
        sb+=(n-i)*(sum/ans*x[i]);
    }
    cout<<sb<<endl;
    return 0;
}
/*

*/
