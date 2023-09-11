#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[20005];
bool isp[20005];
void sieve(ll n)
{
	for(ll i=0;i<=n;i++)
		isp[i]=1;
	isp[0]=isp[1]=0;
	for(ll i=2;i<=n;i++)
		if(isp[i])
			for(ll j=i<<1;j<=n;j+=i)
				isp[j]=0;//筛去i的所有倍数
}
ll prim(ll n)
{
	sieve(n);
	ll cnt=1;
	prime[0]=2;
	for(ll i=3;i<=n;i+=2)
		if(isp[i])
			prime[cnt++]=i;
//	printf("^^^\n");
	return cnt;
}
int main()
{
	ll n;
	cin>>n;
	ll c=prim(n);
//	for(int i=0;i<=c;i++)
//		printf("primr[%d]=%lld\n",i,prime[i]);
	for(int i=0;i<c;i++)
	{
		for(int j=i;j<c;j++)
		{
//			printf("??\n");
			ll now=n-prime[i]-prime[j];
			if(now>n||now<2)
				break;
			if(isp[now])
			{
				cout<<prime[i]<<' '<<prime[j]<<' '<<now<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
