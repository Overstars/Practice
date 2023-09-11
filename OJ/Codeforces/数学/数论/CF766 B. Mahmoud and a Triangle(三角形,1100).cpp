#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=2;i<n;i++)
	{
		if(a[i-2]+a[i-1]>a[i])
		{
			cout<<"YES\n";
			exit(0);
		}
	}
	cout<<"NO\n";
	return 0;
}
