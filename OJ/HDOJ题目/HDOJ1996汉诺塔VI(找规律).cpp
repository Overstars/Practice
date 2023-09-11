#include<iostream>
#include<cstdio>
using namespace std;
long long llpow(long long a,long long b)
{
	long long ans=1;
	while(b>0){
		if(b%2==1)
			ans*=a;
		a*=a;
		b/=2;
	}
	return ans;
}
int main()
{
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		printf("%lld\n",llpow(3,n));
	}
	return 0;
}
