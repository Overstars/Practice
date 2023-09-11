#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	while(~scanf("%lld%lld",&n,&k))
	{
		ll ans=k*n;
		for(ll l=1,r=1;l<=k;l=r+1)
		{
			if(k/l==0||l>n)
				break;
			r=min(k/(k/l),n);//防止多减
			ll x=r-l+1;//项数
			ans-=(k/l)*(x*l+x*(x-1)/2);
//			printf("l=%lld,r=%lld,del=%lld,x=%lld,ans=%lld\n",l,r,n/l,x,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
