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
//#include <unordered_map>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define debug(x) cout<<x<<endl
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int MAXN=1e5+50;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
//::iterator it;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
ll n;
ll a[2*MAXN],sum[2*MAXN],c[2*MAXN];
int main()
{
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    for(ll i=1;i<=n;i++)c[i]=(c[i-1]+sum[i])%mod;
    //cout<<c[n]<<endl;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=(ans+1ll*i*a[i]%mod*((c[n]-c[i-1]-1ll*(n-i+1)*sum[i-1]%mod+mod)%mod)%mod)%mod;
    }
    cout<<(ans+mod)%mod<<endl;
    return 0;
}
/*

*/



