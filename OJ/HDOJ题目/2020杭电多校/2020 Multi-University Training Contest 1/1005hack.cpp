#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
const ll N=1e5+5;
ll f[N],ivf[N];
inline ll pow(ll a,ll b)
{
    b%=mod-1;
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1ll;
    }
    return res;
}

inline void init()
{
    f[1]=1ll;f[0]=1ll;
    for(ll i=2;i<=N-5;i++)    f[i]=f[i-1]*i%mod;//阶层表
    for(ll i=0;i<=N-5;i++)
    {
        ivf[i]=pow(f[i],mod-2);
    }
}

int main()
{
    int T;
    ll n,c,k;
    init();
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%lld%lld%lld",&n,&c,&k);
            ll ans=0;
            ll A=691504013ll;//1+sqrt(5)/2
            ll B=308495997ll;//1-sqrt(5)/2
            ll D=276601605ll;//1/sqrt(5)
            A=pow(A,c);B=pow(B,c);
        // cout<<A<<' '<<B<<endl;
            ll lvB=pow(B,mod-2);
            ll a=1,b=pow(B,k);
            for(ll i=0;i<=k;i++)
            {
                ll x=a*b%mod;
                if(x==1)
                {
                    x=(n+1)%mod;
                }
                else
                {
                    x=(pow(x,n+1)-1+mod)%mod*pow((x-1+mod)%mod,mod-2)%mod;
                }
                if((k-i)&1) x=-x;
                ans=(ans+f[k]*ivf[i]%mod*ivf[k-i]%mod*x%mod)%mod;
                a=a*A%mod;
                b=b*lvB%mod;
            }
            ans=ans*pow(D,k)%mod;
            printf("%lld\n",(ans+mod)%mod);
        }
    }
    return 0;
}
/*
2
5 1 1
2 1 2
*/

