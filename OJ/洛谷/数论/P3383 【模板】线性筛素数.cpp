#include<bits/stdc++.h>
using namespace std;
const int maxn=10000005;
bool isp[maxn];
int sieve(int n)
{
	for(int i=0;i<=n;i++)
		isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2;i<=n;i++)
		if(isp[i])
			for(int j=i<<1;j<=n;j+=i)
				isp[j]=0;//筛去i的所有倍数
}
int main()
{
	int x,n,m;
	cin>>n>>m;
	sieve(n);
	while(m--)
	{
		cin>>x;
		cout<<(isp[x]?"Yes":"No")<<endl;
	}
	return 0;
}
