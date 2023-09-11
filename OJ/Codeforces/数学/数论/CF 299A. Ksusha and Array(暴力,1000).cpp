#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[(int)1e5+5];
int main()
{
	ll n,ans=1,tmp;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]%ans!=0)
		{
			ans=-1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
