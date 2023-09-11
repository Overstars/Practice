#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=1000005;
ll a[maxn],fac[maxn]={1,1,2,6},c[maxn];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int k,ll num,int n)
{
	while(k<=n)
	{
		c[k]+=num;
		k+=lowbit(k);
	}
}
ll query(int k)
{
	ll sum=0;
	while(k)
	{
		sum+=c[k];
		k-=lowbit(k);
	}
	return sum;
}
ll contor(ll arr[],int n)
{
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll cnt=query(a[i]-1);//��ѯa[i]ǰ���ж��ٸ�1,����a[i]С��û���ù������ָ���
		add(a[i],-1,n);//����һ�������޸ĸõ�Ϊ0
		ans+=(cnt*fac[n-i])%mod;//�����iλ*С��*a[i]�ж��ٸ����
		ans%=mod;
	}
	return (ans+1)%mod;
}
void init(int n)
{
	for(int i=4;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
	for(int i=1;i<=n;i++)
		add(i,1,n);//���е㶼�޸�Ϊ1
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("P5367.in","r",stdin);
	int n;
	cin>>n;
//	for(int i=4;i<=n;i++)
//		fac[i]=(fac[i-1]*i)%mod;
	init(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
//	for(int i=1;i<=n;i++)
//		add(i,1,n);//���е㶼�޸�Ϊ1
	cout<<contor(a,n)<<endl;
	return 0;
}
