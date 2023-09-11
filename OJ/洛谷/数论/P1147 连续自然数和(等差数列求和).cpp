#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll a0,ll sum)
{
	ll delta=(2*a0-1)*(2*a0-1)+8*sum;
	if(delta<0)
		return -1;//无解
	ll sq=(ll)sqrt(delta);
	if(sq*sq!=delta)
		return -1;//无整数解
	ll ret=1-2*a0+sq;
	if(ret%2==0)
		return ret>>1;
	else
		return -1;
}
int main()
{
	ll m;
	cin>>m;
	for(int i=1;i<=(m>>1);i++)
	{
		ll n=fun(i,m);
		if(n==-1)
			continue;
		cout<<i<<" "<<i+n-1<<endl;
	}
	return 0;
}
