#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55],mod=1000000007;
int main()
{
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=a[i]-i+1;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
