#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ull mod=123456789;
ull mul_mod(ull x,ull n,ull mod)
{
	x%=mod;
	n%=mod;
	ull ret=0;
	while(n)
	{
		if(n&1)
		{
			ret+=x;
			if(ret>=mod)
				ret-=mod;
		}
		x<<=1;
		if(x>=mod)
			x-=mod;
		n>>=1;
	}
	return ret;
}
ull qmod(ull a,ull b)
{
	ull ans=1;
	while(b)
	{
		if(b&1)
			ans=mul_mod(ans,a,mod);
		a=mul_mod(a,a,mod);
		b>>=1;
	}
	return ans;
}
signed main()
{
	ull k;
	cin>>k;
	cout<<qmod(2,k-1)<<endl;
	return 0;
}
