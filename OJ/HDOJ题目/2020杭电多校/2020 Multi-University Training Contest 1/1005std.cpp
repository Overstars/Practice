#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD=1e9+9;
const int MAXK=1e5;
int pow_mod(int x,int i){
    int y=1;
    while(i){
        if(i&1)y=(ll)y*x%MOD;
        x=(ll)x*x%MOD;
        i>>=1;
    }
    return y;
}

ll N,C;
int K,f[MAXK+5],ivf[MAXK+5];

inline void init()
{
    f[1]=1ll;f[0]=1ll;
    for(ll i=2;i<=MAXK;i++)    f[i]=f[i-1]*i%MOD;//阶层表
    for(ll i=0;i<=MAXK;i++)
    {
        ivf[i]=pow_mod(f[i],MOD-2);
    }
}

int main(){
    ios::sync_with_stdio(0);

    init();
    int T;cin>>T;while(T--){
        cin>>N>>C>>K;
        int A=691504013,B=308495997;
        A=pow_mod(A,C%(MOD-1));
        B=pow_mod(B,C%(MOD-1));
//        cout<<A<<' '<<B<<endl;
        int a=1,b=pow_mod(B,K);
        int ib=pow_mod(B,MOD-2);
        int ans=0;
        for(int j=0;j<=K;++j){
            int x=(ll)a*b%MOD;

            if(x==1)
                x=(N+1)%MOD;
            else
                x=(ll)(pow_mod(x,(N+1)%(MOD-1))-1+MOD)%MOD * pow_mod((x-1+MOD)%MOD,MOD-2) % MOD;

            if((K-j)&1)
                x=(x==0?x:MOD-x);
            ans=((ll)ans+(ll)f[K]*ivf[j]%MOD*ivf[K-j]%MOD*x%MOD)%MOD;
    //        cout<<x<<endl;
            a=(ll)a*A%MOD;
            b=(ll)b*ib%MOD;
        }


        int mul=276601605;
        mul=pow_mod(mul,K);
        ans=(ll)ans*mul%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
