#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=19260817;
ll read()//快读挂
{
    ll x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9')
	{
		if(ss=='-')
			f=-1;
		ss=getchar();
	}
    while(ss>='0'&&ss<='9')
	{
		x=x*10+ss-'0';
		x%=mod;
		ss=getchar();
	}
    return x*f;
}
ll qmod(ll a,ll b,ll mod)  //快速幂
{
    ll ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
			ans=(ans%mod)*(a%mod)%mod;
        a=((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return ans;
}
//求a在模p下的乘法逆元（p是素数）
ll inv(ll a,ll p)
{
    return qmod(a,p-2,p);
}
int main()
{
	ll a,b;
	a=read(),b=read();
	if(b==0)
		cout<<"Angry!"<<endl;
	else
		cout<<(a%mod*inv(b,mod))%mod<<endl;
	return 0;
}
