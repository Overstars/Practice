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
	long long t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		printf("%lld\n",llpow(2,n-k));
	}
	return 0;
}
//�����Ƴ�ͨ�ʽF[i]=2F[i-1]����F[x]=2^x,x=n-k
